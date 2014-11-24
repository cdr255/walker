#include "player.hpp"

Player::Player(float a, float b, float tilesize, float speedfactor)
  : Character(a, b, tilesize, speedfactor)
{
}

void Player::control (float delta)
{
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    move(0, delta);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    move(delta, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	    move(delta * -1, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	    move(0, delta * -1);
}  
