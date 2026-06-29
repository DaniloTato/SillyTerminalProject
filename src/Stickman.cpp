#include "Stickman.hpp"

void Stickman::setBounds(rot::Vec2Int b) { bounds = b; }

void Stickman::update() {
  position.x += speed * direction;

  sprite.setPosition(static_cast<rot::Vec2Int>(position));

  if ((sprite.getPosition().x + frameSize.x) >= bounds.x) {
    direction = -1.F;
  } else if (sprite.getPosition().x <= 0) {
    direction = 1.F;
  }

  animator.update();
}

void Stickman::draw(rot::TerminalWindow &window) { window.draw(sprite); }