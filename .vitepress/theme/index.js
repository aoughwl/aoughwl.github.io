import { h, ref, onMounted } from 'vue'
import { useData } from 'vitepress'
import DefaultTheme from 'vitepress/theme-without-fonts'
import './custom.css'
import './chrome.css'
import { initTooltips, initContextMenu } from './chrome.js'

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

// Brief, plain-English descriptions shown as hover tooltips on sidebar items —
// so you can learn what each stage is just by moving the mouse over it.
const DESC_BY_PATH = {
  '/docs/parity': 'How close the rebuild is to upstream Nimony, feature by feature',
  '/docs/aowlup': 'Version manager — installs and switches between toolchain pieces (like rustup)',
  '/docs/aowlmony': 'The driver that runs your code through the whole compiler pipeline',
  '/docs/aowlparser': 'Parser — turns source text into a structured syntax tree',
  '/docs/aowlsem': 'Semantic checker — resolves types, overloads, and reports errors',
  '/docs/aowlhexer': 'Lowering pass — simplifies typed code down toward the backends',
  '/aowli': 'Interpreter — runs your program directly, with no separate compile step',
  '/docs/aowllib': 'The native runtime library that compiled programs link against',
  '/docs/aowlhl': 'Shared high-level IR that the interpreter and JS backend both read',
  '/docs/aowlc': 'C backend — emits C source you can compile to a native binary',
  '/docs/aowljs': 'JavaScript backend — transpiles straight to fast native JS',
  '/docs/aowlweb': 'Faithful JS/WASM build for running the language in the browser',
  '/docs/aowlts': 'TypeScript backend — idiomatic, fully-typed output',
  '/docs/aowlpy': 'Python backend — idiomatic Python output',
  '/docs/aowllsp': 'Language Server — editor smarts: go-to-definition, hover, rename',
  '/docs/aowlsuggest': 'Quick-fixes and lints layered over the parser’s diagnostics',
  '/docs/aowlfmt': 'Formatter — canonical layout without ever changing meaning',
  '/docs/aowlcode': 'Claude Code plugin + MCP server wired into the toolchain',
  '/docs/aiflens': 'Command-line tool to inspect and query NIF/AIF artifacts',
  '/docs/obfuscate': 'IR-level obfuscator used for the binary-only public releases',
  '/docs/aowljson': 'Standalone JSON value library — parse, build, and serialize',
  '/docs/aowlmcp': 'Model Context Protocol server library (stdio, HTTP, HTTP/3)',
  '/docs/net-stack': 'From-scratch networking stack, one concern per library (TCP → HTTP/3)',
  '/docs/net-stack/tcp': 'Raw TCP sockets — the bottom of the networking stack',
  '/docs/net-stack/net': 'Socket ergonomics, dual-stack IPv6, buffered reads',
  '/docs/net-stack/tls': 'TLS 1.3 over OpenSSL — encrypted connections, client and server',
  '/docs/net-stack/http': 'Transport-free HTTP: headers, URLs, parsing, status codes',
  '/docs/net-stack/compress': 'gzip / brotli / zstd compression codecs',
  '/docs/net-stack/serve': 'HTTP/1.1 + HTTP/2 server with HTTPS and concurrency',
  '/docs/net-stack/reactor': 'Single-thread async engine: HTTP/1.1, WebSocket, HTTP/3 on one thread',
  '/docs/net-stack/ws': 'WebSocket (RFC 6455) — real-time two-way messaging',
  '/docs/net-stack/requests': 'Browser-identical HTTP client (curl-impersonate)',
  '/docs/web': 'Typed HTML5 builder for web pages',
  '/docs/html': 'HTML5 parser and document model',
  '/docs/css': 'CSS engine and styling DSL',
  '/docs/aowlhl-shared': 'Shared high-level IR',
}

// external icon+text link builder (used by the nav)
function extLink({ cls, href, target, icon, text, rightIcon, label, tip }) {
  const kids = []
  if (icon) kids.push(h('span', { class: 'nav-ico', innerHTML: icon }))
  if (text) kids.push(h('span', { class: 'nav-txt' }, text))
  if (rightIcon) kids.push(h('span', { class: 'nav-ico nav-ico-r', innerHTML: rightIcon }))
  const attrs = { class: cls, href, target: target || '_blank', rel: 'noopener', 'aria-label': label || text }
  if (tip) attrs['data-tip'] = tip
  return h('a', attrs, kids)
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

    // plain-English hover description for the row (independent of the repo badge)
    const desc = DESC_BY_PATH[linkPath]
    if (desc && link.getAttribute('data-tip') !== desc) link.setAttribute('data-tip', desc)

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
    badge.setAttribute('data-tip', 'github.com/aoughwl/' + repo + ' ↗')
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
        h('a', { class: 'repo-btn', href, target: '_blank', rel: 'noopener', 'aria-label': 'GitHub — ' + label, 'data-tip': 'View ' + label + ' on GitHub ↗' }, [
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
            extLink({ cls: 'nav-pg-link', href: PLAYGROUND_URL, target: '_self', icon: PLAY_SVG, text: 'Playground', rightIcon: REDIRECT_SVG, label: 'Open the playground', tip: 'Run nimony in your browser ↗' }),
            h('div', { class: 'nav-social' }, [
              extLink({ cls: 'nav-social-link', href: GITHUB_URL, icon: GITHUB_SVG, text: 'GitHub', label: 'GitHub · aoughwl', tip: 'aoughwl on GitHub ↗' }),
              extLink({ cls: 'nav-social-link nav-discord', href: DISCORD_URL, icon: DISCORD_SVG, text: 'Discord', label: 'Discord', tip: 'Join the Discord ↗' }),
              extLink({ cls: 'nav-social-link nav-support', href: SUPPORT_URL, icon: HEART_SVG, text: 'Support', label: 'Support us', tip: 'Support the project ↗' }),
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
    const raf = (fn) => { let q = false; return () => { if (q) return; q = true; requestAnimationFrame(() => { q = false; fn() }) } }

    // the one-time entrance animation (class stamped pre-paint in the head script)
    // plays once, then we drop the class so it never replays on SPA navigation.
    setTimeout(() => root.classList.remove('aowl-boot'), 1000)

    // ===== sidebar collapse (manual, binary) ================================
    // The centering gutter VitePress uses on wide viewports, (100vw − max)/2,
    // so the collapsed layout stays centered instead of hugging a side.
    let layoutMax = 1440
    const setGutter = () => {
      const v = parseInt(getComputedStyle(root).getPropertyValue('--vp-layout-max-width'))
      if (v) layoutMax = v
      root.style.setProperty('--aowl-gutter', Math.max(0, (window.innerWidth - layoutMax) / 2) + 'px')
    }
    setGutter()
    window.addEventListener('resize', raf(setGutter), { passive: true })

    const KEY = 'aowl-sb-collapsed'
    const setCollapsed = (on) => {
      root.classList.toggle('aowl-sb-collapsed', on)
      localStorage.setItem(KEY, on ? '1' : '0')
    }
    if (localStorage.getItem(KEY) === '1') root.classList.add('aowl-sb-collapsed')

    // Persisted sidebar geometry: POSITION offset (drag the handle) and WIDTH
    // (hold the handle + scroll wheel). VitePress reads --vp-sidebar-width;
    // --aowl-sb-x nudges the whole sidebar horizontally.
    const WKEY = 'aowl-sb-width', XKEY = 'aowl-sb-x'
    const WMIN = 220, WMAX = 520
    const clamp = (v, lo, hi) => Math.max(lo, Math.min(hi, v))
    const applyWidth = (w) => root.style.setProperty('--vp-sidebar-width', w + 'px')
    const applyX = (x) => root.style.setProperty('--aowl-sb-x', x + 'px')
    const curWidth = () => parseInt(getComputedStyle(root).getPropertyValue('--vp-sidebar-width')) || 300
    const curX = () => parseInt(getComputedStyle(root).getPropertyValue('--aowl-sb-x')) || 0
    // Horizontal-offset limits from the sidebar's ACTUAL rendered inset — its
    // computed padding-left already encodes VitePress's per-breakpoint centering
    // gutter, so we don't re-derive (or overshoot) it. Content-left = inset + x,
    // so the min offset leaves LEFT_MARGIN of space (never off-screen) and the
    // max is a small bounded rightward push. Falls back to the gutter estimate
    // before the sidebar DOM exists.
    const LEFT_MARGIN = 18, RIGHT_MAX = 90
    const xBounds = () => {
      const sb = document.querySelector('.VPSidebar')
      const padL = sb ? parseFloat(getComputedStyle(sb).paddingLeft) : NaN
      const inset = Number.isFinite(padL) && padL > 0
        ? padL
        : (parseInt(getComputedStyle(root).getPropertyValue('--aowl-gutter')) || 0) + 32
      return { min: LEFT_MARGIN - inset, max: RIGHT_MAX }
    }
    const clampX = (x) => { const b = xBounds(); return clamp(x, b.min, b.max) }
    const savedW = parseInt(localStorage.getItem(WKEY)); if (savedW >= WMIN && savedW <= WMAX) applyWidth(savedW)
    // remember the user's intended offset; re-clamp it to the live viewport (so a
    // flush-left drag on a wide screen still resolves sensibly after a resize)
    const savedX = parseInt(localStorage.getItem(XKEY))
    let xIntent = Number.isFinite(savedX) ? savedX : 0
    applyX(clampX(xIntent))
    window.addEventListener('resize', raf(() => applyX(clampX(xIntent))), { passive: true })

    const PANEL_CLOSE =
      '<svg viewBox="0 0 24 24" width="16" height="16" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><rect x="3" y="4" width="18" height="16" rx="2"/><line x1="9" y1="4" x2="9" y2="20"/><polyline points="14.5 9 11.5 12 14.5 15"/></svg>'
    const PANEL_OPEN =
      '<svg viewBox="0 0 24 24" width="17" height="17" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><rect x="3" y="4" width="18" height="16" rx="2"/><line x1="9" y1="4" x2="9" y2="20"/><polyline points="11.5 9 14.5 12 11.5 15"/></svg>'

    // Collapse control docked at the right of the OVERVIEW heading.
    const mountCollapse = () => {
      const sb = document.querySelector('.VPSidebar')
      if (!sb || sb.querySelector('.aowl-sb-collapse')) return
      const label = sb.querySelector('.group .VPSidebarItem.level-0 > .item .text')
        || sb.querySelector('.VPSidebarItem.level-0 .text')
      if (!label) return
      const host = label.closest('.item') || label.parentElement
      const b = document.createElement('button')
      b.className = 'aowl-sb-collapse'
      b.type = 'button'
      b.setAttribute('data-tip', 'Click to hide · drag to move · hold + scroll to resize')
      b.setAttribute('aria-label', 'Hide, move, or resize sidebar')
      b.innerHTML = PANEL_CLOSE

      // Plain click = hide. Horizontal drag = move the sidebar's position. Hold
      // the handle and scroll the wheel = resize its width.
      let dragging = false, acted = false, startX = 0, startXOff = 0
      const onMove = (e) => {
        const dx = e.clientX - startX
        if (Math.abs(dx) > 3) acted = true      // it's a drag, not a plain click
        if (acted) applyX(clampX(startXOff + dx))
      }
      // while held, scroll ANYWHERE resizes width — the handle moves as the width
      // changes, so a button-scoped wheel listener falls out from under the cursor
      const onWheel = (e) => {
        e.preventDefault()
        const w = clamp(curWidth() + (e.deltaY < 0 ? 14 : -14), WMIN, WMAX)
        applyWidth(w); localStorage.setItem(WKEY, String(w))
        acted = true
      }
      const onUp = () => {
        window.removeEventListener('pointermove', onMove)
        window.removeEventListener('pointerup', onUp)
        window.removeEventListener('wheel', onWheel)
        root.classList.remove('aowl-sb-resizing')
        if (acted) { xIntent = curX(); localStorage.setItem(XKEY, String(xIntent)) }
        dragging = false
        setTimeout(() => { acted = false }, 0)   // let a real click through, block a drag's click
      }
      b.addEventListener('pointerdown', (e) => {
        if (e.button !== 0) return
        dragging = true; acted = false; startX = e.clientX; startXOff = curX()
        // Freeze transitions for the WHOLE hold so move + wheel are instant in
        // ANY order — adding this only after motion left a wheel-then-move
        // sequence animating each step (the "jumping" glitch). Removed on pointerup
        // (before the click event), so a plain click still animates the collapse.
        root.classList.add('aowl-sb-resizing')
        window.addEventListener('pointermove', onMove)
        window.addEventListener('pointerup', onUp)
        window.addEventListener('wheel', onWheel, { passive: false })   // hold + scroll
        e.preventDefault()
      })
      b.addEventListener('click', (e) => {
        e.preventDefault(); e.stopPropagation()
        if (acted) return          // it was a drag/resize, not a collapse
        setCollapsed(true)
      })
      host.appendChild(b)
    }
    mountCollapse()
    new MutationObserver(raf(mountCollapse)).observe(document.body, { childList: true, subtree: true })
    const origRC = router.onAfterRouteChanged
    router.onAfterRouteChanged = (to) => { origRC?.(to); requestAnimationFrame(mountCollapse) }

    // Floating "show sidebar" handle — only visible while collapsed.
    const expand = document.createElement('button')
    expand.className = 'aowl-sb-expand'
    expand.type = 'button'
    expand.setAttribute('data-tip', 'Show sidebar')
    expand.setAttribute('aria-label', 'Show sidebar')
    expand.innerHTML = PANEL_OPEN
    expand.addEventListener('click', () => setCollapsed(false))
    document.body.appendChild(expand)

    // ===== rounded text-selection overlay ==================================
    // Native ::selection can't have rounded corners, so we hide it and paint our
    // own rounded pills over the selection's client rects — one per line.
    const selLayer = document.createElement('div')
    selLayer.className = 'aowl-sel-layer'
    document.body.appendChild(selLayer)
    const drawSel = () => {
      const sel = window.getSelection()
      if (!sel || sel.isCollapsed || sel.rangeCount === 0) { selLayer.textContent = ''; return }
      const raw = sel.getRangeAt(0).getClientRects()
      if (!raw.length) { selLayer.textContent = ''; return }

      // getClientRects() emits a separate rect per inline element (bold, code,
      // links…), so a selection spanning them fragments into many pills. Merge
      // rects that share a line into one continuous band so each visual line is a
      // single rounded highlight.
      const rects = [...raw].filter((r) => r.width > 0.5 && r.height > 0.5)
        .sort((a, b) => a.top - b.top || a.left - b.left)
      const lines = []
      for (const r of rects) {
        const last = lines[lines.length - 1]
        // same line ⇒ vertical overlap of >60% with the current band
        if (last && Math.min(last.bottom, r.bottom) - Math.max(last.top, r.top) > Math.min(last.bottom - last.top, r.height) * 0.6) {
          last.left = Math.min(last.left, r.left)
          last.right = Math.max(last.right, r.right)
          last.top = Math.min(last.top, r.top)
          last.bottom = Math.max(last.bottom, r.bottom)
        } else {
          lines.push({ left: r.left, right: r.right, top: r.top, bottom: r.bottom })
        }
      }
      let html = ''
      for (const b of lines.slice(0, 400)) {
        const w = b.right - b.left, h = b.bottom - b.top
        if (w < 1 || h < 1) continue
        html += `<span style="left:${b.left}px;top:${b.top - 1}px;width:${w}px;height:${h + 2}px"></span>`
      }
      selLayer.innerHTML = html
    }
    const schedSel = raf(drawSel)
    document.addEventListener('selectionchange', schedSel)
    window.addEventListener('scroll', schedSel, { passive: true })
    window.addEventListener('resize', schedSel, { passive: true })

    // ===== shared UI chrome: fancy tooltips + right-click context menu ======
    initTooltips()
    const ghUrl = () => { const a = document.querySelector('.repo-btn'); return a && a.getAttribute('href') }
    const copy = (t) => { try { navigator.clipboard && navigator.clipboard.writeText(t) } catch (_) {} }
    initContextMenu((target) => {
      const s = (window.getSelection && window.getSelection().toString()) || ''
      const inDoc = target.closest('.vp-doc, .VPContent')
      const idEl = target.closest('.vp-doc [id]')
      const items = []
      items.push({ label: 'Copy', kb: '⌘C', off: !s, act: () => copy(s) })
      if (idEl && idEl.id) {
        const name = idEl.id.length > 26 ? idEl.id.slice(0, 26) + '…' : idEl.id
        items.push({ label: 'Copy link to “' + name + '”', act: () => copy(location.origin + location.pathname + '#' + idEl.id) })
      }
      if (inDoc) {
        items.push({ label: 'Select article', kb: '⌘A', act: () => {
          const m = document.querySelector('.vp-doc'); if (!m) return
          const r = document.createRange(); r.selectNodeContents(m)
          const g = window.getSelection(); g.removeAllRanges(); g.addRange(r)
        } })
      }
      items.push({ sep: true })
      items.push({ label: 'Copy page link', act: () => copy(location.href) })
      items.push({ label: 'View page source on GitHub', off: !ghUrl(), act: () => { const u = ghUrl(); if (u) window.open(u, '_blank', 'noopener') } })
      items.push({ sep: true })
      items.push({ label: 'Back', kb: '⌥←', off: history.length < 2, act: () => history.back() })
      items.push({ label: 'Forward', kb: '⌥→', act: () => history.forward() })
      return items
    }, { allowNativeOn: 'input, textarea, .VPNavBarSearch, .VPLocalSearchBox' })
  },
}
