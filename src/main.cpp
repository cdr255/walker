#include "walker.hpp"
#include "character.hpp"

int main()
{
  sf::RenderWindow AppWindow(sf::VideoMode(300, 300), "My Window");
  Character player(10, 10, TILESIZE);
  sf::View screen(sf::FloatRect(100, 100, 100, 100));
  screen.setViewport(sf::FloatRect(0.25f, 0.25f, 0.50f, 0.50f));
  AppWindow.setView(screen);

  // Main Loop
  while(AppWindow.isOpen())
    {
      // Event Handling
      sf::Event event;
      while(AppWindow.pollEvent(event))
	{
	  switch (event.type)
	    {
	      // Pause When Unfocused
	    case sf::Event::LostFocus:
	      focused = false;
	      break;
	     
	    case sf::Event::GainedFocus:
	      focused = true;
	      break;

	      //Close Window
	    case sf::Event::Closed:
	      AppWindow.close();
	      break;
	      
	    default:
	      break;
	    }
	}

      if(focused == true)
	{
	  
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    player.move(0, 1);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    player.move(1, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	    player.move(-1, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	    player.move(0, -1);
	}
      //Update Entities
      player.hit_box.setPosition(player.x, player.y);
      
      //Update Window
      AppWindow.clear(sf::Color::Black);
      AppWindow.draw(player.hit_box);
      AppWindow.display();
    }


  return 0;
}
