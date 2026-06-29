# ROT (Render On Terminal)

`ROT` is a custom C++ library for drawing ASCII-based content directly to the terminal. It is built as a small rendering layer on top of a fixed-size ASCII buffer, with support for textures, sprites, text, and terminal display.

## What ROT IS

- A lightweight terminal rendering engine.
- Uses a 2D `Buffer<Cell>` grid as the frame buffer.
- Draws using ASCII cells with optional color, bold, and italic styling.
- Outputs terminal frames using ANSI escape sequences.
- Designed for simple animation, games, demos, and terminal-based visualizations.

## Why ROT Exists

ROT was custom made for this project to provide a minimal cross-platform way to:

- display animated ASCII art in a terminal,
- treat terminal output like a frame buffer,
- reuse rendering primitives such as sprites, textures, and text,
- separate program logic from low-level terminal output.

## Use Cases

1. **ASCII games and demos**
   - Render characters, sprites, and backgrounds without a full graphics engine.
   - Build simple game loops with moving actors and particle effects.

2. **Terminal dashboards and visualizers**
   - Draw graphs, status panels, or visual reports in plain text terminals.

3. **Learning and teaching graphics concepts**
   - Demonstrate rendering pipelines, buffers, and sprite animation in a simple environment.

## Architecture Overview

ROT is composed of these core layers:

- **Primitives**
  - `rot::Vec2<T>` and alias types represent coordinates and sizes.
  - `rot::Color` stores RGB color values and optional alpha.
  - `rot::Cell` stores a glyph and style metadata.

- **Buffer and Texture**
  - `rot::Buffer<T>` is a fixed-size 2D cell array.
  - `rot::Texture<T>` wraps a `Buffer<T>` and exposes cropped regions.
  - `rot::ASCIITexture` loads ASCII art from `.txt` files into a `Texture<Cell>`.

- **Drawable Components**
  - `rot::IDrawComponent<T>` is the interface for anything that can be drawn into a buffer.
  - `rot::Sprite<T>` is a drawable region of a texture placed at a position.
  - `rot::Text` is a drawable text object that writes characters into the buffer.

- **Window and Display**
  - `rot::TerminalWindow` owns an `ASCIIBuffer`, accepts draw calls, and flushes the buffer to `std::cout`.

- **Geometry Helpers**
  - `rot::Rect<T>` and `rot::IntRect` support containment and intersection tests.
  - `rot::TextureRegion<T>` identifies a sub-rectangle of a texture.

## Key Classes and Methods

### `rot::Vec2<T>`

A generic 2D vector type.

- `T x, y`
- constructors: default, `Vec2(T x, T y)`, and conversion from another `Vec2<U>`

Aliases:

- `rot::Vec2Int` = `Vec2<int32_t>`
- `rot::Vec2Float` = `Vec2<float>`
- `rot::Vec2Size` = `Vec2<size_t>`
- `rot::Size2D` = `Vec2<size_t>`

### `rot::Color`

Represents an RGBA color for terminal output.

- `Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)`
- `Color(uint8_t r, uint8_t g, uint8_t b)`

Static named colors available in the implementation:

- `Color::Black`
- `Color::Red`
- `Color::Green`
- `Color::Yellow`
- `Color::Blue`
- `Color::Magenta`
- `Color::Cyan`
- `Color::White`

### `rot::Cell`

A single display cell in the ASCII buffer.

- `Cell()` — default empty cell with `' '` glyph and white color.
- `Cell(char glyph, Color color, bool bold, bool italic)`
- `getGlyph()`
- `getColor()`
- `isItalic()`
- `isBold()`

### `rot::Buffer<T>`

A fixed-size 2D storage container.

- `Buffer(Vec2Int size)`
- `clear()`
- `set(const Vec2Int &position, T value)`
- `at(const Vec2Int &position) const`
- `at(const Vec2Int &position)`
- `getWidth() const`
- `getHeight() const`

Alias:

- `rot::ASCIIBuffer = Buffer<Cell>`

### `rot::Texture<T>`

Wraps a buffer as texture data.

- `Texture(Vec2Int size)`
- `TextureRegion<T> crop(IntRect rect) const`
- `at(const Vec2Int &position) const`
- `set(const Vec2Int &position, T value)`

Protected helpers:

- `resize(Vec2Int size)`
- `getBuffer()` / `getBuffer() const`

### `rot::TextureRegion<T>`

Defines a rectangular region inside a texture.

- `texture` pointer
- `rect` sub-area of the texture

### `rot::Sprite<T>`

A drawable sprite that renders a texture region into a buffer.

- `Sprite()`
- `Sprite(TextureRegion<T> region, Vec2Int position = {0, 0})`
- `setTextureRegion(TextureRegion<T> newRegion)`
- `getTextureRegion() const`
- `setPosition(Vec2Int newPosition)`
- `getPosition() const`
- `draw(Buffer<T> &buffer) const` override

Alias:

- `rot::ASCIISprite = Sprite<Cell>`

### `rot::IDrawComponent<T>`

Abstract base class for drawable objects.

- virtual destructor
- `virtual void draw(Buffer<T> &buffer) const = 0`

Alias:

- `rot::ASCIIDrawComponent = IDrawComponent<Cell>`

### `rot::TerminalWindow`

A simple render window for terminal output.

- `TerminalWindow(Vec2Int size)`
- `clear()` — clears the internal buffer.
- `draw(const ASCIIDrawComponent &component)` — draws any ASCII component into the buffer.
- `display()` — writes the buffer to `std::cout` using ANSI escape codes.
- `close()`
- `isOpen() const`

### `rot::ASCIITexture`

Loads ASCII art from a `.txt` file into a texture.

- `ASCIITexture()`
- `ASCIITexture(const std::filesystem::path &path)`
- `loadTextureFromTxt(const std::filesystem::path &path)`

### `rot::Text`

Draws a text string into the buffer.

- `Text(Vec2Int position, std::string text)`
- `setPosition(Vec2Int newPosition)`
- `setText(std::string newText)`
- `getPosition() const`
- `draw(Buffer<Cell> &buffer) const` override

Notes:

- Newlines (`'\n'`) advance the cursor to the next row.
- Text is rendered with white bold italic cells.

### `rot::Rect<T>` and `rot::IntRect`

Used for geometry tests and sprite regions.

- `Rect()`
- `Rect(T x, T y, T width, T height)`
- `contains(const Vec2<T> &point) const`
- `intersects(const Rect<T> &other) const`

Alias:

- `rot::IntRect = Rect<int32_t>`

## How ROT Fits in `SillyVideo`

The `SillyVideo` application uses ROT as the rendering backend:

- `main.cpp` creates a `rot::TerminalWindow` and an `rot::ASCIITexture` from `assets/walking.txt`.
- `Stickman` uses `rot::ASCIISprite` and `Animation` to animate a sprite region.
- `SnowflakeSystem` renders many small snowflake pixels into the window.
- `rot::Text` prints centered title text.
- `TerminalWindow::display()` flushes the final frame.

## Example Usage

```cpp
rot::TerminalWindow window({40, 10});
rot::ASCIITexture texture("assets/walking.txt");

rot::ASCIISprite sprite(texture.crop({0, 0, 7, 3}), {0, 5});

window.clear();
window.draw(sprite);
window.draw(rot::Text({5, 1}, "Hello World"));
window.display();
```

## Build Integration

ROT is built as a static library in `rot/CMakeLists.txt` and linked into the main `SillyVideo` target. The `rot/include/ROT/` folder provides the public API.
