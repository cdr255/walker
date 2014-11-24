#include "walker.hpp"
#include "character.hpp"
#include "gui.hpp"

int main()
{
  Gui system;
  sf::Clock clock;
  Character player(100, 100, TILESIZE);
  Character destiny(164, 164, TILESIZE);
  
  // Main Loop
  while(system.AppWindow.isOpen())
    {
      sf::Time delta_time = system.clock.restart();

      std::cout << "Time Elapsed: " << delta_time.asSeconds() << ".\n";
      // Event Handling
      sf::Event event;
      while(system.AppWindow.pollEvent(event))
	{
	  switch (event.type)
	    {
	      // Pause When Unfocused
	    case sf::Event::LostFocus:
	      system.focused = false;
	      break;
	     
	    case sf::Event::GainedFocus:
	      system.focused = true;
	      break;

	      //Close Window
	    case sf::Event::Closed:
	      system.AppWindow.close();
	      break;
	      
	    default:
	      break;
	    }
	}

      if(system.focused == true)
	{
	  
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    if(player.y < 228)
	      player.move(0, SPEED * delta_time.asSeconds());
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    if(player.x < 228)
	      player.move(SPEED * delta_time.asSeconds(), 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	    if(player.x > 100)
	      player.move(SPEED * delta_time.asSeconds() * -1, 0);
	  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	    if(player.y > 100)
	      player.move(0, SPEED * delta_time.asSeconds() * -1);
	  
	  if(player.hit_box.intersects(destiny.hit_box))
	    player.score(1);

	}
      //Update Window
      std::cout << player.points << "\n";
      system.AppWindow.clear(sf::Color::Black);
      system.AppWindow.draw(player.sprite);
      system.AppWindow.draw(destiny.sprite);
      system.AppWindow.display();
    }


  return 0;
}
