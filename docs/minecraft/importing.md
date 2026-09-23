---
title: Importing your Minecraft install
description: How the Jester Minecraft client reads assets from a game you own, without shipping any of them.
---

# Importing your game

The client distributes no Minecraft content. The importer reads a game install
that already exists on your machine and publishes what it finds into Jester's
catalogs at run time.

## What is read

- **Blockstates** describing which model applies to a block in a given state.
- **Block models** and their textures, including inheritance between models.
- **Recipes**, for crafting.
- **Sounds and language data**, for audio and text.

A full import is on the order of a thousand blockstates, a couple of thousand
block models and about fifteen hundred recipes.

## When it runs

Import happens behind the menu. The title screen is exactly where a player waits
for it, so the block registry must be filled while the menu is up. Reading is
unbudgeted there because nothing repaints behind a menu anyway.

## Server names

A server identifies blocks by name. The importer supplies the list of names (a
little over eleven hundred) a few seconds into a session, and the join has to wait
for it. See [Joining a server](/docs/minecraft/joining-a-server).

## Nothing leaves your machine

Imported data lives in your local Jester data, not in a mod you would share. If
you build a player, keep imported assets out of it: a build that follows a link
to an import folder can bundle gigabytes of content that must never be
distributed.
