#ifndef EZSTREAM_BACKBUTTON
#define EZSTREAM_BACKBUTTON

#include "Widget.h"

class BackButton: public Widget
{
public:
    BackButton(int x, int y, int width, int height);
    void render() override;
};

#endif