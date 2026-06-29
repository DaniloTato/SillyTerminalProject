#pragma once

#include "ROT/Color.hpp"
#include "ROT/Rect.hpp"
#include "ROT/Vec2.hpp"
#include <ROT/Pixel.hpp>

namespace {

const float kDefaultSpeed = 0.02;
const float kDefaultAcceleration = 0.001;
const float kDefaultPhase = 0.0F;
const float kDefaultAmplitude = 2.5F;

} // namespace

class Snowflake {
private:
  rot::ASCIIPixel flake;
  rot::Vec2Float position;
  rot::IntRect lifeRect;
  float speed = kDefaultSpeed;
  float acceleration = kDefaultAcceleration;
  float phase = kDefaultPhase;
  float amplitude = kDefaultAmplitude;
  float baseX;
  std::chrono::steady_clock::time_point birthTime =
      std::chrono::steady_clock::now();
  bool dead = false;

public:
  explicit Snowflake(rot::Vec2Int position, char glyph, rot::Color color,
                     rot::IntRect lifeRect);

  ~Snowflake() = default;

  void update();

  [[nodiscard]] bool isDead() const { return dead; }

  [[nodiscard]] rot::ASCIIPixel getPixel() { return flake; }
};