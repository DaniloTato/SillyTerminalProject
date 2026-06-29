#pragma once

#include <ROT/Vec2.hpp>
#include <cstdint>

namespace rot {

template <typename T> struct Rect {
  Rect() : position(), size() {}
  Rect(T x, T y, T width, T height) : position(x, y), size(width, height) {}

  [[nodiscard]] bool contains(const Vec2<T> &point) const {
    return point.x >= position.x && point.x < position.x + size.x &&
           point.y >= position.y && point.y < position.y + size.y;
  }

  [[nodiscard]] bool intersects(const Rect<T> &other) const {
    return position.x < other.position.x + other.size.x &&
           position.x + size.x > other.position.x &&
           position.y < other.position.y + other.size.y &&
           position.y + size.y > other.position.y;
  }

  Vec2<T> position;
  Vec2<T> size;
};

using IntRect = Rect<int32_t>;

} // namespace rot