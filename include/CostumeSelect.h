#ifndef EZSTREAM_COSTUMESELECT
#define EZSTREAM_COSTUMESELECT

#include "Widget.h"

//widget that allows the user to select a costume
class CostumeSelect: public Widget
{
private:
    unsigned int _player_id; //either player 1 or player 2

public:
    CostumeSelect(int x, int y, int width, unsigned int player_id);

    // renders a button for each costume
    void render() override;
};

#endif