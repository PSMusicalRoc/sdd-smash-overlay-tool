#ifndef EZSTREAM_PLAYER_CHARACTER_SELECT
#define EZSTREAM_PLAYER_CHARACTER_SELECT
#include <string>

#include "Widget.h"
#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"
#include <SDL.h>

class PlayerCharacterSelect: public Widget
{
private:
    unsigned int _costume;
    std::string _name;
    std::string _label;
    std::string _json_label;

public:
    PlayerCharacterSelect(int x, int y, int width, const std::string& label = "", const std::string& json_label = "");
    void render() override;
    unsigned int getCostume();
    std::string getName();
    std::string getLabel();
};

#endif