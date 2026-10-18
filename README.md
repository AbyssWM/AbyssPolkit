<div align="center">

<img src="https://github.com/AbyssWM.png?size=200" width="140" alt="Abyss logo">

# 🔐 AbyssPolkit

**Polkit authentication agent for Abyssland.**

[![License](https://img.shields.io/badge/license-BSD--3--Clause-blue?style=flat-square)](LICENSE) [![Fedora COPR](https://img.shields.io/badge/fedora-COPR-51a2da?style=flat-square&logo=fedora&logoColor=white)](https://copr.fedorainfracloud.org/coprs/bb8therobot1717/Abyss/) [![Wayland](https://img.shields.io/badge/wayland-native-ffbc00?style=flat-square&logo=wayland&logoColor=black)](https://wayland.freedesktop.org/) [![C++](https://img.shields.io/badge/C%2B%2B-26-00599c?style=flat-square&logo=cplusplus&logoColor=white)](https://isocpp.org/) [![Stars](https://img.shields.io/github/stars/AbyssWM/AbyssPolkit?style=flat-square&color=7c3aed)](https://github.com/AbyssWM/AbyssPolkit/stargazers)

[🌐 Website](https://abysswm.github.io/) · [📖 Wiki](https://abysswm.github.io/wiki/getting-started) · [📦 Install](#-install) · [🌊 Ecosystem](#-the-abyss-ecosystem)

<sub>Part of <a href="https://github.com/AbyssWM"><b>Abyss</b></a> · based on <a href="https://github.com/hyprwm/hyprpolkitagent">hyprpolkitagent</a> by <a href="https://github.com/hyprwm">hyprwm</a></sub>

</div>

---

> [!WARNING]
> **Experimental, pre-1.0.** Packages exist for several distributions, but expect rough edges and breaking changes.

## ✨ About

A simple polkit authentication agent for Abyssland, written in C++ with [Abysstoolkit](https://github.com/AbyssWM/Abysstoolkit). It ships a systemd user unit and the D-Bus service `org.abyssland.AbyssPolkitAgent`. Only one polkit agent may be registered per session.

![AbyssPolkit](./assets/polkit.png)

## ✨ About

A simple polkit authentication agent for Abyssland, written in C++ with [Abysstoolkit](https://github.com/AbyssWM/Abysstoolkit). It ships a systemd user unit and the D-Bus service `org.abyssland.AbyssPolkitAgent`. Only one polkit agent may be registered per session.

![AbyssPolkit](./assets/polkit.png)

## ✨ About

A simple polkit authentication agent for Abyssland, written in C++ with [Abysstoolkit](https://github.com/AbyssWM/Abysstoolkit). It ships a systemd user unit and the D-Bus service `org.abyssland.AbyssPolkitAgent`. Only one polkit agent may be registered per session.

![AbyssPolkit](./assets/polkit.png)

## Usage

See the [Abyss wiki](https://abysswm.github.io/wiki/tools).

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

See [the abysstoolkit wiki](https://abysswm.github.io/wiki/tools) for the full list of available keys.

## 📦 Install

<details open>
<summary><b>Fedora 44 / 45</b> — COPR</summary>

```sh
sudo dnf copr enable bb8therobot1717/Abyss
sudo dnf install abysspolkit
```
</details>

<details>
<summary><b>Arch Linux</b> — PKGBUILD</summary>

```sh
git clone https://github.com/AbyssWM/arch-builds.git
cd arch-builds/packages/abysspolkit && makepkg -si
```
</details>

<details>
<summary><b>Gentoo</b> — overlay</summary>

```sh
eselect repository add abyss git https://github.com/AbyssWM/gentoo-builds.git
emaint sync -r abyss
emerge --ask gui-apps/abysspolkit
```
</details>

<details>
<summary><b>Void Linux</b> — xbps-src template</summary>

Copy `srcpkgs/abysspolkit` from [void-builds](https://github.com/AbyssWM/void-builds) into your `void-packages` checkout, then:

```sh
./xbps-src pkg abysspolkit && sudo xbps-install -R hostdir/binpkgs abysspolkit
```
</details>

<details>
<summary><b>Debian · Ubuntu · Linux Mint</b></summary>

Packaging lives in [debian-builds](https://github.com/AbyssWM/debian-builds) and [ubuntu-builds](https://github.com/AbyssWM/ubuntu-builds). A signed APT repository is on the way — see the [install guide](https://abysswm.github.io/wiki/getting-started) for the current status.
</details>

### 🔨 Build from source

Install the Abyss libraries it depends on first (see the [install guide](https://abysswm.github.io/wiki/getting-started)), then:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
cmake --build build
sudo cmake --install build
```

## 🌊 The Abyss ecosystem

<details>
<summary>All 17 repositories</summary>

| Repository | Role | Based on |
|---|---|---|
| 🪟 [Abyssland](https://github.com/AbyssWM/Abyssland) | compositor | [Hyprland](https://github.com/hyprwm/Hyprland) |
| 📚 [Abyssal](https://github.com/AbyssWM/Abyssal) | library | [aquamarine](https://github.com/hyprwm/aquamarine) |
| 📚 [Abyssutils](https://github.com/AbyssWM/Abyssutils) | library | [hyprutils](https://github.com/hyprwm/hyprutils) |
| 📚 [Abyssparse](https://github.com/AbyssWM/Abyssparse) | library | [hyprlang](https://github.com/hyprwm/hyprlang) |
| 📚 [Abysscursor](https://github.com/AbyssWM/Abysscursor) | library | [hyprcursor](https://github.com/hyprwm/hyprcursor) |
| 📚 [Abyssgraphics](https://github.com/AbyssWM/Abyssgraphics) | library | [hyprgraphics](https://github.com/hyprwm/hyprgraphics) |
| 📚 [Abysswire](https://github.com/AbyssWM/Abysswire) | library | [hyprwire](https://github.com/hyprwm/hyprwire) |
| 🛠️ [Abyss-scanner](https://github.com/AbyssWM/Abyss-scanner) | tool | [hyprwayland-scanner](https://github.com/hyprwm/hyprwayland-scanner) |
| 📜 [Abyssland-protocols](https://github.com/AbyssWM/Abyssland-protocols) | protocols | [hyprland-protocols](https://github.com/hyprwm/hyprland-protocols) |
| 🧩 [Xdg-desktop-portal-abyss](https://github.com/AbyssWM/Xdg-desktop-portal-abyss) | portal | [xdg-desktop-portal-hyprland](https://github.com/hyprwm/xdg-desktop-portal-hyprland) |
| 📚 [Abysstoolkit](https://github.com/AbyssWM/Abysstoolkit) | library | [hyprtoolkit](https://github.com/hyprwm/hyprtoolkit) |
| 🌙 [Abyss-guiutils](https://github.com/AbyssWM/Abyss-guiutils) | app | [hyprland-guiutils](https://github.com/hyprwm/hyprland-guiutils) |
| 🌙 [AbyssDusk](https://github.com/AbyssWM/AbyssDusk) | app | [hyprsunset](https://github.com/hyprwm/hyprsunset) |
| 🔒 [AbyssLock](https://github.com/AbyssWM/AbyssLock) | app | [hyprlock](https://github.com/hyprwm/hyprlock) |
| 🖼️ [AbyssPaper](https://github.com/AbyssWM/AbyssPaper) | app | [hyprpaper](https://github.com/hyprwm/hyprpaper) |
| 🎨 [AbyssPicker](https://github.com/AbyssWM/AbyssPicker) | app | [hyprpicker](https://github.com/hyprwm/hyprpicker) |
| 🔐 **AbyssPolkit** | app | [hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent) |

</details>

## 💜 Credits

AbyssPolkit exists thanks to **[hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent)**, created by **Hypr Development** at **[hyprwm](https://github.com/hyprwm)**. All credit for the original work goes to them – please support the original project.

Abyss is an independent project and is **not affiliated with or endorsed by hyprwm**.

## ⚖️ License

This project is licensed under the **BSD 3-Clause License**. The original copyright notice is kept in [`LICENSE`](LICENSE) as required.

## 👥 Contributors

- [bb8TheRobot](https://github.com/bb8TheRobot)

## 📦 Install

<details open>
<summary><b>Fedora 44 / 45</b> — COPR</summary>

```sh
sudo dnf copr enable bb8therobot1717/Abyss
sudo dnf install abysspolkit
```
</details>

<details>
<summary><b>Arch Linux</b> — PKGBUILD</summary>

```sh
git clone https://github.com/AbyssWM/arch-builds.git
cd arch-builds/packages/abysspolkit && makepkg -si
```
</details>

<details>
<summary><b>Gentoo</b> — overlay</summary>

```sh
eselect repository add abyss git https://github.com/AbyssWM/gentoo-builds.git
emaint sync -r abyss
emerge --ask gui-apps/abysspolkit
```
</details>

<details>
<summary><b>Void Linux</b> — xbps-src template</summary>

Copy `srcpkgs/abysspolkit` from [void-builds](https://github.com/AbyssWM/void-builds) into your `void-packages` checkout, then:

```sh
./xbps-src pkg abysspolkit && sudo xbps-install -R hostdir/binpkgs abysspolkit
```
</details>

<details>
<summary><b>Debian · Ubuntu</b> — .deb from Releases</summary>

Prebuilt `.deb` files for **Debian forky (testing)** and **Ubuntu 26.10** are attached to every [release](https://github.com/AbyssWM/AbyssPolkit/releases/latest). Install the Abyss libraries first, then:

```sh
sudo apt install ./*.deb
```

Debian 13, Ubuntu 24.04/26.04 and Linux Mint 22 ship libraries that are too old for Abyssland — build from source there. Packaging: [debian-builds](https://github.com/AbyssWM/debian-builds) · [ubuntu-builds](https://github.com/AbyssWM/ubuntu-builds)
</details>

### 🔨 Build from source

Install the Abyss libraries it depends on first (see the [install guide](https://abysswm.github.io/wiki/getting-started)), then:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
cmake --build build
sudo cmake --install build
```

## 🌊 The Abyss ecosystem

<details>
<summary>All 17 repositories</summary>

| Repository | Role | Based on |
|---|---|---|
| 🪟 [Abyssland](https://github.com/AbyssWM/Abyssland) | compositor | [Hyprland](https://github.com/hyprwm/Hyprland) |
| 📚 [Abyssal](https://github.com/AbyssWM/Abyssal) | library | [aquamarine](https://github.com/hyprwm/aquamarine) |
| 📚 [Abyssutils](https://github.com/AbyssWM/Abyssutils) | library | [hyprutils](https://github.com/hyprwm/hyprutils) |
| 📚 [Abyssparse](https://github.com/AbyssWM/Abyssparse) | library | [hyprlang](https://github.com/hyprwm/hyprlang) |
| 📚 [Abysscursor](https://github.com/AbyssWM/Abysscursor) | library | [hyprcursor](https://github.com/hyprwm/hyprcursor) |
| 📚 [Abyssgraphics](https://github.com/AbyssWM/Abyssgraphics) | library | [hyprgraphics](https://github.com/hyprwm/hyprgraphics) |
| 📚 [Abysswire](https://github.com/AbyssWM/Abysswire) | library | [hyprwire](https://github.com/hyprwm/hyprwire) |
| 🛠️ [Abyss-scanner](https://github.com/AbyssWM/Abyss-scanner) | tool | [hyprwayland-scanner](https://github.com/hyprwm/hyprwayland-scanner) |
| 📜 [Abyssland-protocols](https://github.com/AbyssWM/Abyssland-protocols) | protocols | [hyprland-protocols](https://github.com/hyprwm/hyprland-protocols) |
| 🧩 [Xdg-desktop-portal-abyss](https://github.com/AbyssWM/Xdg-desktop-portal-abyss) | portal | [xdg-desktop-portal-hyprland](https://github.com/hyprwm/xdg-desktop-portal-hyprland) |
| 📚 [Abysstoolkit](https://github.com/AbyssWM/Abysstoolkit) | library | [hyprtoolkit](https://github.com/hyprwm/hyprtoolkit) |
| 🌙 [Abyss-guiutils](https://github.com/AbyssWM/Abyss-guiutils) | app | [hyprland-guiutils](https://github.com/hyprwm/hyprland-guiutils) |
| 🌙 [AbyssDusk](https://github.com/AbyssWM/AbyssDusk) | app | [hyprsunset](https://github.com/hyprwm/hyprsunset) |
| 🔒 [AbyssLock](https://github.com/AbyssWM/AbyssLock) | app | [hyprlock](https://github.com/hyprwm/hyprlock) |
| 🖼️ [AbyssPaper](https://github.com/AbyssWM/AbyssPaper) | app | [hyprpaper](https://github.com/hyprwm/hyprpaper) |
| 🎨 [AbyssPicker](https://github.com/AbyssWM/AbyssPicker) | app | [hyprpicker](https://github.com/hyprwm/hyprpicker) |
| 🔐 **AbyssPolkit** | app | [hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent) |

</details>

## 💜 Credits

AbyssPolkit exists thanks to **[hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent)**, created by **Hypr Development** at **[hyprwm](https://github.com/hyprwm)**. All credit for the original work goes to them – please support the original project.

Abyss is an independent project and is **not affiliated with or endorsed by hyprwm**.

## ⚖️ License

This project is licensed under the **BSD 3-Clause License**. The original copyright notice is kept in [`LICENSE`](LICENSE) as required.

## 👥 Contributors

- [bb8TheRobot](https://github.com/bb8TheRobot)

## 📦 Install

<details open>
<summary><b>Fedora 44 / 45</b> — COPR</summary>

```sh
sudo dnf copr enable bb8therobot1717/Abyss
sudo dnf install abysspolkit
```
</details>

<details>
<summary><b>Arch Linux</b> — PKGBUILD</summary>

```sh
git clone https://github.com/AbyssWM/arch-builds.git
cd arch-builds/packages/abysspolkit && makepkg -si
```
</details>

<details>
<summary><b>Gentoo</b> — overlay</summary>

```sh
eselect repository add abyss git https://github.com/AbyssWM/gentoo-builds.git
emaint sync -r abyss
emerge --ask gui-apps/abysspolkit
```
</details>

<details>
<summary><b>Void Linux</b> — signed XBPS repo</summary>

```sh
echo "repository=https://abysswm.github.io/void" | sudo tee /etc/xbps.d/abyss.conf
sudo xbps-install -S abysspolkit
```
</details>

<details>
<summary><b>Debian · Ubuntu</b> — .deb from Releases</summary>

Prebuilt `.deb` files for **Debian forky (testing)** and **Ubuntu 26.10** are attached to every [release](https://github.com/AbyssWM/AbyssPolkit/releases/latest). Install the Abyss libraries first, then:

```sh
sudo apt install ./*.deb
```

Debian 13, Ubuntu 24.04/26.04 and Linux Mint 22 ship libraries that are too old for Abyssland — build from source there. Packaging: [debian-builds](https://github.com/AbyssWM/debian-builds) · [ubuntu-builds](https://github.com/AbyssWM/ubuntu-builds)
</details>

### 🔨 Build from source

Install the Abyss libraries it depends on first (see the [install guide](https://abysswm.github.io/wiki/getting-started)), then:

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
cmake --build build
sudo cmake --install build
```

## 🌊 The Abyss ecosystem

<details>
<summary>All 17 repositories</summary>

| Repository | Role | Based on |
|---|---|---|
| 🪟 [Abyssland](https://github.com/AbyssWM/Abyssland) | compositor | [Hyprland](https://github.com/hyprwm/Hyprland) |
| 📚 [Abyssal](https://github.com/AbyssWM/Abyssal) | library | [aquamarine](https://github.com/hyprwm/aquamarine) |
| 📚 [Abyssutils](https://github.com/AbyssWM/Abyssutils) | library | [hyprutils](https://github.com/hyprwm/hyprutils) |
| 📚 [Abyssparse](https://github.com/AbyssWM/Abyssparse) | library | [hyprlang](https://github.com/hyprwm/hyprlang) |
| 📚 [Abysscursor](https://github.com/AbyssWM/Abysscursor) | library | [hyprcursor](https://github.com/hyprwm/hyprcursor) |
| 📚 [Abyssgraphics](https://github.com/AbyssWM/Abyssgraphics) | library | [hyprgraphics](https://github.com/hyprwm/hyprgraphics) |
| 📚 [Abysswire](https://github.com/AbyssWM/Abysswire) | library | [hyprwire](https://github.com/hyprwm/hyprwire) |
| 🛠️ [Abyss-scanner](https://github.com/AbyssWM/Abyss-scanner) | tool | [hyprwayland-scanner](https://github.com/hyprwm/hyprwayland-scanner) |
| 📜 [Abyssland-protocols](https://github.com/AbyssWM/Abyssland-protocols) | protocols | [hyprland-protocols](https://github.com/hyprwm/hyprland-protocols) |
| 🧩 [Xdg-desktop-portal-abyss](https://github.com/AbyssWM/Xdg-desktop-portal-abyss) | portal | [xdg-desktop-portal-hyprland](https://github.com/hyprwm/xdg-desktop-portal-hyprland) |
| 📚 [Abysstoolkit](https://github.com/AbyssWM/Abysstoolkit) | library | [hyprtoolkit](https://github.com/hyprwm/hyprtoolkit) |
| 🌙 [Abyss-guiutils](https://github.com/AbyssWM/Abyss-guiutils) | app | [hyprland-guiutils](https://github.com/hyprwm/hyprland-guiutils) |
| 🌙 [AbyssDusk](https://github.com/AbyssWM/AbyssDusk) | app | [hyprsunset](https://github.com/hyprwm/hyprsunset) |
| 🔒 [AbyssLock](https://github.com/AbyssWM/AbyssLock) | app | [hyprlock](https://github.com/hyprwm/hyprlock) |
| 🖼️ [AbyssPaper](https://github.com/AbyssWM/AbyssPaper) | app | [hyprpaper](https://github.com/hyprwm/hyprpaper) |
| 🎨 [AbyssPicker](https://github.com/AbyssWM/AbyssPicker) | app | [hyprpicker](https://github.com/hyprwm/hyprpicker) |
| 🔐 **AbyssPolkit** | app | [hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent) |

</details>

## 💜 Credits

AbyssPolkit exists thanks to **[hyprpolkitagent](https://github.com/hyprwm/hyprpolkitagent)**, created by **Hypr Development** at **[hyprwm](https://github.com/hyprwm)**. All credit for the original work goes to them – please support the original project.

Abyss is an independent project and is **not affiliated with or endorsed by hyprwm**.

## ⚖️ License

This project is licensed under the **BSD 3-Clause License**. The original copyright notice is kept in [`LICENSE`](LICENSE) as required.

## 👥 Contributors

- [bb8TheRobot](https://github.com/bb8TheRobot)
