// aowlui — tiny, dependency-free UI chrome shared across the aoughwl web
// properties (the playground and the docs site): fancy hover tooltips and a
// unified right-click context menu. Framework-agnostic ES module; pair it with
// aowlui.css.
//
//   import { initTooltips, initContextMenu, initAowlUI } from './aowlui.js'

// ---------------------------------------------------------------------------
// Tooltips: any element with a `data-tip` attribute gets a floating label on
// hover (after a short delay), viewport-clamped, flipping above when it would
// overflow the bottom.
// ---------------------------------------------------------------------------
export function initTooltips(opts = {}) {
  // Tooltips are a hover affordance. On touch devices a tap fires a synthetic
  // mouseover (shows) with no matching mouseout (so it sticks) — so skip them
  // entirely unless the device can actually hover.
  if (typeof window === 'undefined' || !window.matchMedia ||
      !window.matchMedia('(hover: hover)').matches) {
    return { hide() {} }
  }
  const delay = opts.delay == null ? 350 : opts.delay
  let tipEl = null, timer = null, cur = null

  const ensure = () => {
    if (!tipEl) { tipEl = document.createElement('div'); tipEl.id = 'aui-tooltip'; document.body.appendChild(tipEl) }
    return tipEl
  }
  const show = (el) => {
    const t = el.getAttribute('data-tip'); if (!t) return
    const tip = ensure(); tip.textContent = t; tip.classList.add('show')
    const r = el.getBoundingClientRect(), tr = tip.getBoundingClientRect()
    let left = r.left + r.width / 2 - tr.width / 2
    left = Math.max(6, Math.min(left, window.innerWidth - tr.width - 6))
    let top = r.bottom + 7
    if (top + tr.height > window.innerHeight - 6) top = r.top - tr.height - 7
    tip.style.left = left + 'px'
    tip.style.top = Math.max(6, top) + 'px'
  }
  const hide = () => { if (tipEl) tipEl.classList.remove('show') }

  document.addEventListener('mouseover', (e) => {
    const el = e.target.closest('[data-tip]')
    // suppress the browser's native title tooltip so ours isn't doubled
    if (el && el.hasAttribute('title')) el.removeAttribute('title')
    if (el === cur) return
    cur = el; clearTimeout(timer)
    if (el) timer = setTimeout(() => show(el), delay); else hide()
  })
  document.addEventListener('mouseout', (e) => {
    if (e.target.closest('[data-tip]')) { clearTimeout(timer); hide(); cur = null }
  })
  document.addEventListener('click', () => { clearTimeout(timer); hide() })
  window.addEventListener('scroll', hide, true)
  return { hide }
}

// ---------------------------------------------------------------------------
// Context menu: right-click opens our own menu. `build(target, event)` returns
// an array of items — `{ label, kb?, off?, act? }` or `{ sep: true }`. Return an
// empty array to fall through to the browser's native menu. `opts.allowNativeOn`
// is a selector where the native menu is preferred (e.g. inputs).
// ---------------------------------------------------------------------------
export function initContextMenu(build, opts = {}) {
  const menu = document.createElement('div')
  menu.id = 'aui-ctxmenu'
  menu.setAttribute('role', 'menu')
  document.body.appendChild(menu)

  const hide = () => menu.classList.remove('show')
  const open = (x, y, items) => {
    menu.innerHTML = ''
    for (const it of items) {
      if (it.sep) { const s = document.createElement('div'); s.className = 'sep'; menu.appendChild(s); continue }
      const d = document.createElement('div')
      d.className = 'item' + (it.off ? ' disabled' : '')
      d.innerHTML = '<span>' + it.label + '</span>' + (it.kb ? '<span class="kb">' + it.kb + '</span>' : '')
      if (!it.off) d.addEventListener('mousedown', (e) => { e.preventDefault(); hide(); try { it.act && it.act() } catch (_) {} })
      menu.appendChild(d)
    }
    menu.classList.add('show')
    const mw = menu.offsetWidth, mh = menu.offsetHeight
    menu.style.left = Math.max(6, Math.min(x, window.innerWidth - mw - 6)) + 'px'
    menu.style.top = Math.max(6, Math.min(y, window.innerHeight - mh - 6)) + 'px'
  }

  // capture phase — some editors (Monaco) consume contextmenu on their own node.
  document.addEventListener('contextmenu', (e) => {
    if (opts.allowNativeOn && e.target.closest(opts.allowNativeOn)) return
    const items = build(e.target, e) || []
    if (!items.length) return
    e.preventDefault(); e.stopPropagation()
    open(e.clientX, e.clientY, items)
  }, true)
  document.addEventListener('mousedown', (e) => { if (!e.target.closest('#aui-ctxmenu')) hide() }, true)
  document.addEventListener('scroll', hide, true)
  window.addEventListener('resize', hide)
  document.addEventListener('keydown', (e) => { if (e.key === 'Escape') hide() })
  return { hide }
}

// Convenience: wire both at once.
export function initAowlUI(opts = {}) {
  initTooltips(opts.tooltip || {})
  if (opts.contextMenu) initContextMenu(opts.contextMenu, opts.contextMenuOpts || {})
}
