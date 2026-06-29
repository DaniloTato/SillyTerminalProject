# SillyVideo

A small C++ ASCII animation project built with CMake.

## Project Overview

`SillyVideo` is a console animation application using a custom ASCII rendering library in `rot/`. The app displays a walking stick figure, falling snowflakes, and centered text inside a terminal window.

## Repository Structure

- `CMakeLists.txt` - root CMake build file for the `SillyVideo` executable.
- `build.sh` / `run.sh` - helper scripts to configure/build and run the program.
- `src/` - main application source files:
  - `main.cpp` - program entry point and animation setup.
  - `Animator.cpp` - frame-based sprite animation support.
  - `Snowflake.cpp`, `SnowflakeSystem.cpp` - snow particle behavior.
  - `Stickman.cpp` - stick figure movement and drawing.
  - `SafePath.cpp` - asset path handling.
- `include/` - project headers for animation, actor systems, and utilities.
- `rot/` - custom rendering library:
  - `rot/CMakeLists.txt` - library build configuration.
  - `rot/src/` - ROT implementation files.
  - `rot/include/ROT/` - library public headers.
- `assets/` - ASCII art textures and static asset data.

## Key Components

### `rot`

A reusable static library that provides basic ASCII rendering utilities:

- `ROT/TerminalWindow.hpp` - window abstraction for drawing ASCII content.
- `ROT/ASCIITexture.hpp` - texture loader for ASCII art.
- `ROT/Sprite.hpp`, `ROT/Pixel.hpp`, `ROT/Color.hpp` - sprite and pixel primitives.
- `ROT/Vec2.hpp`, `ROT/Rect.hpp` - geometry and coordinate types.
- `ROT/Text.hpp` - text rendering support.

See [ROT.md](ROT.md) for a dedicated ROT architecture and API reference.

### Application Logic

- `Animation.hpp` / `Animator.hpp` - sprite animation data and update logic.
- `Stickman.hpp` - creates and moves a stick figure using animated textures.
- `SnowflakeSystem.hpp` - spawns and updates snowflake particles within a bounding rectangle.
- `SafePath.hpp` - safe asset path handling using `std::filesystem`.

## Build Instructions

From the project root:

```bash
./build.sh
```

This runs `cmake -S . -B build` and builds the project into the `build/` directory.

## Run Instructions

From the project root:

```bash
./run.sh
```

Or run the built executable directly:

```bash
./build/SillyVideo
```

## Notes

- The executable depends on `assets/walking.txt` which is copied into the build output folder after build.
- The project targets C++20 and uses CMake 3.20 or newer.
