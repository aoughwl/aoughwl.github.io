// Storefront components.
//
// The site is static. Everything that needs a secret -- prices, checkout,
// licence lookups, downloads -- is one fetch away at /api/v1, served by the
// aowl-store Worker on this same origin. Nothing here is product-specific:
// a new thing to sell is a row in the Worker's `products` table plus a page
// that drops <BuyButton product="its-id" /> on it.

import { h, ref, onMounted, computed } from 'vue'

// Same-origin in production. A preview build (localhost, *.github.io) has no
// Worker in front of it, so it talks to the real API cross-origin instead.
const API = (() => {
  if (typeof window === 'undefined') return '/api/v1'
  return /(^|\.)aoughwl\.com$/.test(location.hostname)
    ? '/api/v1'
    : 'https://aoughwl.com/api/v1'
})()

async function api(path, { method = 'POST', body } = {}) {
  const res = await fetch(`${API}${path}`, {
    method,
    headers: { 'Content-Type': 'application/json' },
    body: body ? JSON.stringify(body) : undefined,
  })
  const json = await res.json().catch(() => ({}))
  return { status: res.status, ...json }
}

const money = (cents, currency = 'usd') =>
  new Intl.NumberFormat('en-US', { style: 'currency', currency: currency.toUpperCase(), maximumFractionDigits: cents % 100 ? 2 : 0 })
    .format(cents / 100)

// What a buy button says while the shop is shut. The Worker sends its own copy
// in `payments_message` / `cta`; this is what shows before it answers, and if
// it never does.
const COMING_SOON = 'Coming very soon'

const SHORT_INTERVAL = { month: 'mo', year: 'yr', week: 'wk', day: 'day' }

/** `$19.99/mo`, or just `$39.99` for something bought once. */
const priceOf = (plan) =>
  money(plan.price_cents, plan.currency) +
  (plan.interval ? '/' + (SHORT_INTERVAL[plan.interval] || plan.interval) : '')

const when = (unix) =>
  unix ? new Date(unix * 1000).toLocaleDateString(undefined, { year: 'numeric', month: 'short', day: 'numeric' }) : '—'

// Errors from the API are machine-readable slugs. This is the one place they
// become sentences, so the Worker never has to carry copy.
const HUMAN = {
  invalid_key: 'That key was not recognised. Check for a typo, or paste it straight from the email.',
  revoked: 'This key has been revoked. If you think that is wrong, get in touch on Discord.',
  refunded: 'This purchase was refunded, so the key is no longer active.',
  expired: 'This subscription has lapsed. Restart it and the same key starts working again — you do not need a new one.',
  not_a_subscription: 'There is no Stripe subscription behind this key, so there is nothing to manage.',
  no_seats_left: 'Every seat on this key is in use. Release a machine below, then activate again.',
  wrong_product: 'That key is for a different product.',
  rate_limited: 'Too many attempts from here. Wait a few minutes and try again.',
  no_release: 'There is no published build to download yet.',
  expired_link: 'That download link expired. Ask for a new one.',
  already_claimed: 'This key has already been shown once. It is in your email.',
  internal_error: 'Something broke on our side. Nothing was charged twice — check your email, then Discord.',
}
const humanise = (slug, detail) => detail || HUMAN[slug] || slug || 'Something went wrong.'

// ---------------------------------------------------------------------------
// <BuyButton product="aowlspt" price="3900" /> -- price is a fallback shown
// before the catalogue answers, so the button never renders blank or lies by
// omission while it loads.
// ---------------------------------------------------------------------------
const BuyButton = {
  props: {
    product: { type: String, required: true },
    // Optional: name one plan when a product has several. Omitted, the cheapest
    // active plan wins, which is also what the API does.
    plan: { type: String, default: null },
    price: { type: [String, Number], default: null },
    interval: { type: String, default: '' },
    label: { type: String, default: 'Buy' },
    // Optional second button beside the first: somewhere to try the thing
    // before paying for it. Anything with a free demo can use it.
    demo: { type: String, default: '' },
    demoLabel: { type: String, default: 'Try it now' },
  },
  setup(props) {
    const busy = ref(false)
    const error = ref('')
    const live = ref(null)
    // 'loading' until the catalogue answers, then one of:
    //   'ready'        -- on sale, the button opens Stripe
    //   'closed'       -- listed and priced, but payments are not open yet
    //   'unavailable'  -- not in the catalogue at all
    // Only 'ready' is clickable, and it is the state we refuse to guess: an
    // unreachable API, a catalogue that omits payments_enabled, anything short
    // of an explicit yes leaves the button saying "coming very soon". A button
    // that opens a checkout the Worker answers with 503 is worse than one that
    // is honest about not being open yet.
    const state = ref('loading')
    const closedMessage = ref(COMING_SOON)

    onMounted(async () => {
      let open = false
      try {
        const r = await api('/catalog', { method: 'GET' })
        const product = (r.products || []).find((p) => p.id === props.product)
        const plans = product?.plans || []
        live.value = props.plan ? plans.find((p) => p.id === props.plan) : plans[0]
        // The global switch and the per-plan flag must both say yes. The Worker
        // stamps both, so requiring both means a page cannot miss the switch by
        // reading only one of them.
        open = r.payments_enabled === true && live.value?.purchasable !== false
        closedMessage.value = live.value?.cta || r.payments_message || COMING_SOON
      } catch {
        // Offline, blocked, a 500 -- we do not know that the shop is open, so
        // it is shut. The front-matter price still shows.
        open = false
      }
      state.value = open ? 'ready' : live.value ? 'closed' : 'unavailable'
    })

    const shown = computed(() => {
      if (live.value) return priceOf(live.value)
      if (props.price == null) return ''
      // Front-matter fallback, so the page is not blank while the catalogue
      // loads and still reads sensibly if it never does.
      return priceOf({ price_cents: Number(props.price), interval: props.interval })
    })

    const label = computed(() => {
      if (busy.value) return 'Opening checkout…'
      // 'loading' answers the same way as 'closed': until the catalogue says
      // the shop is open, the honest label is the closed one, so the button
      // never flashes "Subscribe" and then takes it away.
      if (state.value === 'closed' || state.value === 'loading') return closedMessage.value
      if (state.value === 'unavailable') return 'Not on sale yet'
      return props.label
    })

    const buy = async () => {
      if (busy.value || state.value !== 'ready') return
      busy.value = true
      error.value = ''
      try {
        const r = await api('/checkout', {
          body: { plan: live.value?.id ?? props.plan, product: props.product },
        })
        if (r.url) location.href = r.url
        else { error.value = humanise(r.error, r.detail); busy.value = false }
      } catch {
        error.value = 'Could not reach checkout. Are you offline?'
        busy.value = false
      }
    }

    return () =>
      h('div', { class: 'aowl-buy' }, [
        h('div', { class: 'aowl-buy-row' }, [
          h('button', {
            class: 'aowl-buy-btn' + (state.value === 'ready' ? '' : ' aowl-soon'),
            disabled: busy.value || state.value !== 'ready',
            // `disabled` already stops the click; aria-disabled says the same
            // thing to a screen reader meeting the label out of context.
            'aria-disabled': state.value !== 'ready' ? 'true' : null,
            onClick: buy,
          }, [
            h('span', { class: 'aowl-buy-label' }, label.value),
            shown.value ? h('span', { class: 'aowl-buy-price' }, shown.value) : null,
          ]),
          // A real navigation, not a router link: the playground is a separate
          // app under /playground, and client-side routing lands on the 404.
          props.demo
            ? h('a', { class: 'aowl-try', href: props.demo, target: '_self' }, props.demoLabel)
            : null,
        ]),
        h('p', { class: 'aowl-buy-note' }, state.value === 'closed' || state.value === 'loading'
          ? [
              'Not open for sale yet — the price above is what it will cost. ',
              h('a', { href: 'https://discord.gg/nxa3W7w4rJ', target: '_blank', rel: 'noopener' },
                'Ask on Discord'),
              ' to hear when it opens. ',
              h('a', { href: '/store/license' }, 'Already bought it?'),
            ]
          : state.value === 'unavailable'
          ? [
              'Not available to buy yet. ',
              h('a', { href: 'https://discord.gg/nxa3W7w4rJ', target: '_blank', rel: 'noopener' },
                'Ask on Discord'),
              ' for access in the meantime.',
            ]
          : [
              live.value?.interval
                ? 'Card payment through Stripe, cancel any time. '
                : 'Card payment through Stripe. ',
              h('a', { href: '/store/license' }, 'Already bought it?'),
            ]),
        error.value ? h('p', { class: 'aowl-err' }, error.value) : null,
      ])
  },
}

// ---------------------------------------------------------------------------
// <StoreGrid /> -- every active product, straight from the catalogue.
// ---------------------------------------------------------------------------
const StoreGrid = {
  setup() {
    const items = ref(null)
    const error = ref('')
    onMounted(async () => {
      try {
        const r = await api('/catalog', { method: 'GET' })
        items.value = r.products || []
      } catch {
        error.value = 'Could not load the catalogue.'
      }
    })
    return () => {
      if (error.value) return h('p', { class: 'aowl-err' }, error.value)
      if (!items.value) return h('p', { class: 'aowl-muted' }, 'Loading…')
      if (!items.value.length) return h('p', { class: 'aowl-muted' }, 'Nothing for sale yet.')
      return h('div', { class: 'aowl-grid' }, items.value.map((p) => {
        // The cheapest plan is the headline price; a product with none is
        // listed but plainly marked as not yet purchasable.
        const cheapest = (p.plans || [])[0]
        return h('a', { class: 'aowl-card', href: `/store/${p.id}` }, [
          h('h3', null, p.name),
          h('p', { class: 'aowl-card-tag' }, p.tagline),
          h('div', { class: 'aowl-card-foot' }, [
            h('span', { class: 'aowl-card-price' }, cheapest ? priceOf(cheapest) : 'Soon'),
            p.latest_version ? h('span', { class: 'aowl-card-ver' }, 'v' + p.latest_version) : null,
          ]),
        ])
      }))
    }
  },
}

// ---------------------------------------------------------------------------
// <LicensePanel /> -- paste a key, see what it entitles you to, download it,
// and free a machine you no longer use.
// ---------------------------------------------------------------------------
const LicensePanel = {
  setup() {
    const key = ref('')
    const info = ref(null)
    const error = ref('')
    const busy = ref(false)
    const dl = ref('')

    // Convenience only: a key in localStorage saves retyping it on every visit.
    // It is not an auth token -- every call re-checks it server-side.
    onMounted(() => {
      const saved = localStorage.getItem('aowl-key')
      if (saved) { key.value = saved; look() }
    })

    async function look() {
      if (!key.value.trim() || busy.value) return
      busy.value = true; error.value = ''; dl.value = ''
      try {
        const r = await api('/license', { body: { key: key.value.trim() } })
        if (r.ok) { info.value = r; localStorage.setItem('aowl-key', key.value.trim()) }
        else { info.value = null; error.value = humanise(r.error, r.detail) }
      } catch {
        error.value = 'Could not reach the licence server.'
      }
      busy.value = false
    }

    async function download() {
      busy.value = true; error.value = ''
      const r = await api('/download', { body: { key: key.value.trim() } })
      busy.value = false
      if (r.ok) { dl.value = r.url; location.href = r.url }
      else error.value = humanise(r.error, r.detail)
    }

    async function release(id) {
      busy.value = true
      await api('/deactivate', { body: { key: key.value.trim(), machine: id } })
      busy.value = false
      look()
    }

    // Card changes, invoices and cancellation all live on Stripe's own page.
    async function manage() {
      busy.value = true; error.value = ''
      const r = await api('/portal', { body: { key: key.value.trim() } })
      busy.value = false
      if (r.ok) location.href = r.url
      else error.value = humanise(r.error, r.detail)
    }

    function forget() {
      localStorage.removeItem('aowl-key')
      key.value = ''; info.value = null; error.value = ''; dl.value = ''
    }

    return () =>
      h('div', { class: 'aowl-lic' }, [
        h('div', { class: 'aowl-lic-form' }, [
          h('input', {
            class: 'aowl-input',
            value: key.value,
            spellcheck: 'false',
            autocapitalize: 'characters',
            placeholder: 'AOWL-SPT-XXXX-XXXX-XXXX-XXXX',
            onInput: (e) => { key.value = e.target.value },
            onKeydown: (e) => { if (e.key === 'Enter') look() },
          }),
          h('button', { class: 'aowl-buy-btn aowl-sm', disabled: busy.value, onClick: look }, 'Look up'),
        ]),
        error.value ? h('p', { class: 'aowl-err' }, error.value) : null,
        info.value ? licenceBody(info.value) : null,
      ])

    function licenceBody(i) {
      const ok = i.status === 'active'
      return h('div', { class: 'aowl-lic-body' }, [
        h('div', { class: 'aowl-lic-head' }, [
          h('h3', null, i.product_name || i.product),
          h('span', { class: 'aowl-pill ' + (ok ? 'ok' : 'bad') }, i.status),
        ]),
        h('table', { class: 'aowl-kv' }, [
          h('tbody', null, [
            row('Key', i.key_prefix + '-••••-••••-••••'),
            row('Seats', `${i.seats_used} of ${i.seats} in use`),
            // For a live subscription this date is the next renewal; for a
            // lapsed one it is when it ran out. Label it for what it is rather
            // than calling both "expires".
            row(ok ? (i.kind === 'subscription' ? 'Renews' : 'Expires') : 'Ended',
                i.expires_at ? when(i.expires_at) : 'never'),
            row('Latest build', i.latest_version ? 'v' + i.latest_version : 'not published yet'),
          ]),
        ]),
        h('div', { class: 'aowl-lic-actions' }, [
          ok
            ? h('button', { class: 'aowl-buy-btn', disabled: busy.value, onClick: download },
                'Download the latest build')
            : null,
          i.manageable
            ? h('button', { class: 'aowl-ghost', disabled: busy.value, onClick: manage },
                ok ? 'Manage subscription' : 'Restart subscription')
            : null,
          h('button', { class: 'aowl-ghost', onClick: forget }, 'Forget this key on this browser'),
        ]),
        i.machines.length
          ? h('div', { class: 'aowl-machines' }, [
              h('h4', null, 'Machines'),
              h('table', { class: 'aowl-kv' }, [
                h('tbody', null, i.machines.map((m) =>
                  h('tr', null, [
                    h('td', null, m.name || m.id),
                    h('td', null, m.status === 'active' ? 'active, last seen ' + when(m.last_seen) : 'released'),
                    h('td', null, m.status === 'active'
                      ? h('button', { class: 'aowl-ghost aowl-xs', onClick: () => release(m.id) }, 'Release')
                      : null),
                  ]))),
              ]),
              h('p', { class: 'aowl-muted' },
                'Releasing a machine frees its seat immediately. The build on that machine stops working when its ' +
                'current token expires.'),
            ])
          : null,
      ])
    }

    function row(k, v) {
      return h('tr', null, [h('td', null, k), h('td', { colspan: 2 }, v)])
    }
  },
}

// ---------------------------------------------------------------------------
// <ThanksPanel /> -- the page Stripe returns to. The key is minted by the
// webhook, not by this page, so it polls until the webhook has landed rather
// than pretending a redirect is a payment.
// ---------------------------------------------------------------------------
const ThanksPanel = {
  setup() {
    const state = ref('waiting')   // waiting | ready | reactivated | slow | error
    const licenceKey = ref('')
    const prefix = ref('')
    const product = ref('')
    const copied = ref(false)

    onMounted(async () => {
      const order = new URLSearchParams(location.search).get('order')
      if (!order) { state.value = 'error'; return }
      for (let i = 0; i < 40; i++) {
        try {
          const r = await api(`/order?order=${encodeURIComponent(order)}`, { method: 'GET' })
          product.value = r.product_name || r.product || ''
          prefix.value = r.key_prefix || ''
          if (r.ready) {
            // A resubscription revived the key they already had, so there is
            // nothing new to reveal -- saying "here is your key" would be a lie.
            if (r.reactivated) { state.value = 'reactivated'; return }
            const c = await api(`/claim?order=${encodeURIComponent(order)}`, { method: 'GET' })
            licenceKey.value = c.key || ''
            state.value = c.key ? 'ready' : 'slow'
            return
          }
        } catch { /* keep waiting */ }
        await new Promise((r) => setTimeout(r, 1500))
      }
      state.value = 'slow'
    })

    const copy = () => {
      navigator.clipboard?.writeText(licenceKey.value)
      copied.value = true
      setTimeout(() => { copied.value = false }, 1600)
    }

    return () => {
      if (state.value === 'error') {
        return h('p', { class: 'aowl-err' }, 'No order in this link. If you were charged, message us on Discord with the email you used.')
      }
      if (state.value === 'waiting') {
        return h('div', { class: 'aowl-thanks' }, [
          h('h3', null, 'Payment received — minting your key…'),
          h('p', { class: 'aowl-muted' }, 'This normally takes a couple of seconds. Do not close the page.'),
        ])
      }
      if (state.value === 'reactivated') {
        return h('div', { class: 'aowl-thanks' }, [
          h('h3', null, 'Welcome back — your existing key is live again'),
          h('p', null, [
            'This is the same key you already had',
            prefix.value ? h('code', null, ` ${prefix.value}-••••-••••-••••`) : '',
            ', with your machines still on it. There is no new key, and nothing to reinstall.',
          ]),
          h('p', null, [
            h('a', { href: '/store/license' }, 'Open your licence page'),
            ' to check it and grab the latest build.',
          ]),
        ])
      }
      if (state.value === 'slow') {
        return h('div', { class: 'aowl-thanks' }, [
          h('h3', null, 'Your key is on its way by email'),
          h('p', null, 'The purchase went through. The key was either already shown once, or Stripe is taking longer than usual — check your inbox, then Discord if it does not arrive.'),
        ])
      }
      return h('div', { class: 'aowl-thanks' }, [
        h('h3', null, `Thanks — here is your ${product.value} key`),
        h('div', { class: 'aowl-key' }, [
          h('code', null, licenceKey.value),
          h('button', { class: 'aowl-ghost aowl-xs', onClick: copy }, copied.value ? 'Copied' : 'Copy'),
        ]),
        h('p', { class: 'aowl-warn' },
          'This is the only time this page will show it. A copy has been emailed to you; it is not recoverable from here.'),
        h('p', null, [
          'Next: ',
          h('a', { href: '/store/license' }, 'open your licence page'),
          ' to download the build and activate a machine.',
        ]),
      ])
    }
  },
}

export function registerStore(app) {
  app.component('BuyButton', BuyButton)
  app.component('StoreGrid', StoreGrid)
  app.component('LicensePanel', LicensePanel)
  app.component('ThanksPanel', ThanksPanel)
}
