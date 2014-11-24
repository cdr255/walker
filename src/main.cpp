#include "walker.hpp"
#include "character.hpp"
#include "gui.hpp"
#include "player.hpp"

int main()
{
  Gui system(300, 300, "Walker", 100, 100, 160, 160);
  Player player(100, 100, TILESIZE, SPEED);
  Character destiny(164, 164, TILESIZE, SPEED);
  
  // Main Loop
  while(system.AppWindow.isOpen())
    {
      float delta = system.Events();
      if(system.focused == true)
	{
	  
	  player.control(delta);
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
