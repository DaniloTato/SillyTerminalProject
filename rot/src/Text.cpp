#include <ROT/Text.hpp>

namespace rot {

void Text::draw(Buffer<Cell> &buffer) const {
  Vec2Int cursor = position;

  for (char c : text) {
    if (c == '\n') {
      cursor.x = position.x;
      cursor.y += 1;
      continue;
    }

    buffer.set(cursor, Cell(c, Color::White, true, true));
    cursor.x += 1;
  }
}

} // namespace rot