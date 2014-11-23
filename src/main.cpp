#include <SFML/Graphics.hpp>

const int TILESIZE=32;

class Character {
public:
  //sf::RectangleShape sprite;
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
  sf::RenderWindow AppWindow(sf::VideoMode(800, 600), "My Window");
  // sf::RectangleShape player(sf::Vector2f(120,50));
  Character player(10, 10);
  
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
