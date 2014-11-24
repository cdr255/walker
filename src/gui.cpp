#include "gui.hpp"

Gui::Gui(int window_height, int window_width, const char * window_name, int view_x, int view_y, int view_width, int view_height) 
  : AppWindow(sf::VideoMode(window_width, window_height), window_name),
    screen(sf::FloatRect(view_x, view_y, view_width, view_height))
{
focused = true;
screen.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
AppWindow.setView(screen);  
}


float Gui::Events()

{      
  sf::Time delta_time = clock.restart();
  
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
	  
	case sf::Event::KeyPressed:
	  if(event.key.code == sf::Keyboard::Escape)
	    AppWindow.close();
	  break;

	default:
	  break;
	}
    }
  return delta_time.asSeconds();
}
