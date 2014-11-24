#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include "character.hpp"

class Player: public Character {
public:
  void control(float);
  Player(float,float,float,float);
};

#endif
