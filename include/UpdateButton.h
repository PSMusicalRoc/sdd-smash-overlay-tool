#ifndef EZSTREAM_UPDATE_BUTTON
#define EZSTREAM_UPDATE_BUTTON

#include "Widget.h"

//button to allow user to update the overlay
class UpdateButton: public Widget
{
public:
    UpdateButton(int x, int y, int width, int height);

    // render the button on screen
    void render() override;
};

#endif