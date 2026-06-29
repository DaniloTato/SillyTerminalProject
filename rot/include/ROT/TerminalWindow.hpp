#pragma once

#include <ROT/Buffer.hpp>
#include <ROT/IDrawComponent.hpp>

namespace rot {

class TerminalWindow {
private:
  ASCIIBuffer buffer;
  bool open = true;

public:
  void clear();
  void draw(const ASCIIDrawComponent &component);
  void display();

  void close() { open = false; }
  [[nodiscard]] bool isOpen() const { return open; }

  TerminalWindow(Vec2Int size) : buffer(size) {}
};

} // namespace rot