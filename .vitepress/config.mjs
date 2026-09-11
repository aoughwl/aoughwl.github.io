import { defineConfig } from 'vitepress'

// The aowlspt REFERENCE sidebar is generated, not written here. `tools/gendocs.py`
// in the aowlspt repo emits both the reference pages and this sidebar.json from
// the actual source -- the ABI headers, the readBoolKey call sites, the mod
// config files -- so a new header or a new mod appears in the navigation without
// anyone editing this file. Do not hand-edit it; run gendocs.py instead.
import aowlsptReference from '../docs/aowlspt/reference/sidebar.json' with { type: 'json' }

// ---------------------------------------------------------------------------
// Sidebar tree. Region headers (OVERVIEW / INTERFACE / COMPILER / EMITTERS /
// RUNTIME / TOOLS / LIBRARIES / GAMES) are top-level groups, ordered the way a program
// travels. Each stage is a link, and any stage that has sub-pages is a
// { collapsed: true, link, items } group — click the label to open the page,
// click the chevron to expand. Adding a child page to ANY stage is a one-liner:
// give it an `items: [...]` array and it becomes collapsible.
// ---------------------------------------------------------------------------
const sidebar = [
  {
    text: 'OVERVIEW',
    items: [
      { text: 'Welcome', link: '/' },
      { text: 'Parity', link: '/docs/parity' },
      { text: 'Daily Changelog', link: 'https://github.com/aoughwl#daily-blog' },
    ],
  },
  {
    text: 'INTERFACE',
    items: [
      { text: 'Manager — aowlup', link: '/docs/aowlup' },
      { text: 'Driver — aowlmony', link: '/docs/aowlmony' },
      { text: 'Store — aowlcas', link: '/docs/aowlcas' },
    ],
  },
  {
    text: 'COMPILER',
    items: [
      {
        text: 'The AIF format',
        link: '/docs/aif',
        collapsed: true,
        items: [
          { text: 'AIF CLI — aiflens', link: '/docs/aiflens' },
        ],
      },
      {
        text: 'Parser — aowlparser',
        link: '/docs/aowlparser',
        collapsed: true,
        items: [
          { text: 'Architecture', link: '/docs/aowlparser/architecture' },
          { text: 'Grammar coverage', link: '/docs/aowlparser/grammar' },
          { text: 'Dialects', link: '/docs/aowlparser/dialects' },
          { text: 'JSON reader', link: '/docs/aowlparser/json-reader' },
          { text: 'Differential testing', link: '/docs/aowlparser/testing' },
          { text: 'Configuration', link: '/docs/aowlparser/configuration' },
          { text: 'Parity & gaps', link: '/docs/aowlparser/known-gaps' },
          { text: 'The .p.aif format', link: '/docs/aowlparser/output-format' },
          { text: 'Browser & JavaScript', link: '/docs/aowlparser/browser' },
        ],
      },
      {
        text: 'Sem — aowlsem',
        link: '/docs/aowlsem',
        collapsed: true,
        items: [
          { text: 'Architecture', link: '/docs/aowlsem/architecture' },
          { text: 'Diagnostics', link: '/docs/aowlsem/diagnostics' },
          { text: 'CLI & API', link: '/docs/aowlsem/cli' },
          { text: 'Lowering reference', link: '/docs/aowlsem/lowering' },
        ],
      },
      { text: 'Hexer — aowlhexer', link: '/docs/aowlhexer' },
      { text: 'High-Level IR — aowlhl', link: '/docs/aowlhl' },
    ],
  },
  {
    text: 'EMITTERS',
    items: [
      { text: 'C — aowlc', link: '/docs/aowlc' },
      { text: 'Native JS — aowljs', link: '/docs/aowljs' },
      {
        text: 'Faithful JS/WASM — aowlweb',
        link: '/docs/aowlweb',
        collapsed: true,
        items: [
          { text: 'Getting started', link: '/docs/aowlweb/getting-started' },
          { text: 'Capabilities', link: '/docs/aowlweb/capabilities' },
          { text: 'Architecture', link: '/docs/aowlweb/architecture' },
          { text: 'JavaScript FFI & DOM', link: '/docs/aowlweb/js-ffi' },
          { text: 'Async runtime', link: '/docs/aowlweb/async' },
          { text: 'Roadmap', link: '/docs/aowlweb/roadmap' },
        ],
      },
      { text: 'TypeScript — aowlts', link: '/docs/aowlts' },
      { text: 'Python — aowlpy', link: '/docs/aowlpy' },
    ],
  },
  {
    text: 'RUNTIME',
    items: [
      {
        text: 'Interpreter — aowli',
        link: '/aowli',
        collapsed: true,
        items: [
          { text: 'Engines', link: '/aowli/engines' },
          { text: 'Debugging', link: '/aowli/debugging' },
          { text: 'Debugging a real bug', link: '/aowli/debugging-a-real-bug' },
          { text: 'aowli-release (prebuilt binaries)', link: '/docs/aowli-release' },
          { text: 'Get a licence — $9.99/mo', link: '/store/aowli' },
        ],
      },
      { text: 'Runtime — aowlrt', link: '/docs/aowlrt' },
      { text: 'Plugin host — aowlhost', link: '/docs/aowlhost' },
      { text: 'Value layout & ABI — aowlabi', link: '/docs/aowlabi' },
    ],
  },
  {
    text: 'TOOLS',
    items: [
      { text: 'Playground', link: 'https://aoughwl.github.io/playground/', target: '_self' },
      { text: 'LSP — aowllsp', link: '/docs/aowllsp' },
      {
        text: 'Suggestions — aowlsuggest',
        link: '/docs/aowlsuggest',
        collapsed: true,
        items: [
          { text: 'The contract', link: '/docs/aowlsuggest/the-contract' },
          { text: 'Commands', link: '/docs/aowlsuggest/commands' },
          { text: 'Quick-fixes', link: '/docs/aowlsuggest/fixes' },
          { text: 'Editor integration', link: '/docs/aowlsuggest/editor-integration' },
          { text: 'Testing', link: '/docs/aowlsuggest/testing' },
        ],
      },
      { text: 'Formatter — aowlfmt', link: '/docs/aowlfmt' },
      { text: 'Test runner — aowltest', link: '/docs/aowltest' },
      {
        text: 'Claude Code — aowlcode',
        link: '/docs/aowlcode',
        collapsed: true,
        items: [
          { text: 'Aowl mode (default-on)', link: '/docs/aowlcode/aowl-mode' },
          { text: 'Tools', link: '/docs/aowlcode/tools' },
          { text: 'Commands', link: '/docs/aowlcode/commands' },
          { text: 'Agents', link: '/docs/aowlcode/agents' },
          { text: 'Execution', link: '/docs/aowlcode/execution' },
          { text: 'Internals', link: '/docs/aowlcode/internals' },
          { text: 'Token budget', link: '/docs/aowlcode/token-budget' },
          { text: 'Fleet (phone control)', link: '/docs/aowlcode/fleet' },
        ],
      },
      { text: 'Obfuscator — obfuscate', link: '/docs/obfuscate' },
    ],
  },
  {
    text: 'LIBRARIES',
    items: [
      {
        text: 'net stack',
        link: '/docs/net-stack',
        collapsed: true,
        items: [
          { text: 'tcp', link: '/docs/net-stack/tcp' },
          { text: 'net', link: '/docs/net-stack/net' },
          { text: 'tls', link: '/docs/net-stack/tls' },
          { text: 'http', link: '/docs/net-stack/http' },
          { text: 'compress', link: '/docs/net-stack/compress' },
          { text: 'serve', link: '/docs/net-stack/serve' },
          { text: 'reactor (async)', link: '/docs/net-stack/reactor' },
          { text: 'ws', link: '/docs/net-stack/ws' },
          { text: 'requests', link: '/docs/net-stack/requests' },
        ],
      },
      {
        text: 'web stack',
        collapsed: true,
        items: [
          { text: 'web', link: '/docs/web' },
          { text: 'html', link: '/docs/html' },
          { text: 'css', link: '/docs/css' },
        ],
      },
      {
        text: 'LLM stack',
        link: '/docs/llm-stack',
        collapsed: true,
        items: [
          { text: 'anthropic', link: '/docs/llm-stack/anthropic' },
          { text: 'openai', link: '/docs/llm-stack/openai' },
        ],
      },
      { text: 'JSON — aowljson', link: '/docs/aowljson' },
      { text: 'MCP servers — aowlmcp', link: '/docs/aowlmcp' },
      { text: 'Discord bots — discord', link: '/docs/discord' },
    ],
  },
  {
    text: 'GAMES',
    items: [
      {
        text: 'Modding engine — Jester',
        link: '/jester',
        collapsed: true,
        items: [
          { text: 'Overview, and the live demo', link: '/jester' },
          { text: 'Documentation', link: '/docs/jester' },
          { text: 'Getting started', link: '/docs/jester/getting-started' },
          { text: 'The mod API', link: '/docs/jester/mod-api' },
          { text: 'Catalogs', link: '/docs/jester/catalogs' },
          { text: 'The UI library', link: '/docs/jester/ui' },
          { text: 'Importers', link: '/docs/jester/importers' },
          { text: 'Networking', link: '/docs/jester/networking' },
          { text: 'The host surface', link: '/docs/jester/host-surface' },
          { text: 'The browser build’s memory', link: '/docs/jester/browser-memory' },
        ],
      },
      {
        text: 'Tarkov modding — aowlspt (deprecated)',
        link: '/docs/aowlspt',
        collapsed: true,
        items: [
          { text: 'Installation', link: '/docs/aowlspt/installation' },
          { text: 'Getting started', link: '/docs/aowlspt/getting-started' },
          { text: 'Features', link: '/docs/aowlspt/features' },
          { text: 'Mods', link: '/docs/aowlspt/mods' },
          { text: 'Bot AI', link: '/docs/aowlspt/bot-ai' },
          { text: 'Configuration', link: '/docs/aowlspt/configuration' },
          { text: 'Automation', link: '/docs/aowlspt/automation' },
          { text: 'Troubleshooting', link: '/docs/aowlspt/troubleshooting' },
          { text: 'FAQ', link: '/docs/aowlspt/faq' },
          {
            text: 'Reference (generated)',
            link: '/docs/aowlspt/reference/',
            collapsed: true,
            items: aowlsptReference,
          },
          {
            text: 'For mod developers',
            link: '/docs/aowlspt/for-mod-developers',
            collapsed: true,
            items: [
              { text: 'The mod API', link: '/docs/aowlspt/api' },
              { text: 'The C ABI', link: '/docs/aowlspt/abi' },
            ],
          },
          {
            text: 'Under the hood',
            link: '/docs/aowlspt/architecture',
            collapsed: true,
            items: [
              { text: 'Architecture', link: '/docs/aowlspt/architecture' },
              { text: 'Reaching into IL2CPP', link: '/docs/aowlspt/il2cpp' },
              { text: 'The game server', link: '/docs/aowlspt/emulator' },
              { text: 'How we know things — the method', link: '/docs/aowlspt/method' },
              { text: 'Traps and hard-won facts', link: '/docs/aowlspt/pitfalls' },
              { text: 'The engineering record', link: '/docs/aowlspt/engineering-record' },
              { text: 'Case study — nimony at scale', link: '/docs/aowlspt/case-study' },
            ],
          },
          {
            text: "The manual — the repository's own documents",
            link: '/docs/aowlspt/manual/',
            collapsed: true,
            items: [
              {
                text: 'The system',
                collapsed: true,
                items: [
                  { text: 'The shape of aowlspt', link: '/docs/aowlspt/manual/architecture' },
                  { text: 'The C ABI', link: '/docs/aowlspt/manual/abi' },
                  { text: 'The wire format', link: '/docs/aowlspt/manual/wire' },
                  { text: 'Mod-to-mod capabilities', link: '/docs/aowlspt/manual/capabilities' },
                  { text: 'Three gaps in the mod API', link: '/docs/aowlspt/manual/api-gaps' },
                ],
              },
              {
                text: 'The client host — IL2CPP',
                collapsed: true,
                items: [
                  { text: 'The post-1.0 client host', link: '/docs/aowlspt/manual/il2cpp' },
                  { text: 'Decrypting global-metadata.dat', link: '/docs/aowlspt/manual/metadata-decrypt' },
                  { text: 'The interaction layer', link: '/docs/aowlspt/manual/interaction-layer-map' },
                  { text: 'The client boot flow', link: '/docs/aowlspt/manual/boot-flow-map' },
                  { text: 'Getting past character-select', link: '/docs/aowlspt/manual/autoenter' },
                  { text: 'Actuating the local player', link: '/docs/aowlspt/manual/player-actuation' },
                  { text: 'Starting an offline raid natively', link: '/docs/aowlspt/manual/native-raid-start' },
                  { text: 'Native menu-screen navigation', link: '/docs/aowlspt/manual/native-screen-nav' },
                ],
              },
              {
                text: 'Offline recon — RVA and screen maps',
                collapsed: true,
                items: [
                  { text: 'The main-menu UI map', link: '/docs/aowlspt/manual/ui-map' },
                  { text: 'The settings screen map', link: '/docs/aowlspt/manual/settings-ui-map' },
                  { text: 'The auto-raid flows', link: '/docs/aowlspt/manual/autoraid-map' },
                  { text: 'The reload / magazine-load path', link: '/docs/aowlspt/manual/ammo-loading-map' },
                  { text: 'The post-processing map', link: '/docs/aowlspt/manual/native-postfx-map' },
                  { text: 'FOV — static RVAs', link: '/docs/aowlspt/manual/fov-rva' },
                  { text: 'SAIN driver — the RVA table', link: '/docs/aowlspt/manual/sain-rva' },
                  { text: 'Voice — offline IL2CPP archaeology', link: '/docs/aowlspt/manual/voice-rva' },
                  { text: 'The audio path, resolved offline', link: '/docs/aowlspt/manual/audioray-rva' },
                ],
              },
              {
                text: 'The backend and the emulator',
                collapsed: true,
                items: [
                  { text: 'The backend', link: '/docs/aowlspt/manual/backend' },
                  { text: 'The emulator', link: '/docs/aowlspt/manual/emulator' },
                  { text: 'Emulator coverage', link: '/docs/aowlspt/manual/emulator-coverage' },
                  { text: 'Every refusal, re-audited', link: '/docs/aowlspt/manual/emulator-refusals' },
                  { text: 'Importing a real database', link: '/docs/aowlspt/manual/importdb' },
                  { text: 'The pre-1.0 database against post-1.0', link: '/docs/aowlspt/manual/post1-data-delta' },
                  { text: 'Loot configuration', link: '/docs/aowlspt/manual/loot-config' },
                  { text: 'The backend, made fast', link: '/docs/aowlspt/manual/perf-server' },
                ],
              },
              {
                text: 'Writing mods',
                collapsed: true,
                items: [
                  { text: 'Writing a mod', link: '/docs/aowlspt/manual/modding' },
                  { text: 'Getting a new mod to stay loaded', link: '/docs/aowlspt/manual/mod-enable-path' },
                  { text: 'Changing the mod set while everything runs', link: '/docs/aowlspt/manual/modmanager' },
                  { text: 'Mod Settings API — design', link: '/docs/aowlspt/manual/mod-settings-api' },
                  { text: 'What a mod may do on the load path', link: '/docs/aowlspt/manual/mod-perf' },
                  { text: 'What a client-side call costs', link: '/docs/aowlspt/manual/perf' },
                  { text: 'Debugging a native mod', link: '/docs/aowlspt/manual/debugging' },
                  { text: 'The in-game debug overlay', link: '/docs/aowlspt/manual/debug-overlay' },
                ],
              },
              {
                text: 'UI and settings',
                collapsed: true,
                items: [
                  { text: 'In-game settings and the config schema', link: '/docs/aowlspt/manual/settings' },
                  { text: 'The settings UI API', link: '/docs/aowlspt/manual/ui-api' },
                  { text: 'UIHOOKS — subscribe to a screen', link: '/docs/aowlspt/manual/uihooks' },
                  { text: 'Native Unity UI from a mod', link: '/docs/aowlspt/manual/native-ui' },
                  { text: 'nativetabs — one declarative call', link: '/docs/aowlspt/manual/nativetabs' },
                  { text: 'Native settings controls', link: '/docs/aowlspt/manual/native-controls' },
                  { text: 'Shelved: native in-game settings', link: '/docs/aowlspt/manual/shelved-native-settings' },
                ],
              },
              {
                text: 'Bots',
                collapsed: true,
                items: [
                  { text: 'Bot navigation — IL2CPP recon', link: '/docs/aowlspt/manual/botnav' },
                  { text: 'SPT 4.1.5 bot control', link: '/docs/aowlspt/manual/spt415-bot-control' },
                  { text: 'Squad-shared objectives', link: '/docs/aowlspt/manual/bot-ai-objectives' },
                ],
              },
              {
                text: 'Automation and the inspector',
                collapsed: true,
                items: [
                  { text: 'The automation library', link: '/docs/aowlspt/manual/automation-library' },
                  { text: 'The automation library — API reference', link: '/docs/aowlspt/manual/automation-api' },
                  { text: 'The live inspector — verb reference', link: '/docs/aowlspt/manual/inspector-verbs' },
                  { text: 'The live inspector as a product', link: '/docs/aowlspt/manual/inspector-product' },
                  { text: 'Headless and unattended running', link: '/docs/aowlspt/manual/headless' },
                ],
              },
              {
                text: 'Graphics and content',
                collapsed: true,
                items: [
                  { text: 'DLSS on this install', link: '/docs/aowlspt/manual/dlss' },
                  { text: 'DLSS-NR on this install', link: '/docs/aowlspt/manual/dlssnr' },
                  { text: 'Ripping and re-importing the maps', link: '/docs/aowlspt/manual/map-rip-and-reimport' },
                  { text: 'Importing all maps into one Unity scene', link: '/docs/aowlspt/manual/unity-map-import' },
                  { text: 'Port plan — ammo loading animations', link: '/docs/aowlspt/manual/port-ammo-loading-animations' },
                ],
              },
              {
                text: 'Shipping it',
                collapsed: true,
                items: [
                  { text: 'Installing', link: '/docs/aowlspt/manual/install' },
                  { text: 'Distribution — the final build', link: '/docs/aowlspt/manual/distribution' },
                  { text: 'Beta distribution and IP protection', link: '/docs/aowlspt/manual/beta-distribution' },
                  { text: '1.0 release readiness', link: '/docs/aowlspt/manual/release-readiness' },
                ],
              },
              {
                text: 'The record',
                collapsed: true,
                items: [
                  { text: 'Backlog — everything not done', link: '/docs/aowlspt/manual/backlog' },
                ],
              },
            ],
          },
          { text: 'Get a licence — $19.99/mo', link: '/store/aowlspt' },
        ],
      },
    ],
  },
  {
    text: 'STORE',
    items: [
      { text: 'What is for sale', link: '/store/' },
      { text: 'aowlspt — $19.99/mo', link: '/store/aowlspt' },
      { text: 'aowli — $9.99/mo', link: '/store/aowli' },
      { text: 'Your licence', link: '/store/license' },
    ],
  },
  {
    text: 'DEPRECATED',
    items: [
      { text: 'nimony-lsp (Nim 2) — nim2-nimony-lsp', link: '/docs/nim2-nimony-lsp' },
    ],
  },
]

export default defineConfig({
  title: 'aoughwl',
  description:
    'A ground-up, self-hosted reimplementation of the Nimony toolchain — parser, semantic checker, lowering, and code generators — open at every seam and running in your browser.',
  lang: 'en-US',
  cleanUrls: true,
  // Follow the OS/browser setting (iOS + macOS dark mode, Windows, Android) on
  // first visit; the toggle still wins and is remembered after that.
  appearance: true,
  ignoreDeadLinks: true,
  lastUpdated: false,

  // Not in the sidebar — internal engineering notes / raw README dumps that
  // contain unescaped angle brackets. Kept in-repo, out of the build.
  srcExclude: [
    'README.md',
    'changes/**',
    'docs/reference/**',
    'engineering-notes.md',
    'nimony.md',
    'projects.md',
    'reference.md',
    'support.md',
    'thanks.md',
    'playground.md',
    'docs/nimony-fork.md',
    'docs/tooling-stack.md',
  ],

  head: [
    // --- Favicons: ICO for legacy, crisp PNGs for modern browsers ---
    ['link', { rel: 'icon', href: '/favicon.ico', sizes: 'any' }],
    ['link', { rel: 'icon', type: 'image/png', sizes: '32x32', href: '/favicon-32.png' }],
    ['link', { rel: 'icon', type: 'image/png', sizes: '16x16', href: '/favicon-16.png' }],
    // --- iOS home-screen icon (fixes the fallback "A") + PWA manifest ---
    ['link', { rel: 'apple-touch-icon', sizes: '180x180', href: '/apple-touch-icon.png' }],
    ['link', { rel: 'manifest', href: '/site.webmanifest' }],
    ['meta', { name: 'apple-mobile-web-app-title', content: 'aoughwl' }],
    ['meta', { name: 'application-name', content: 'aoughwl' }],
    // Browser/OS chrome colour follows the system theme, so iOS Safari's status
    // bar and address bar match the page instead of always going near-black.
    ['meta', { name: 'theme-color', media: '(prefers-color-scheme: light)', content: '#ffffff' }],
    ['meta', { name: 'theme-color', media: '(prefers-color-scheme: dark)', content: '#0a0a0b' }],
    ['meta', { name: 'color-scheme', content: 'light dark' }],
    ['meta', { name: 'apple-mobile-web-app-capable', content: 'yes' }],
    ['meta', { name: 'apple-mobile-web-app-status-bar-style', content: 'black-translucent' }],
    // --- Open Graph / Twitter (link previews on Discord, Slack, X, iMessage) ---
    ['meta', { property: 'og:type', content: 'website' }],
    ['meta', { property: 'og:site_name', content: 'aoughwl' }],
    ['meta', { property: 'og:title', content: 'aoughwl' }],
    ['meta', { property: 'og:description', content: 'A self-hosted reimplementation of the Nimony toolchain — open at every seam, running in your browser.' }],
    ['meta', { property: 'og:url', content: 'https://aoughwl.com/' }],
    ['meta', { property: 'og:image', content: 'https://aoughwl.com/og-image.png' }],
    ['meta', { property: 'og:image:width', content: '1200' }],
    ['meta', { property: 'og:image:height', content: '630' }],
    ['meta', { name: 'twitter:card', content: 'summary_large_image' }],
    ['meta', { name: 'twitter:title', content: 'aoughwl' }],
    ['meta', { name: 'twitter:description', content: 'A self-hosted reimplementation of the Nimony toolchain — open at every seam, running in your browser.' }],
    ['meta', { name: 'twitter:image', content: 'https://aoughwl.com/og-image.png' }],
    // Apply the saved sidebar width/offset BEFORE first paint (no flash), and
    // stamp `aowl-boot` for the one-time entrance animation.
    ['script', {}, `(function(){try{var r=document.documentElement;
      var w=parseInt(localStorage.getItem('aowl-sb-width'));if(w>=220&&w<=520)r.style.setProperty('--vp-sidebar-width',w+'px');
      var x=parseInt(localStorage.getItem('aowl-sb-x'));if(x>=-1400&&x<=400)r.style.setProperty('--aowl-sb-x',x+'px');
      var p=parseInt(localStorage.getItem('aowl-pad'));r.style.setProperty('--aowl-pad',(p>=8&&p<=400?p:32)+'px');
      r.classList.add('aowl-boot');}catch(e){}})();`],
  ],

  themeConfig: {
    // logo already spells "aoughwl"; the label beside it reads "docs" (light/dark pair)
    logo: {
      light: '/assets/aoughwl-logo-black.png',
      dark: '/assets/aoughwl-logo-white.png',
    },
    siteTitle: 'docs',

    // Top-nav links (Playground on the left; GitHub · Discord · Support on the
    // right) are all rendered with icons via the nav slots in theme/index.js.
    sidebar,

    search: { provider: 'local' },

    outline: { level: [2, 3], label: 'On this page' },

    docFooter: { prev: 'Previous', next: 'Next' },

    footer: {
      message:
        'aoughwl — self-hosted platform for things n stuff. <a href="https://discord.gg/nxa3W7w4rJ" target="_blank" rel="noopener">Contact / Support</a> on Discord for access to the private backends.',
      copyright: '© aoughwl',
    },
  },
})
