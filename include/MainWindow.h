#ifndef EZSTREAM_MAIN_WINDOW
#define EZSTREAM_MAIN_WINDOW

#include <SDL.h>
#include <vector>
#include "Widget.h"

#include "TextInput.h"

class MainWindow
{
private:
    std::vector<Widget*> _widgets;

public:
    MainWindow();
    ~MainWindow();
    void render(SDL_Window* renderwindow);
};

#endif