#include <ROT/Cell.hpp>
#include <ROT/IDrawComponent.hpp>
#include <ROT/TerminalWindow.hpp>
#include <ROT/Vec2.hpp>
#include <cstddef>
#include <iostream>

namespace rot {

void TerminalWindow::clear() { buffer.clear(); }

void TerminalWindow::draw(const ASCIIDrawComponent &component) {
  component.draw(buffer);
}

void TerminalWindow::display() {
  for (size_t y = 0; y < buffer.getHeight(); ++y) {
    for (size_t x = 0; x < buffer.getWidth(); ++x) {
      const Cell &cell = buffer.at(static_cast<Vec2Int>(Vec2Size(x, y)));
      const Color color = cell.getColor();
      std::cout << "\033[38;2;" << static_cast<int>(color.r) << ';'
                << static_cast<int>(color.g) << ';' << static_cast<int>(color.b)
                << 'm';
      if (cell.isBold()) {
        std::cout << "\033[1m";
      }

      if (cell.isItalic()) {
        std::cout << "\033[3m";
      }

      std::cout << cell.getGlyph();
      std::cout << "\033[0m";
    }
    std::cout << '\n';
  }
  std::cout << std::flush;
}

} // namespace rot