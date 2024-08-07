#ifndef EZSTREAM_COSTUMESELECT
#define EZSTREAM_COSTUMESELECT

#include "Widget.h"

class CostumeSelect: public Widget
{
private:
    unsigned int _player_id;

public:
    CostumeSelect(int x, int y, int width, unsigned int player_id);
    void render() override;
};

#endif