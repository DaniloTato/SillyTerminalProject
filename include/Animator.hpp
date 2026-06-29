#pragma once

#include "Animation.hpp"
#include <ROT/Sprite.hpp>

#include <chrono>
#include <functional>

class Animator {
public:
  Animator(rot::ASCIISprite &sprite, Animation animation);

  void update();

private:
  using Clock = std::chrono::steady_clock;

  void updateRegion();

  std::reference_wrapper<rot::ASCIISprite> sprite;
  Animation animation;

  uint32_t currentFrame = 0;
  Clock::time_point lastFrameTime = Clock::now();
};