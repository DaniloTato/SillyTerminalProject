#include "SnowflakeSystem.hpp"
#include "ROT/Rect.hpp"
#include <array>

void SnowflakeSystem::setlifeRect(rot::IntRect size) { lifeRect = size; }

void SnowflakeSystem::setSpawnInterval(std::chrono::milliseconds interval) {
  spawnInterval = interval;
}

void SnowflakeSystem::update() {
  auto now = std::chrono::steady_clock::now();

  if (now - lastSpawnTime >= spawnInterval) {
    spawn();
    lastSpawnTime = now;
  }

  for (auto &f : flakes) {
    f->update();
  }

  std::erase_if(
      flakes, [](const std::unique_ptr<Snowflake> &f) { return f->isDead(); });
}

void SnowflakeSystem::spawn() {

  int x = std::rand() % lifeRect.size.x;

  std::array<char, 4> glyphs{'*', 'x', '$', '%'};

  const std::array<rot::Color, 6> colors{rot::Color::White,
                                         rot::Color::Cyan,
                                         rot::Color::Blue,
                                         rot::Color::Magenta,
                                         rot::Color::Yellow,
                                         rot::Color::Green

  };

  const auto glyph =
      glyphs.at(static_cast<std::size_t>(std::rand() % glyphs.size()));

  const auto color =
      colors.at(static_cast<std::size_t>(std::rand() % colors.size()));

  flakes.push_back(
      std::make_unique<Snowflake>(rot::Vec2Int{x, 0}, glyph, color, lifeRect));
}

void SnowflakeSystem::draw(rot::TerminalWindow &window) {
  for (auto &f : flakes) {
    window.draw(f->getPixel());
  }
}