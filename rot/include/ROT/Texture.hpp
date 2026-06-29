#pragma once

#include <ROT/Buffer.hpp>
#include <ROT/Rect.hpp>
#include <ROT/TextureRegion.hpp>

namespace rot {

template <typename T> class Texture {
public:
  explicit Texture(Vec2Int size) : buffer(size) {}

  [[nodiscard]]
  TextureRegion<T> crop(IntRect rect) const {
    return {this, rect};
  }

  [[nodiscard]]
  const T &at(const Vec2Int &position) const {
    return buffer.at(position);
  }

  void set(const Vec2Int &position, T value) {
    buffer.set(position, std::move(value));
  }

protected:
  void resize(Vec2Int size) { buffer = Buffer<T>(size); }

  [[nodiscard]] Buffer<T> &getBuffer() { return buffer; }

  [[nodiscard]] const Buffer<T> &getBuffer() const { return buffer; }

private:
  Buffer<T> buffer;
};

} // namespace rot