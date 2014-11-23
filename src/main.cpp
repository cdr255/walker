#include <iostream>
#include <SFML/Graphics.hpp>

const int TILESIZE=32;
bool focused=true;


class Character {
  // Things that walk on the map.
public:
  int x, y, size;
  sf::RectangleShape hit_box;
  Character(int, int);
};


Character::Character(int a, int b) {
  x = a;
  y = b;
  size = TILESIZE;
  hit_box.setSize(sf::Vector2f(size, size));
  hit_box.setPosition(x, y);
}
  



int main()
{
  sf::RenderWindow AppWindow(sf::VideoMode(300, 300), "My Window");
  Character player(10, 10);
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
      
      //Update Window
      std::cout << focused << "\n";
      AppWindow.clear(sf::Color::Black);
      AppWindow.draw(player.hit_box);
      AppWindow.display();
    }


  return 0;
}
