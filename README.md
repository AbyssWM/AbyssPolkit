# abysspolkitagent
A simple polkit authentication agent for Abyssland, written in C++ with [abysstoolkit](https://github.com/AbyssWM/abysstoolkit).

![](./assets/polkit.png)

## Usage

See [the abyssland wiki](https://github.com/AbyssWM/Abyssland).

## Configuration

abysspolkitagent reads `~/.config/abysspolkitagent/abysspolkitagent.conf` (or `$XDG_CONFIG_HOME/abysspolkitagent/abysspolkitagent.conf`) at startup. The file is optional, anything missing falls back to the defaults.

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
