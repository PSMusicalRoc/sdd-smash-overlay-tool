#ifndef EZSTREAM_PLAYER_CHARACTER_SELECT
#define EZSTREAM_PLAYER_CHARACTER_SELECT
#include <string>

#include "Widget.h"
#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"
#include <SDL.h>

// button to open the character select screen
class PlayerCharacterSelect: public Widget
{
private:
    unsigned int _costume; // current selected costume
    std::string _name; // current character's name
    std::string _label; // label of the widget
    std::string _json_label; // the label used for the json
    std::string _prev_character; // previous chosen character
    bool _is_player_one; // true if the button corresponds to player 1

public:
    PlayerCharacterSelect(bool player1, int x, int y, int width, const std::string& label = "", const std::string& json_label = "");
    
    // renders button on screen
    void render() override;

    // getters
    unsigned int getCostume();
    std::string getName();
    std::string getLabel();
};

#endif