---
title: Your licence
---

# Your licence

Paste the key from your email. Nothing is stored on our side by looking it up,
and the key is kept in this browser only so you do not have to retype it.

<LicensePanel />

## Activating a machine

The download is the same archive for everybody. It becomes *yours* at
activation:

```
install\aowlspt-install.exe activate AOWL-SPT-XXXX-XXXX-XXXX-XXXX
```

That call binds the licence to this machine, and the machine gets back a signed
token plus the key that unseals the build's encrypted parts. Both are stored
next to the install. Copying an activated install to a second machine does not
carry over — the token names the machine it was issued to, and the sealed parts
will not open anywhere else.

Afterwards, no network is needed. The install re-checks itself when it happens
to be online, and the token is refreshed silently. If it stays offline past the
token's expiry it asks for one connection, not for the key again.

## Moving to a new machine

Release the old one in the table above, then activate the new one. A rebuilt
machine — new Windows install, new drive — reads as a different machine, so
release the old entry first if you are out of seats.

## Lost the key

It is in the email from the purchase. If that is gone too, message
**timbuktu_guy** on [Discord](https://discord.gg/nxa3W7w4rJ) with the email
address you paid with. We can look up the order; we cannot recover the key
itself from the database — only a hash of it is stored — so what you get is a
freshly issued key and the old one revoked.
