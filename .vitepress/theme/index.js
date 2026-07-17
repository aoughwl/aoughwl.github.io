import { h } from 'vue'
import DefaultTheme from 'vitepress/theme'
import './custom.css'

// GitHub mark for the single icon+text nav link.
const GITHUB_SVG = `<svg viewBox="0 0 16 16" width="18" height="18" aria-hidden="true"><path fill="currentColor" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.01 8.01 0 0 0 16 8c0-4.42-3.58-8-8-8Z"></path></svg>`

// small redirect / external-link arrow for the sidebar repo badges
const REDIRECT_SVG = `<svg viewBox="0 0 24 24" width="11" height="11" aria-hidden="true" fill="none" stroke="currentColor" stroke-width="2.4" stroke-linecap="round" stroke-linejoin="round"><path d="M7 17 17 7M8 7h9v9"/></svg>`

const REPO_BASE = 'https://github.com/aoughwl/'
const SEP = ' — ' // em dash used in the sidebar labels

// Turn "Native JS — aowljs" sidebar rows into: left name (the page link) +
// a right-aligned "aowljs ↗" badge linking to the repo. Idempotent; re-run on
// every sidebar mutation so Vue re-renders can't wipe it.
function decorateSidebar() {
  const texts = document.querySelectorAll('.VPSidebar .VPSidebarItem .item > .link .text')
  texts.forEach((p) => {
    const item = p.closest('.item')
    if (!item) return
    const full = p.dataset.full || p.textContent
    const idx = full.indexOf(SEP)
    if (idx === -1) return

    p.dataset.full = full // remember the original for re-runs
    const name = full.slice(0, idx).trim()
    const repo = full.slice(idx + SEP.length).trim()

    // left side shows just the friendly name
    if (p.textContent !== name) p.textContent = name

    // (re)build the badge
    let badge = item.querySelector(':scope > .repo-badge')
    if (!badge) {
      badge = document.createElement('a')
      badge.className = 'repo-badge'
      badge.target = '_blank'
      badge.rel = 'noopener'
      badge.addEventListener('click', (e) => e.stopPropagation())
      item.appendChild(badge)
      item.classList.add('has-repo-badge')
    }
    const href = REPO_BASE + repo
    if (badge.getAttribute('href') !== href) badge.setAttribute('href', href)
    badge.innerHTML = `<span class="repo-badge-name">${repo}</span>${REDIRECT_SVG}`
  })
}

export default {
  extends: DefaultTheme,
  Layout() {
    return h(DefaultTheme.Layout, null, {
      'nav-bar-content-after': () =>
        h(
          'a',
          {
            class: 'nav-gh-link',
            href: 'https://github.com/aoughwl',
            target: '_blank',
            rel: 'noopener',
            'aria-label': 'GitHub · aoughwl',
          },
          [h('span', { class: 'nav-gh-icon', innerHTML: GITHUB_SVG }), h('span', { class: 'nav-gh-text' }, 'GitHub')]
        ),
    })
  },
  enhanceApp({ router }) {
    if (typeof window === 'undefined') return
    const run = () => requestAnimationFrame(decorateSidebar)
    // initial + after every SPA route change
    const orig = router.onAfterRouteChanged
    router.onAfterRouteChanged = (to) => {
      orig?.(to)
      run()
    }
    if (document.readyState !== 'loading') run()
    else window.addEventListener('DOMContentLoaded', run)
    // survive Vue re-renders (active-state patches wipe injected nodes)
    const startObserver = () => {
      const sb = document.querySelector('.VPSidebar')
      if (!sb) return setTimeout(startObserver, 150)
      let queued = false
      new MutationObserver(() => {
        if (queued) return
        queued = true
        requestAnimationFrame(() => {
          queued = false
          decorateSidebar()
        })
      }).observe(sb, { childList: true, subtree: true })
      decorateSidebar()
    }
    startObserver()
  },
}
