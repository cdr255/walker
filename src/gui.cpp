#include "gui.hpp"

Gui::Gui(int window_height, int window_width, const char * window_name, int view_x, int view_y, int view_width, int view_height) 
  : AppWindow(sf::VideoMode(window_width, window_height), window_name),
    screen(sf::FloatRect(view_x, view_y, view_width, view_height))
{
focused = true;
screen.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
AppWindow.setView(screen);  
}


void Gui::Events()
{
}
