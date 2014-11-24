#include "walker.hpp"
#include "character.hpp"


int main()
{
  int score = 0;
  sf::Clock clock;
  sf::RenderWindow AppWindow(sf::VideoMode(300, 300), "My Window");
  Character player(100, 100, TILESIZE);
  Character destiny(164, 164, TILESIZE);
  sf::View screen(sf::FloatRect(100, 100, 160, 160));
  screen.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
  AppWindow.setView(screen);
  
  
  // Main Loop
  while(AppWindow.isOpen())
    {
      sf::Time delta_time = clock.restart();

      std::cout << "Time Elapsed: " << delta_time.asSeconds() << ".\n";
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
	    score++;

	}
      //Update Window
      std::cout << score << "\n";
      AppWindow.clear(sf::Color::Black);
      AppWindow.draw(player.sprite);
      AppWindow.draw(destiny.sprite);
      AppWindow.display();
    }


  return 0;
}
