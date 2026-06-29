#pragma once

#include <ROT/Buffer.hpp>
#include <ROT/IDrawComponent.hpp>
#include <ROT/Vec2.hpp>
#include <string>

namespace rot {

class Text : public IDrawComponent<Cell> {
public:
  Text(Vec2Int position, std::string text)
      : position(position), text(std::move(text)) {}

  void setPosition(Vec2Int newPosition) { position = newPosition; }

  void setText(std::string newText) { text = std::move(newText); }

  [[nodiscard]] Vec2Int getPosition() const { return position; }

  void draw(Buffer<Cell> &buffer) const override;

private:
  Vec2Int position;
  std::string text;
};

} // namespace rot