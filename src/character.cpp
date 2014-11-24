#include "character.hpp"

Character::Character(float a, float b, float tilesize) {
  x = a;
  y = b;
  size = tilesize;
  hit_box.setSize(sf::Vector2f(size, size));
  hit_box.setPosition(x, y);
}

void Character::move(float a, float b)
{
  x = x + 32 * a;
  y = y + 32 * b;
  hit_box.setPosition(x, y);
}
