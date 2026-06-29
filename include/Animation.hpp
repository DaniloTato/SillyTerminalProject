#pragma once

#include <ROT/ASCIITexture.hpp>

namespace {

const uint8_t kDefaultFrameTime = 100;

}

struct Animation {
  const rot::ASCIITexture *texture = nullptr;
  rot::Vec2Int frameSize;
  rot::Vec2Int startFramePosition;
  uint32_t firstFrame{};
  uint32_t lastFrame{};
  std::chrono::milliseconds frameTime{kDefaultFrameTime};
};