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
    unsigned int costume;
    std::string name;
    std::string label;
    std::string jsonLabel;
    bool player1;

public:
    PlayerCharacterSelect(bool player1, int x, int y, int width, const std::string& label = "", const std::string& jsonLabel = "");
    void render() override;
    unsigned int getCostume();
    std::string getName();
    std::string getLabel();
};

#endif