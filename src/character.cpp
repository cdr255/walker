#include "character.hpp"

Character::Character(float a, float b, float tilesize) {
  x = a;
  y = b;
  size = tilesize;
  sprite.setSize(sf::Vector2f(size, size));
  sprite.setPosition(x, y);
  hit_box = sprite.getGlobalBounds();
}

void Character::move(float a, float b)
{
  x = x + 32 * a;
  y = y + 32 * b;
  if(x > 228)
    x = 228;
  if(y > 228)
    y = 228;
  if(x < 100)
    x = 100;
  if(y < 100)
    y = 100;

  sprite.setPosition(x, y);
  hit_box = sprite.getGlobalBounds();
}
