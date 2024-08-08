#ifndef EZSTREAM_BACKBUTTON
#define EZSTREAM_BACKBUTTON

#include "Widget.h"

//A button to return to the main window
class BackButton: public Widget
{
public:
    BackButton(int x, int y, int width, int height);

    //render the button on screen
    void render() override;
};

#endif