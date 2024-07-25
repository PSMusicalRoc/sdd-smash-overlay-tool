#ifndef EZSTREAM_MAIN_WINDOW
#define EZSTREAM_MAIN_WINDOW

#include <SDL.h>
#include <vector>
#include "Widget.h"

#include "TextInput.h"
#include "Character.h"

class MainWindow
{
private:
    std::vector<Widget*> _widgets;

public:
    MainWindow();
    ~MainWindow();
    std::vector<Character> loadCharacters();
    void render(SDL_Window* renderwindow);
};

#endif