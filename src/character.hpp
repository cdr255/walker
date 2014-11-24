#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_
#include <SFML/Graphics.hpp>

class Character {
  // Things that walk on the map.
public:
  float x, y, size;
  sf::RectangleShape hit_box;
  Character(float, float, float);
  void move(float, float);
};

#endif
