#ifndef _GUI_HPP_
#define _GUI_HPP_
#include <iostream>
#include <SFML/Graphics>

class Gui {
public:
bool focused;
sf::RenderWindow AppWindow;
sf::View screen;
sf::Clock clock;
Gui();
Events();

};


#endif
