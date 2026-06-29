#pragma once

#include "Animation.hpp"
#include "Animator.hpp"
#include <ROT/Sprite.hpp>
#include <ROT/TerminalWindow.hpp>
#include <ROT/Vec2.hpp>

namespace {
const float kDefaultDirection = 1.F;
}

class Stickman {
public:
  Stickman(rot::ASCIISprite sprite, Animation animation,
           rot::Vec2Float startingPos, float speed)
      : sprite(std::move(sprite)), animator(this->sprite, animation),
        position(startingPos), frameSize(animation.frameSize), speed(speed) {}

  void update();
  void draw(rot::TerminalWindow &window);

  void setBounds(rot::Vec2Int bounds);

private:
  rot::ASCIISprite sprite;
  Animator animator;

  rot::Vec2Float position;
  float direction = kDefaultDirection;

  rot::Vec2Int frameSize;
  rot::Vec2Int bounds;
  float speed;
};