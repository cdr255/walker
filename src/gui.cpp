#include "gui.hpp"

Gui::Gui()
{
  focused = true;
AppWindow(sf::VideoMode(300, 300), "Walker v0.1");
screen(sf::FloatRect(100, 100, 160, 160));
screen.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
AppWindow.setView(screen);  
}


Gui::Events()
{
}
