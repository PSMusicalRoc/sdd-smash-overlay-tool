#ifndef EZSTREAM_MAIN_WINDOW
#define EZSTREAM_MAIN_WINDOW

#include <SDL.h>
#include "TextInput.h"

class MainWindow
{
private:
    TextInput textInputs[4];
public:
    MainWindow();
    void render(SDL_Window* renderwindow);
};

#endif