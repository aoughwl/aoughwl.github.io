---
repo: aoughwl/ovh
---

# aowlcloud — OVH VPS + a declared cloud on top

`aowlcloud` (repo `aoughwl/ovh`) orders OVH VPS, then runs exactly what you
declare on them: machines, a private WireGuard mesh, firewall, services, TLS
ingress, and pools of isolated per-session containers (e.g. one browser per
session, each with its own network and egress IP). One spec file describes the
whole cloud, and one binary manages it.

```sh
aowlcloud up examples/website.json --confirm
```

::: warning Not yet tested live
It has **never been run against a real OVH account**: no real order, and no
Docker/WireGuard on a live node. What *is* tested is listed under
[Tests](#tests). The first `up` should be watched, on a cheap VPS.
:::

[[toc]]

---

## Two halves

**A. OVH lifecycle** (`ovh.nim`, `vps.nim`): a signed API client, the VPS
catalog, cart ordering, order tracking, rebuild, rescue mode, reboot, console
and termination.

**B. What runs on the machines** (`spec.nim`, `render.nim`, `remote.nim`,
`node/`): a pure renderer turns the spec into per-node files, and SSH pushes
them with a **dead-man rollback**.

---

## Safety rules

| Risk | What stops it |
|---|---|
| Buying by accident | `order` is a dry run that builds a real cart and prices it; `--confirm` is required to check out, and `ovh.maxMonthly` caps the whole cluster. |
| Buying twice | A node with a pending order is never ordered again. |
| Wiping a machine | `rebuild`/`terminate` need the VPS name typed back (`--yes-i-mean NAME`). |
| Locking yourself out | Every apply arms a timer on the node before anything goes live. The controller must reconnect over a new SSH session and confirm, or the node restores its last confirmed config. One unconfirmed node halts the rollout. |
| A typo opening a port | Unknown spec keys are errors; SSH sources must be listed explicitly; Docker-published ports are fenced in FORWARD. |
| Firewall syntax error | `nft -c` validates on the node before the timer is armed. |
| Secrets leaking | Secrets travel over SSH into 0600 env files and never appear in the spec, user-data or plan output. The WireGuard private key never leaves its node. |
| Clobbering Docker's firewall | aowlcloud owns only `table inet aowl` and `table ip aowlnat`; it never flushes the ruleset. |

Every money/destroy/apply action is appended to `~/.aowlcloud/audit.log`.

---

## The spec

One JSON file declares `ovh` (plan, datacenter, OS, `maxMonthly`), `access`,
`mesh`, `nodes` (ordered from OVH, or an existing Linux box adopted by `host`),
`ingress` (Caddy, automatic TLS), raw nft `firewall` rules, and `services`
(`image` or `build`, `on`, `port`, `routes`, `public`, `env`, `secrets`,
`volumes`, `pool`, ...).

- **Pools**: each session is its own systemd instance with its own Docker
  bridge and volumes, optional SNAT to one of the node's extra IPs, and can
  reach the internet only — not the host, the mesh or other sessions.
- **Elastic groups**: hourly Public Cloud instances, capped by `maxHourly`.
  `scale` sets a member count; `autoscale` follows a demand command, growing at
  once and shrinking after `scaleDownAfter`.

Day-to-day commands: `plan`, `apply`, `status`, `logs`, `ssh`, `rollback`.

---

## Build

```sh
git clone https://github.com/aoughwl/ovh
cd ovh
nim c -o:bin/aowlcloud.exe src/aowlcloud.nim   # Nim 2.2, no packages
```

---

## Tests

- `nim c -r tests/tall.nim` — signing, spec validation, rendering, tar format.
- `nim c -r --threads:on tests/tovh.nim` — the cart sequence and money/destroy
  guards against a **mock** OVH.
- `tests/node_harness.sh` — real kernel nftables, `systemd-analyze verify`,
  pool wrappers and the full apply/confirm/rollback state machine, inside a
  private mount+net namespace.

## Limits

- VPS has no nested virtualisation: a session gets its own container and
  namespaces, not its own kernel.
- Extra egress IPs must be ordered and routed in OVH first.
- IPv6 is dropped except SSH from listed v6 sources.
