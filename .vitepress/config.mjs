import { defineConfig } from 'vitepress'

// ---------------------------------------------------------------------------
// Sidebar tree. Region headers (OVERVIEW / PIPELINE / EMITTERS / ECOSYSTEM) are
// top-level groups; each stage is a link, and any stage that has sub-pages is a
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
    ],
  },
  {
    text: 'INTERFACE',
    items: [
      { text: 'Manager — aowlup', link: '/docs/aowlup' },
      { text: 'Driver — aowlmony', link: '/docs/aowlmony' },
    ],
  },
  {
    text: 'COMPILER',
    items: [
      {
        text: 'Parser — aowlparser',
        link: '/docs/aowlparser',
        collapsed: true,
        items: [
          { text: 'Architecture', link: '/docs/aowlparser/architecture' },
          { text: 'Grammar coverage', link: '/docs/aowlparser/grammar' },
          { text: 'Differential testing', link: '/docs/aowlparser/testing' },
          { text: 'Configuration', link: '/docs/aowlparser/configuration' },
          { text: 'Parity & gaps', link: '/docs/aowlparser/known-gaps' },
          { text: 'The .p.aif format', link: '/docs/aowlparser/output-format' },
          { text: 'Browser & JavaScript', link: '/docs/aowlparser/browser' },
        ],
      },
      { text: 'Sem — aowlsem', link: '/docs/aowlsem' },
      { text: 'Hexer — aowlhexer', link: '/docs/aowlhexer' },
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
          { text: 'aowli-release (public binaries)', link: '/docs/aowli-release' },
        ],
      },
      {
        text: 'Runtime — aowllib',
        link: '/docs/aowllib',
        collapsed: true,
        items: [
          { text: 'Overview', link: '/docs/aowllib' },
        ],
      },
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
      { text: 'Claude Code — aowlcode', link: '/docs/aowlcode' },
      { text: 'AIF CLI — aiflens', link: '/docs/aiflens' },
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
  appearance: 'dark', // default dark, but the theme toggle stays available
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
    ['link', { rel: 'icon', href: '/favicon.ico' }],
    ['meta', { name: 'theme-color', content: '#0a0a0b' }],
    ['meta', { property: 'og:type', content: 'website' }],
    ['meta', { property: 'og:title', content: 'aoughwl' }],
    ['meta', { property: 'og:description', content: 'A self-hosted reimplementation of the Nimony toolchain — open at every seam, running in your browser.' }],
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
