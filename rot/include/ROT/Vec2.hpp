#pragma once

#include <cstddef>
#include <cstdint>

namespace rot {

template <typename T> struct Vec2 {
  T x{};
  T y{};

  constexpr Vec2() = default;

  constexpr Vec2(T x, T y) : x(x), y(y) {}

  template <typename U>
  explicit constexpr Vec2(const Vec2<U> &other)
      : x(static_cast<T>(other.x)), y(static_cast<T>(other.y)) {}
};

using Size2D = Vec2<size_t>;
using Vec2Int = Vec2<int32_t>;
using Vec2Size = Vec2<size_t>;
using Vec2Float = Vec2<float>;

} // namespace rot