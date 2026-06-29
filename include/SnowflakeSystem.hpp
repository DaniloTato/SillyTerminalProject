#pragma once

#include "ROT/Rect.hpp"
#include "Snowflake.hpp"
#include <ROT/TerminalWindow.hpp>
#include <chrono>
#include <memory>
#include <vector>

namespace {
const uint32_t kDefaultSpawnInterval = 300;
}

class SnowflakeSystem {
public:
  SnowflakeSystem(rot::IntRect lifeRect) : lifeRect(lifeRect) {}

  void update();
  void draw(rot::TerminalWindow &window);

  void setlifeRect(rot::IntRect size);
  void setSpawnInterval(std::chrono::milliseconds interval);

private:
  void spawn();

  std::vector<std::unique_ptr<Snowflake>> flakes;

  rot::IntRect lifeRect;
  std::chrono::milliseconds spawnInterval{kDefaultSpawnInterval};
  std::chrono::steady_clock::time_point lastSpawnTime =
      std::chrono::steady_clock::now();
};