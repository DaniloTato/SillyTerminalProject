#pragma once

#include <ROT/Buffer.hpp>
#include <ROT/Cell.hpp>

namespace rot {

template <typename T> class IDrawComponent {
public:
  virtual ~IDrawComponent() = default;
  virtual void draw(Buffer<T> &buffer) const = 0;
};

using ASCIIDrawComponent = IDrawComponent<Cell>;

} // namespace rot