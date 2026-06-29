#pragma once

#include "ROT/Color.hpp"
#include <ROT/Buffer.hpp>
#include <ROT/IDrawComponent.hpp>
#include <ROT/Vec2.hpp>

namespace rot {

template <typename T> class Pixel : public IDrawComponent<T> {
public:
  Pixel(Vec2Int position, char glyph) : position(position), glyph(glyph) {}
  Pixel(Vec2Int position, char glyph, rot::Color color)
      : position(position), glyph(glyph), color(color) {}

  void draw(Buffer<T> &buffer) const override {
    buffer.set(position, Cell(glyph, color, false, false));
  }

  void setPosition(Vec2Int newPosition) { position = newPosition; }

  [[nodiscard]] Vec2Int getPosition() const { return position; }

private:
  Vec2Int position;
  char glyph;
  rot::Color color;
};

using ASCIIPixel = Pixel<Cell>;

} // namespace rot