#ifndef EZSTREAM_MAIN_WINDOW
#define EZSTREAM_MAIN_WINDOW
#include "TextInput.h"

class MainWindow
{
private:
    TextInput textInputs[4];
public:
    MainWindow();
    void render();
};

#endif