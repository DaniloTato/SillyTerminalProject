#pragma once

#include <ROT/Color.hpp>

namespace rot {

class Cell {
private:
  char glyph;
  Color color;
  bool bold;
  bool italic;

public:
  explicit Cell()
      : glyph(' '), color(Color::White), bold(false), italic(false) {}

  explicit Cell(char glyph, Color color, bool bold, bool italic)
      : glyph(glyph), color(color), bold(bold), italic(italic) {}

  [[nodiscard]] char getGlyph() const { return glyph; }

  [[nodiscard]] Color getColor() const { return color; }

  [[nodiscard]] bool isItalic() const { return italic; }

  [[nodiscard]] bool isBold() const { return bold; }
};

} // namespace rot