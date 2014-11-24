#include "character.hpp"

Character::Character(float a, float b, float tilesize, float speedfactor) {
  x = a;
  y = b;
  size = tilesize;
  sprite.setSize(sf::Vector2f(size, size));
  sprite.setPosition(x, y);
  hit_box = sprite.getGlobalBounds();
  points = 0;
  speed = speedfactor;

}

void Character::move(float a, float b)
{
  x = x + size * a * speed;
  y = y + size * b * speed;
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

void Character::score(int a)
{
  points = points + a;
}
