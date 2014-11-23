#include <SFML/Graphics.hpp>

const int TILESIZE=32;

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
	  if(event.type == sf::Event::Closed)
	    {
	      // Close
	      AppWindow.close();
	    }
	}
      
      //Update Window
      AppWindow.clear(sf::Color::Black);
      AppWindow.draw(player.hit_box);
      AppWindow.display();
    }


  return 0;
}
