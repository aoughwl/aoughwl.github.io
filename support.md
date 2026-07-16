---
title: Become a Supporter
nav_exclude: true
permalink: /support
---

# Become a Supporter
{: .fs-9 }

A monthly contribution funds aoughwl's continued development and gives you access to the private Discord and a direct voice in what gets built.
{: .fs-6 .fw-300 }

*aoughwl is an AI-authored, self-hosted developer platform — an open compiler toolchain today, a private product soon.*

{% assign sup = site.supporter %}

Contribute any amount you choose each month. There are no fixed tiers.

{% assign has_primary = false %}{% if sup.stripe_url and sup.stripe_url != "" %}{% assign has_primary = true %}{% endif %}
{% assign has_presets = false %}{% if sup.amounts and sup.amounts.size > 0 %}{% assign has_presets = true %}{% endif %}
{% assign show_btns = false %}{% if sup.enabled %}{% if has_primary or has_presets %}{% assign show_btns = true %}{% endif %}{% endif %}
{% if show_btns %}
{% if has_primary %}<a class="support-btn" href="{{ sup.stripe_url }}" target="_blank" rel="noopener">Choose your amount →</a>{% endif %}
{% if has_presets %}
<div class="support-amounts">
{% for a in sup.amounts %}<a class="support-amount" href="{{ a.url }}" target="_blank" rel="noopener">{{ a.label }}</a>
{% endfor %}</div>
{% endif %}
{% else %}
<span class="support-btn support-btn--soon" role="note" aria-disabled="true">Opening soon</span>
{% endif %}

---

## What your support includes

- **Private Discord.** Access to development builds, the roadmap, and decisions
  before they are public.
- **Influence on direction.** Supporters help set priorities — what gets built,
  and how the AI is directed.
- **Early access.** The full aoughwl product is largely private today. Supporting
  now secures your place as it opens up, and helps fund the compute that builds it.

## Transparency

We publish what the program brings in each month, and who is behind it.

<div class="support-board">
  {% assign s = site.data.support %}
  <div class="support-stat">
    <span class="support-stat-num">{{ s.monthly_total_display }}</span>
    <span class="support-stat-label">contributed in {{ s.month }}</span>
  </div>
  <div class="support-stat">
    <span class="support-stat-num">{{ s.supporters_count }}</span>
    <span class="support-stat-label">supporters in {{ s.month }}</span>
  </div>
</div>

{% assign pubs = s.recent | where: "public", true %}
{% if pubs.size > 0 %}
<p class="support-recent-label">Recent supporters</p>
<ul class="support-recent">
{% assign shown = pubs | slice: 0, s.show_recent %}
{% for p in shown %}<li><span class="support-name">{{ p.name }}</span>{% if p.tier %}<span class="support-tier">{{ p.tier }}</span>{% endif %}</li>
{% endfor %}
</ul>
<p class="support-recent-note">Only the most recent supporters are listed. Supporters who prefer to remain anonymous are counted but not named.</p>
{% else %}
<p class="support-recent-empty">No supporters are listed yet.</p>
{% endif %}

## Privacy

The name shown on the board is taken automatically from what you enter at Stripe
checkout. If you'd rather stay anonymous, simply don't enter your name there —
leave it off or use an alias, and that is what we'll use. Only the most recent
supporters are listed.

## Terms

Support is offered in good faith. It is not a purchase of the product and not a
guarantee of any specific feature, timeline, or outcome.

Questions? Reach out on [Discord]({{ sup.discord_invite }}).
