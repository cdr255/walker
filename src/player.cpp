#include "player.hpp"

void player_control(Character& player, float delta)
{
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    player.move(0, delta);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    player.move(delta, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	      player.move(delta * -1, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	      player.move(0, delta * -1);
}  
