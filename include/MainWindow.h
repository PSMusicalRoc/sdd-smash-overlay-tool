#ifndef EZSTREAM_MAIN_WINDOW
#define EZSTREAM_MAIN_WINDOW

#include <SDL.h>
#include <vector>
#include "Widget.h"

#include "TextInput.h"
#include "Character.h"

enum WindowMode {
    MAINWINDOW,
    P1SELECT,
    P2SELECT
};

//the main window that everything is displayed on
class MainWindow
{
private: 
    std::vector<Widget*> _widgets; //widgets for main window
    std::vector<Widget*> _widgets2; //widgets for player 1 character select
    std::vector<Widget*> _widgets3; //widgets for player 2 character select

    //current active window
    static WindowMode _curr_mode;


public:
    MainWindow();
    ~MainWindow();
    //render all widgets of the active window
    void render(SDL_Window* render_window);
};




#endif