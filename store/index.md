---
title: Store
---

# Store

Most of aoughwl is a compiler toolchain, and it is free and open. A few things
built *with* it are products, and those are sold here — one payment, a licence
key, and the build.

<StoreGrid />

## How a licence works

The same scheme for everything on this page, so there is only one thing to
learn:

- **You get a key** — `AOWL-XXX-…` — by email and on screen the moment the
  payment clears. It is the only credential; there is no account and no
  password.
- **The key activates machines.** Each product says how many. Activation binds
  the build to that machine and hands it a signed licence token, after which the
  machine works with no network at all.
- **A machine can be released** from [your licence page](/store/license), which
  frees the seat for another one. Reinstalling on the same machine does not cost
  a seat.
- **Updates are included** for the licence's lifetime, at the same key.

Payment is handled by Stripe. We never see a card number, and the licence
database stores a hash of your key rather than the key itself — a breach on our
side does not hand anybody a working licence.

## Refunds

Ask, within 14 days, on [Discord](https://discord.gg/nxa3W7w4rJ), and you get
your money back. A refund revokes the key; the build stops working when the
token on each machine next expires.

## Not for sale

The compiler, the interpreter, the parser, the emitters, the playground and
every library documented on this site stay free. If you want to support that
work rather than buy something, there is a [support link](https://donate.stripe.com/3cI6oH1eJ74w9L1e3ueAg00)
in the nav.
