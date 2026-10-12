<div align="center">

<img src="https://github.com/AbyssWM.png?size=200" width="160" alt="Abyss logo">

# AbyssPolkit

**AbyssPolkit – polkit authentication agent for Abyssland, fork of hyprpolkitagent (BSD-3, © hyprwm)**

Part of [**Abyss**](https://github.com/AbyssWM) · Based on [hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent) by [hyprwm](https://github.com/hyprwm)

</div>

---

> [!NOTE]
> **Name not final.** "AbyssPolkit" is a working name and may change.

> [!WARNING]
> **Early development.** Abyss is being rebranded and reworked right now. Nothing is ready for daily use yet.

## Install

Builds against the Abyss libraries in `/opt/abyss` (Abyssutils, Abysstoolkit, Abyssgraphics, Abyssparse). Needs `sdbus-c++`, `pixman`, `libdrm` and a polkit install with `polkit-agent-helper-1`. From the Abyss workspace:

```sh
sh tools/build.sh AbyssPolkit
```

This installs the `abyss-polkit-agent` binary (libexec), a systemd user unit and the D-Bus service `org.abyssland.AbyssPolkitAgent` to `/opt/abyss`. Only one polkit agent may be registered per session.

A simple polkit authentication agent for Abyssland, written in C++ with [abysstoolkit](https://github.com/AbyssWM/abysstoolkit).

![](./assets/polkit.png)

## Usage

See [the abyssland wiki](https://github.com/AbyssWM/Abyssland).

## Configuration

abyss-polkit-agent reads `~/.config/abyss-polkit-agent/abyss-polkit-agent.conf` (or `$XDG_CONFIG_HOME/abyss-polkit-agent/abyss-polkit-agent.conf`) at startup. The file is optional, anything missing falls back to the defaults.

It uses abyssparse syntax. Only the `general` section exists right now.

Defaults:

```
general {
    password_field_width = 340
    window_width         = 520
    window_height        = 440
    show_details         = true
}
```

- `password_field_width`: px, width of the password input
- `window_width`, `window_height`: px, dialog size
- `show_details`: whether the action and command panel can be toggled

Drop the file at the path above with only the keys you want to override. Changes apply the next time the agent starts.

## Theming

Colors, corner rounding, font family and font sizes come from the abysstoolkit palette, not from the agent's own config. Drop a `~/.config/abyss/abysstoolkit.conf` (or `$XDG_CONFIG_HOME/abyss/abysstoolkit.conf`) with the keys you want to override. The next dialog the agent shows uses the new values, no restart needed.

See [the abysstoolkit wiki](https://wiki.abyssland.org/Abyss-Ecosystem/abysstoolkit/) for the full list of available keys.
