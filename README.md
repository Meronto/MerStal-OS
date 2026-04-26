# MerStal-OS

**MerStal-OS** is an experimental SDL3-based PDA-style shell inspired by dark post-apocalyptic terminal interfaces.

The project is currently a desktop prototype, but the long-term goal is to run it as a custom fullscreen environment on a minimal **Buildroot-based Linux system** for the **Raspberry Pi Zero 2 W**.

## Status

Current prototype includes:

- SDL3 window and render loop
- modular main menu screen
- keyboard navigation
- textured UI buttons
- early support for custom fonts and assets

This is not a complete operating system yet. It is the graphical shell prototype that will later be integrated into a custom embedded Linux image.




## Clone

Clone the repository:

```bash
git clone https://github.com/Meronto/MerStal-OS.git
cd MerStal-OS
```

If you use SSH:

```bash
git clone git@github.com:Meronto/MerStal-OS.git
cd MerStal-OS
```

Replace `YOUR_USERNAME` with your GitHub username.

## Dependencies

### Debian / Ubuntu

```bash
sudo apt update
sudo apt install cmake gcc git libsdl3-dev libsdl3-image-dev libsdl3-ttf-dev
```

### Arch Linux / Manjaro

```bash
sudo pacman -Syu
sudo pacman -S cmake gcc git sdl3 sdl3_image sdl3_ttf
```

### Fedora

```bash
sudo dnf update
sudo dnf install cmake gcc git SDL3-devel SDL3_image-devel SDL3_ttf-devel
```

If SDL3 packages are not available in your distribution repositories, SDL3, SDL3_image and SDL3_ttf can be built manually from source.

## Build

Build the project from the repository root:

```bash
cmake -S . -B build
cmake --build build
```

## Run

Run the executable from the project root:

```bash
./build/merstal_os
```

Do not run it from inside the `build/` directory, because assets are loaded using relative paths.


## Goal

The final goal is:

```text
Raspberry Pi Zero 2 W
  -> Buildroot Linux
  -> auto-start MerStal-OS
  -> fullscreen PDA-style interface
```

> If you have any problems, write in [telegram](https://t.me/meronto)📩
