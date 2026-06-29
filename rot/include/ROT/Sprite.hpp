#pragma once

#include <ROT/IDrawComponent.hpp>
#include <ROT/Rect.hpp>
#include <ROT/TextureRegion.hpp>
#include <ROT/Vec2.hpp>

namespace rot {

template <typename T> class Sprite : public IDrawComponent<T> {
public:
  explicit Sprite() : region(nullptr, IntRect{}) {}

  explicit Sprite(TextureRegion<T> region, Vec2Int position = {0, 0})
      : region(region), position(position) {}

  void setTextureRegion(TextureRegion<T> newRegion) { region = newRegion; }

  const TextureRegion<T> &getTextureRegion() const { return region; }

  void setPosition(Vec2Int newPosition) { position = newPosition; }

  [[nodiscard]] Vec2Int getPosition() const { return position; }

  void draw(Buffer<T> &buffer) const override {

    if (!region.texture) {
      return;
    }

    for (int32_t y = 0; y < region.rect.size.y; ++y) {
      for (int32_t x = 0; x < region.rect.size.x; ++x) {

        Vec2Int source{
            region.rect.position.x + x,
            region.rect.position.y + y,
        };

        Vec2Int destination{
            position.x + x,
            position.y + y,
        };

        buffer.set(destination, region.texture->at(source));
      }
    }
  }

private:
  TextureRegion<T> region;
  Vec2Int position;
};

using ASCIISprite = Sprite<Cell>;

} // namespace rot