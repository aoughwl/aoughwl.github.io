// serve.mjs — a plain static server for poking at the playground by hand.
//
//   node tools/serve.mjs [port] [dir]
//
// The verification harnesses each spin up their own server on an ephemeral port
// and tear it down; this one stays up on a known port so a human can open it.
// No caching headers, because the whole point is to reload after an edit.
import http from "node:http";
import fs from "node:fs";
import path from "node:path";

const port = Number(process.argv[2] || 8099);
// THE SITE ROOT, NOT THE PLAYGROUND FOLDER. VitePress copies `public/` to the
// root of the deployed site, so the playground lives at `/playground/` there —
// and the shell's mod registry names an absolute url under that path. Serving
// `public/playground` as `/` made those two disagree, so a local checkout could
// not test its own content set. Serving `public` makes every path here the path
// the published site has; `/` redirects to the playground for convenience.
const ROOT = path.resolve(process.argv[3] || "public");
const TYPES = { ".html": "text/html", ".js": "text/javascript", ".mjs": "text/javascript",
  ".json": "application/json", ".css": "text/css", ".bin": "application/octet-stream",
  ".ico": "image/x-icon", ".png": "image/png", ".svg": "image/svg+xml", ".wasm": "application/wasm",
  ".woff2": "font/woff2", ".nif": "text/plain", ".map": "application/json" };

http.createServer((req, res) => {
  let rel = decodeURIComponent(req.url.split("?")[0]).replace(/^\//, "");
  if (rel === "") { res.writeHead(302, { location: "/playground/" }); res.end(); return; }
  if (rel.endsWith("/")) rel += "index.html";
  const file = path.join(ROOT, rel);
  if (!file.startsWith(ROOT) || !fs.existsSync(file) || fs.statSync(file).isDirectory()) {
    res.writeHead(404, { "content-type": "text/plain" }); res.end("not here: " + rel); return;
  }
  res.writeHead(200, {
    "content-type": TYPES[path.extname(file)] || "application/octet-stream",
    "cache-control": "no-store",
  });
  fs.createReadStream(file).pipe(res);
}).listen(port, "127.0.0.1", () => console.log(`serving ${ROOT} at http://127.0.0.1:${port}/`));
