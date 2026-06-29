#pragma once

#include <cstdint>

namespace {
constexpr uint8_t kDefaultAlpha = 255;
}

namespace rot {

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a = kDefaultAlpha;

  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
  Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

  static const Color Black;
  static const Color Red;
  static const Color Green;
  static const Color Yellow;
  static const Color Blue;
  static const Color Magenta;
  static const Color Cyan;
  static const Color White;
};

} // namespace rot