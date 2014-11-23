#include <SFML/Window.hpp>

int main()
{
  sf::Window AppWindow(sf::VideoMode(800, 600), "My Window");
  

  // Main Loop
  while(AppWindow.isOpen())
    {
      // Event Handling
      sf::Event event;
      while(AppWindow.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	    {
	      // Close
	      AppWindow.close();
	    }
	}
    }


  return 0;
}
