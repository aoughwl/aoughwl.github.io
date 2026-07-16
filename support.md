---
title: Become a Supporter
nav_exclude: true
permalink: /support
---

# Become a Supporter
{: .fs-9 }

Fund the work, get into the private Discord, and help steer where the AI goes next.
{: .fs-6 .fw-300 }

*aoughwl is an AI-authored, self-hosted developer platform — an open compiler toolchain today, a private product soon.*

{% assign sup = site.supporter %}

**Pay what you want.** Pick whatever monthly amount feels right — no tiers, no minimum. Give more when you can, less when you can't.
{: .fs-5 .fw-300 }

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

## What you get

- **A private Discord.** Direct line to the work — builds, decisions, and the
  roadmap, before any of it is public.
- **A real say in direction.** Supporters get to weigh in on what we build and how
  we point the AI next. Your priorities move up the list.
- **Get in early.** The full aoughwl product is coming and mostly private today.
  Supporting now is how you get in before the door opens — and how you help pay
  for the compute that builds it.

## Where the money goes — in the open

We think it's only fair to be transparent about what this brings in and who's
behind it.

<div class="support-board">
  {% assign s = site.data.support %}
  <div class="support-stat">
    <span class="support-stat-num">{{ s.monthly_total_display }}</span>
    <span class="support-stat-label">raised in {{ s.month }}</span>
  </div>
  <div class="support-stat">
    <span class="support-stat-num">{{ s.supporters_count }}</span>
    <span class="support-stat-label">supporters in {{ s.month }}</span>
  </div>
</div>

{% assign pubs = s.recent | where: "public", true %}
{% if pubs.size > 0 %}
<p class="support-recent-label">Most recent supporters</p>
<ul class="support-recent">
{% assign shown = pubs | slice: 0, s.show_recent %}
{% for p in shown %}<li><span class="support-name">{{ p.name }}</span>{% if p.tier %}<span class="support-tier">{{ p.tier }}</span>{% endif %}</li>
{% endfor %}
</ul>
<p class="support-recent-note">We only ever show the most recent supporters — never a full, scrolling roster. Supporters who'd rather stay anonymous are counted here but not named.</p>
{% else %}
<p class="support-recent-empty">No public supporters listed yet — <strong>be the first.</strong></p>
{% endif %}

## Your name, your call

When you join you choose whether your name shows up here or not. Public or
anonymous, it's entirely up to you — and either way, only the most recent
supporters are ever listed.

## The fine print

You're supporting the work and getting access to the private Discord. That's the
deal, plainly. This is **not** a purchase of the product and **not** a guarantee
of any specific feature, timeline, or outcome. We'll do our absolute best to give
supporters a genuinely good bargain and to honor the spirit of this — steering the
AI the way supporters want and getting you in early — but it's support, offered in
good faith, not a contract. Please don't take it as a binding promise.

Questions first? Reach out on [Discord]({{ sup.discord_invite }}).
