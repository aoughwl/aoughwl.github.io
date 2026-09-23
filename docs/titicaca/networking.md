---
title: Titicaca networking, storage and security
description: How Titicaca fetches pages, caches them, keeps cookies, parses URLs and limits what a page may do.
---

# Networking, storage and security

## Fetching

The mod does not own a socket. It asks the host to fetch a URL and gets bytes
back, through the same [host surface](/docs/jester/host-surface) any mod uses,
so a mod cannot reach the network unless the host lets it.

## URLs

`weburl` implements the WHATWG URL parser, including special-scheme handling,
percent-encoding sets, IPv4 and IPv6 hosts, and the setter algorithms behind
`URL.searchParams`, `location` and `<a>` elements. `webidna` supplies the UTS 46
processing that turns internationalised host names into their ASCII form. The
URL and setters test data are run by dedicated runner modes.

## Cache and cookies

`webcache` stores responses by URL and honours the usual validators.
`webcookie` implements the cookie jar: domain and path matching, `Secure`,
`HttpOnly`, `SameSite` and expiry.

## Forms

`webform` handles form submission and encoding: `application/x-www-form-urlencoded`,
`multipart/form-data` and `text/plain`, driven by the standard's activation
behaviour.

## What a page may do

A page runs inside the engine's realm and can touch only what the DOM binding
exposes. There is no file access, no process access and no route to other mods.
Anything else it wants goes through the host, which can refuse it.

## Not yet

`fetch`, `Request` and `Response` are incomplete, and there is no service-worker,
WebSocket or WebRTC support. Do not treat this browser as a hardened one; see
[Limits and roadmap](/docs/titicaca/limits).
