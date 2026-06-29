#include "Snowflake.hpp"
#include "ROT/Vec2.hpp"
#include <cstdint>

namespace {
const uint8_t kPhaseMod = 100;
const float kPhaseMultiplier = 0.0001F;
} // namespace

Snowflake::Snowflake(rot::Vec2Int position, char glyph, rot::Color color,
                     rot::IntRect lifeRect)
    : flake(position, glyph, color), position(position), lifeRect(lifeRect),
      phase(static_cast<float>(std::rand() % kPhaseMod) * kPhaseMultiplier),
      baseX(static_cast<float>(position.x)) {}

void Snowflake::update() {
  using Clock = std::chrono::steady_clock;

  speed += acceleration;

  // vertical movement (still accumulative)
  position.y += speed;

  float t = std::chrono::duration<float>(Clock::now() - birthTime).count();

  const float tMult = 5.0F;

  // stable oscillation around baseX (NOT accumulation)
  position.x = baseX + std::sin((t * tMult) + phase) * amplitude;

  auto intPosition = static_cast<rot::Vec2Int>(position);
  flake.setPosition(intPosition);

  if (!lifeRect.contains(intPosition)) {
    dead = true;
  }
}