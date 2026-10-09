// deadlinks.mjs — every internal link in the BUILT site must land on a page.
//
//   npm run docs:build && node tools/deadlinks.mjs [dist=.vitepress/dist]
//
// The config sets `ignoreDeadLinks: true` (the generated aowlspt reference has
// links VitePress cannot see through), so the build never fails on a dead link.
// This walks the output instead: for each <a href> that stays on this site, the
// target must exist as a file, a `.html` page (cleanUrls), or a directory index,
// and a `#fragment` must name an id on that page. Exit 1 lists every miss.
import fs from "node:fs";
import path from "node:path";

const dist = path.resolve(process.argv[2] || ".vitepress/dist");
const pages = [];
(function walk(d) {
  for (const e of fs.readdirSync(d, { withFileTypes: true })) {
    const p = path.join(d, e.name);
    if (e.isDirectory()) { if (!["assets", "playground", "jester-demo", "aowlspt"].includes(e.name) || d !== dist) walk(p); }
    else if (e.name.endsWith(".html")) pages.push(p);
  }
})(dist);

const idsCache = new Map();
function idsOf(file) {
  if (!idsCache.has(file)) {
    const html = fs.readFileSync(file, "utf8");
    idsCache.set(file, new Set([...html.matchAll(/\sid="([^"]+)"/g)].map((m) => m[1])));
  }
  return idsCache.get(file);
}
function resolve(urlPath) {
  const clean = decodeURIComponent(urlPath).replace(/\/+$/, "");
  const cands = [clean, clean + ".html", path.join(clean, "index.html")];
  if (clean === "") cands.push("index.html");
  for (const c of cands) {
    const f = path.join(dist, c);
    if (fs.existsSync(f) && fs.statSync(f).isFile()) return f;
  }
  return null;
}

const misses = [];
for (const page of pages) {
  const html = fs.readFileSync(page, "utf8");
  const here = "/" + path.relative(dist, page).replace(/index\.html$/, "").replace(/\.html$/, "");
  for (const m of html.matchAll(/<a\s[^>]*href="([^"]+)"/g)) {
    let href = m[1].replace(/&amp;/g, "&");
    if (/^(mailto:|javascript:|data:)/.test(href)) continue;
    if (/^https?:\/\//.test(href)) {
      const u = new URL(href);
      if (u.host !== "aoughwl.github.io" && u.host !== "aoughwl.com") continue;
      href = u.pathname + u.hash;
    }
    const [p, frag] = href.split("#");
    let target;
    if (p === "") target = page;
    else {
      const abs = p.startsWith("/") ? p : path.posix.join(path.posix.dirname(here + "x"), p);
      if (abs.startsWith("/playground") || abs.startsWith("/jester-demo")) continue;
      target = resolve(abs);
    }
    if (!target) { misses.push(`${here}  →  ${href}`); continue; }
    if (frag && target.endsWith(".html") && !idsOf(target).has(decodeURIComponent(frag)))
      misses.push(`${here}  →  ${href}   (no such #id)`);
  }
}
const uniq = [...new Set(misses)].sort();
console.log(`${pages.length} pages checked, ${uniq.length} dead internal link(s)`);
for (const m of uniq) console.log("  " + m);
process.exit(uniq.length ? 1 : 0);
