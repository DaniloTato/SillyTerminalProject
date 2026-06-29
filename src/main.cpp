#include "Animation.hpp"
#include "ROT/Rect.hpp"
#include "SafePath.hpp"
#include "SnowflakeSystem.hpp"
#include "Stickman.hpp"
#include <ROT/ASCIITexture.hpp>
#include <ROT/Sprite.hpp>
#include <ROT/TerminalWindow.hpp>
#include <ROT/Text.hpp>
#include <ROT/Vec2.hpp>
#include <chrono>
#include <thread>

namespace {

constexpr rot::Vec2Int kWindowSize{40, 10};
constexpr auto kFrameDelay = std::chrono::milliseconds{16};

rot::ASCIITexture loadTexture() {
  return {SafePath{"assets/walking.txt"}.get()};
}

Animation makeWalkAnimation(rot::ASCIITexture &texture) {
  constexpr rot::Vec2Int kFrameSize{7, 3};
  constexpr rot::Vec2Int kStartFrame{0, 0};
  constexpr auto kFrameTime = std::chrono::milliseconds{500};

  return {
      .texture = &texture,
      .frameSize = kFrameSize,
      .startFramePosition = kStartFrame,
      .firstFrame = 0,
      .lastFrame = 3,
      .frameTime = kFrameTime,
  };
}

Stickman makeStickman(rot::ASCIITexture &texture) {
  rot::ASCIISprite sprite;

  constexpr rot::Vec2Float kStartingPos{0.F, 5.F};
  constexpr float kSpeed = 0.1F;

  Stickman stickman(sprite, makeWalkAnimation(texture), kStartingPos, kSpeed);

  stickman.setBounds(kWindowSize);

  return stickman;
}

SnowflakeSystem makeSnow() {
  return {rot::IntRect{0, 0, kWindowSize.x, kWindowSize.y}};
}

} // namespace

int main() {
  rot::TerminalWindow window(kWindowSize);

  auto texture = loadTexture();
  auto stickman = makeStickman(texture);
  auto snow = makeSnow();

  constexpr std::string message = "Hello World";
  rot::Text text{{(kWindowSize.x - message.size()) / 2, 2}, message};

  while (window.isOpen()) {
    stickman.update();
    snow.update();

    window.clear();
    snow.draw(window);
    stickman.draw(window);
    window.draw(text);
    window.display();

    std::this_thread::sleep_for(kFrameDelay);
  }
}