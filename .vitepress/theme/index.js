import { h, ref, onMounted } from 'vue'
import { useData } from 'vitepress'
import DefaultTheme from 'vitepress/theme-without-fonts'
import './custom.css'

// ---- icons ----------------------------------------------------------------
const GITHUB_SVG = `<svg viewBox="0 0 16 16" width="17" height="17" aria-hidden="true"><path fill="currentColor" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.01 8.01 0 0 0 16 8c0-4.42-3.58-8-8-8Z"></path></svg>`
const DISCORD_SVG = `<svg viewBox="0 0 24 24" width="18" height="18" aria-hidden="true"><path fill="currentColor" d="M20.317 4.3698a19.7913 19.7913 0 0 0-4.8851-1.5152.0741.0741 0 0 0-.0785.0371c-.211.3753-.4447.8648-.6083 1.2495-1.8447-.2762-3.68-.2762-5.4868 0-.1636-.3933-.4058-.8742-.6177-1.2495a.077.077 0 0 0-.0785-.037 19.7363 19.7363 0 0 0-4.8852 1.515.0699.0699 0 0 0-.0321.0277C.5334 9.0458-.319 13.5799.0992 18.0578a.0824.0824 0 0 0 .0312.0561c2.0528 1.5076 4.0413 2.4228 5.9929 3.0294a.0777.0777 0 0 0 .0842-.0276c.4616-.6304.8731-1.2952 1.226-1.9942a.076.076 0 0 0-.0416-.1057c-.6528-.2476-1.2743-.5495-1.8722-.8923a.077.077 0 0 1-.0076-.1277c.1258-.0943.2517-.1923.3718-.2914a.0743.0743 0 0 1 .0776-.0105c3.9278 1.7933 8.18 1.7933 12.0614 0a.0739.0739 0 0 1 .0785.0095c.1202.099.246.1981.3728.2924a.077.077 0 0 1-.0066.1276 12.2986 12.2986 0 0 1-1.873.8914.0766.0766 0 0 0-.0407.1067c.3604.698.7719 1.3628 1.225 1.9932a.076.076 0 0 0 .0842.0286c1.961-.6067 3.9495-1.5219 6.0023-3.0294a.077.077 0 0 0 .0313-.0552c.5004-5.177-.8382-9.6739-3.5485-13.6604a.061.061 0 0 0-.0312-.0286zM8.02 15.3312c-1.1825 0-2.1569-1.0857-2.1569-2.419 0-1.3332.9555-2.4189 2.157-2.4189 1.2108 0 2.1757 1.0952 2.1568 2.419 0 1.3332-.9555 2.4189-2.1569 2.4189zm7.9748 0c-1.1825 0-2.1569-1.0857-2.1569-2.419 0-1.3332.9554-2.4189 2.1569-2.4189 1.2108 0 2.1757 1.0952 2.1568 2.419 0 1.3332-.946 2.4189-2.1568 2.4189Z"></path></svg>`
const HEART_SVG = `<svg viewBox="0 0 24 24" width="17" height="17" aria-hidden="true"><path fill="currentColor" d="M12 21.35l-1.45-1.32C5.4 15.36 2 12.28 2 8.5 2 5.42 4.42 3 7.5 3c1.74 0 3.41.81 4.5 2.09C13.09 3.81 14.76 3 16.5 3 19.58 3 22 5.42 22 8.5c0 3.78-3.4 6.86-8.55 11.54L12 21.35z"></path></svg>`
const PLAY_SVG = `<svg viewBox="0 0 24 24" width="15" height="15" aria-hidden="true"><path fill="currentColor" d="M8 5v14l11-7z"></path></svg>`
const REDIRECT_SVG = `<svg viewBox="0 0 24 24" width="13" height="13" aria-hidden="true" fill="none" stroke="currentColor" stroke-width="2.4" stroke-linecap="round" stroke-linejoin="round"><path d="M7 17 17 7M8 7h9v9"/></svg>`
const REDIRECT_SM = `<svg viewBox="0 0 24 24" width="11" height="11" aria-hidden="true" fill="none" stroke="currentColor" stroke-width="2.4" stroke-linecap="round" stroke-linejoin="round"><path d="M7 17 17 7M8 7h9v9"/></svg>`

const DISCORD_URL = 'https://discord.gg/nxa3W7w4rJ'
const GITHUB_URL = 'https://github.com/aoughwl'
const SUPPORT_URL = 'https://donate.stripe.com/3cI6oH1eJ74w9L1e3ueAg00'
const PLAYGROUND_URL = 'https://aoughwl.github.io/playground/'

const REPO_BASE = 'https://github.com/aoughwl/'
const SEP = ' — '

// Repos for sidebar items that DON'T use the "Name — repo" label form (their
// label is already the bare repo name, or an external app). These get an
// icon-only "↗" badge to their repo.
const REPO_BY_PATH = {
  '/docs/web': 'web',
  '/docs/html': 'html',
  '/docs/css': 'css',
  '/docs/net-stack/tcp': 'tcp',
  '/docs/net-stack/net': 'net',
  '/docs/net-stack/tls': 'tls',
  '/docs/net-stack/http': 'http',
  '/docs/net-stack/compress': 'compress',
  '/docs/net-stack/serve': 'serve',
  '/docs/net-stack/ws': 'ws',
  '/docs/net-stack/requests': 'requests',
}

const norm = (p) => (p || '').replace(/index$/, '').replace(/\.html$/, '').replace(/\/$/, '') || '/'

// external icon+text link builder (used by the nav)
function extLink({ cls, href, target, icon, text, rightIcon, label }) {
  const kids = []
  if (icon) kids.push(h('span', { class: 'nav-ico', innerHTML: icon }))
  if (text) kids.push(h('span', { class: 'nav-txt' }, text))
  if (rightIcon) kids.push(h('span', { class: 'nav-ico nav-ico-r', innerHTML: rightIcon }))
  return h('a', { class: cls, href, target: target || '_blank', rel: 'noopener', 'aria-label': label || text }, kids)
}

// ---- sidebar repo badges --------------------------------------------------
function decorateSidebar() {
  const items = document.querySelectorAll('.VPSidebar .VPSidebarItem .item > .link')
  items.forEach((link) => {
    const p = link.querySelector('.text')
    const item = link.closest('.item')
    if (!p || !item) return

    let repo = null
    let withText = false
    const full = p.dataset.full || p.textContent
    const idx = full.indexOf(SEP)
    const linkPath = norm(new URL(link.getAttribute('href') || '/', location.origin).pathname)

    if (idx !== -1) {
      // "Native JS — aowljs" → name + "aowljs ↗"
      p.dataset.full = full
      const name = full.slice(0, idx).trim()
      repo = full.slice(idx + SEP.length).trim()
      withText = true
      if (p.textContent !== name) p.textContent = name
    } else if (REPO_BY_PATH[linkPath]) {
      // libraries etc. — label already IS the repo name, but show the name on
      // the badge too (with the ↗) so it reads as a real repo link.
      repo = REPO_BY_PATH[linkPath]
      withText = true
    }
    // NOTE: Playground intentionally gets NO repo badge — it already has its own
    // natural link to the app; a second redirect looked wrong.
    if (!repo) return

    let badge = item.querySelector(':scope > .repo-badge')
    if (!badge) {
      badge = document.createElement('a')
      badge.className = 'repo-badge'
      badge.target = '_blank'
      badge.rel = 'noopener'
      // clicks must open the repo, never toggle/navigate the row
      badge.addEventListener('click', (e) => e.stopPropagation())
      const caret = item.querySelector(':scope > .caret')
      if (caret) item.insertBefore(badge, caret)
      else item.appendChild(badge)
      item.classList.add('has-repo-badge')
    }
    const href = REPO_BASE + repo
    if (badge.getAttribute('href') !== href) badge.setAttribute('href', href)
    badge.title = 'github.com/aoughwl/' + repo
    badge.classList.toggle('icon-only', !withText)
    badge.innerHTML = withText ? `<span class="repo-badge-name">${repo}</span>${REDIRECT_SM}` : REDIRECT_SM
  })
}

// ---- generic per-page GitHub button --------------------------------------
// Every doc page gets its repo button for free: just add `repo: aoughwl/<name>`
// (or a full URL) to the page's YAML front-matter. No per-page markup, no
// hand-written links. Rendered at the top of the doc via the `doc-before` slot.
const RepoButton = {
  setup() {
    const { frontmatter } = useData()
    return () => {
      const repo = frontmatter.value.repo
      if (!repo) return null
      // front-matter carries `owner/repo` (e.g. aoughwl/requests) or a full URL.
      const label = repo.replace(/^https?:\/\/github\.com\//, '').replace(/\/$/, '')
      const href = /^https?:\/\//.test(repo) ? repo : 'https://github.com/' + label
      return h('div', { class: 'repo-btn-row' }, [
        h('a', { class: 'repo-btn', href, target: '_blank', rel: 'noopener', 'aria-label': 'GitHub — ' + label }, [
          h('span', { class: 'repo-btn-ico', innerHTML: GITHUB_SVG }),
          h('span', { class: 'repo-btn-txt' }, label),
          h('span', { class: 'repo-btn-arrow', innerHTML: REDIRECT_SM }),
        ]),
      ])
    }
  },
}

// ---- client-only nav extras (renders after mount → no hydration mismatch) --
const NavExtras = {
  setup() {
    const mounted = ref(false)
    onMounted(() => { mounted.value = true })
    return () =>
      mounted.value
        ? h('div', { class: 'nav-right' }, [
            extLink({ cls: 'nav-pg-link', href: PLAYGROUND_URL, target: '_self', icon: PLAY_SVG, text: 'Playground', rightIcon: REDIRECT_SVG, label: 'Open the playground' }),
            h('div', { class: 'nav-social' }, [
              extLink({ cls: 'nav-social-link', href: GITHUB_URL, icon: GITHUB_SVG, text: 'GitHub', label: 'GitHub · aoughwl' }),
              extLink({ cls: 'nav-social-link nav-discord', href: DISCORD_URL, icon: DISCORD_SVG, text: 'Discord', label: 'Discord' }),
              extLink({ cls: 'nav-social-link nav-support', href: SUPPORT_URL, icon: HEART_SVG, text: 'Support', label: 'Support us' }),
            ]),
          ])
        : null
  },
}

export default {
  extends: DefaultTheme,
  Layout() {
    return h(DefaultTheme.Layout, null, {
      'nav-bar-content-after': () => h(NavExtras),
      'doc-before': () => h(RepoButton),
    })
  },
  enhanceApp({ router }) {
    if (typeof window === 'undefined') return
    const run = () => requestAnimationFrame(decorateSidebar)
    const orig = router.onAfterRouteChanged
    router.onAfterRouteChanged = (to) => { orig?.(to); run() }
    if (document.readyState !== 'loading') run()
    else window.addEventListener('DOMContentLoaded', run)

    const start = () => {
      const sb = document.querySelector('.VPSidebar')
      if (!sb) return setTimeout(start, 150)
      let queued = false
      new MutationObserver(() => {
        if (queued) return
        queued = true
        requestAnimationFrame(() => { queued = false; decorateSidebar() })
      }).observe(sb, { childList: true, subtree: true })
      run()
    }
    start()

    // --- scroll state: lets the top bar declutter as you leave the top ---
    const root = document.documentElement
    let ticking = false
    const onScroll = () => {
      if (ticking) return
      ticking = true
      requestAnimationFrame(() => {
        root.classList.toggle('aowl-scrolled', window.scrollY > 12)
        ticking = false
      })
    }
    window.addEventListener('scroll', onScroll, { passive: true })
    onScroll()

    // --- desktop-only sidebar collapse toggle ---
    // Persisted across navigations/sessions; a floating pill toggles a class on
    // <html> that the CSS uses to slide the sidebar out and widen the content.
    const KEY = 'aowl-sidebar-collapsed'
    if (localStorage.getItem(KEY) === '1') root.classList.add('aowl-sidebar-collapsed')
    const mountToggle = () => {
      if (document.querySelector('.aowl-sb-toggle')) return
      const btn = document.createElement('button')
      btn.className = 'aowl-sb-toggle'
      btn.type = 'button'
      btn.setAttribute('aria-label', 'Toggle sidebar')
      btn.title = 'Toggle sidebar'
      btn.innerHTML =
        '<svg viewBox="0 0 24 24" width="15" height="15" fill="none" stroke="currentColor" stroke-width="2.2" stroke-linecap="round" stroke-linejoin="round"><polyline points="15 6 9 12 15 18"/></svg>'
      btn.addEventListener('click', () => {
        const on = root.classList.toggle('aowl-sidebar-collapsed')
        localStorage.setItem(KEY, on ? '1' : '0')
      })
      document.body.appendChild(btn)
    }
    mountToggle()
  },
}
