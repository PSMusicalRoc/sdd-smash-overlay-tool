#ifndef EZSTREAM_UPDATE_BUTTON
#define EZSTREAM_UPDATE_BUTTON

#include "Widget.h"

class UpdateButton: public Widget
{
public:
    UpdateButton(int x, int y, int width, int height);
    void render() override;
};

#endif