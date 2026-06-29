#include "Animator.hpp"
#include <cstdint>

Animator::Animator(rot::ASCIISprite &sprite, Animation animation)
    : sprite(sprite), animation(animation) {
  updateRegion();
}

void Animator::update() {
  auto now = Clock::now();

  if (now - lastFrameTime >= animation.frameTime) {
    ++currentFrame;

    if (currentFrame > animation.lastFrame) {
      currentFrame = animation.firstFrame;
    }

    updateRegion();

    lastFrameTime = now;
  }
}

void Animator::updateRegion() {
  rot::IntRect rect{
      animation.startFramePosition.x +
          (static_cast<int32_t>(currentFrame) * animation.frameSize.x),
      animation.startFramePosition.y, animation.frameSize.x,
      animation.frameSize.y};

  sprite.get().setTextureRegion(rot::TextureRegion{animation.texture, rect});
}