#pragma once

#include <ROT/Cell.hpp>
#include <ROT/Vec2.hpp>
#include <cstddef>
#include <vector>

namespace rot {

template <typename T> class Buffer {
public:
  Buffer(Vec2Int size);

  void clear();
  void set(const Vec2Int &position, T value);

  [[nodiscard]]
  const T &at(const Vec2Int &position) const;

  [[nodiscard]]
  T &at(const Vec2Int &position);

  [[nodiscard]]
  size_t getWidth() const {
    return static_cast<size_t>(size.x);
  }

  [[nodiscard]]
  size_t getHeight() const {
    return static_cast<size_t>(size.y);
  }

private:
  Vec2Int size;
  std::vector<T> cells;
};

template <typename T>
Buffer<T>::Buffer(Vec2Int size)
    : size(size),
      cells(static_cast<size_t>(size.x) * static_cast<size_t>(size.y)) {}

template <typename T> void Buffer<T>::clear() {
  std::fill(cells.begin(), cells.end(), T{});
}

template <typename T> void Buffer<T>::set(const Vec2Int &position, T value) {
  cells[(position.y * size.x) + position.x] = std::move(value);
}

template <typename T> const T &Buffer<T>::at(const Vec2Int &position) const {
  return cells[(position.y * size.x) + position.x];
}

template <typename T> T &Buffer<T>::at(const Vec2Int &position) {
  return cells[(position.y * size.x) + position.x];
}

using ASCIIBuffer = Buffer<Cell>;

} // namespace rot