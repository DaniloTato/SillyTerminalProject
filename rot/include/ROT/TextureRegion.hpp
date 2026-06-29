#pragma once

#include <ROT/Rect.hpp>

namespace rot {

template <typename T> class Texture;

template <typename T> struct TextureRegion {

  TextureRegion(const Texture<T> *texture, IntRect rect)
      : texture(texture), rect(rect) {}

  const Texture<T> *texture;

  IntRect rect;
};

} // namespace rot