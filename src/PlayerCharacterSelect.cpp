#include "PlayerCharacterSelect.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"
#include <SDL.h>

#include "Update.h"
#include "MainWindow.h"
#include "ImageContainer.h"
#include "CharacterCache.h"

#include "WindowState.h"

void switchCharacterRenders(const std::string& old_character, const std::string& new_character, bool is_player_one)
{
    Character* c = CharacterCache::get()->getCharacter(old_character);
    if ((is_player_one && old_character != Update::get()->getData<std::string>("p2Character") && c != nullptr) ||
        (!is_player_one && old_character != Update::get()->getData<std::string>("p1Character") && c != nullptr))
    {
        int costumes = c->getNumCostumes();
        for (int i = 1; i <= costumes; i++)
        {
            ImageContainer::get()->unloadImage(ImageContainer::makeRenderImgKey(old_character, i));
        }
    }

    c = CharacterCache::get()->getCharacter(new_character);
    if ((is_player_one && new_character != Update::get()->getData<std::string>("p2Character") && c != nullptr) ||
        (!is_player_one && new_character != Update::get()->getData<std::string>("p1Character") && c != nullptr))
    {
        int costumes = c->getNumCostumes();
        for (int i = 1; i <= costumes; i++)
        {
            ImageContainer::get()->loadImage(ImageContainer::makeRenderImgKey(new_character, i), "res/characters/" + new_character
                + "/render" + std::to_string(i) + ".png");
        }
    }
}


PlayerCharacterSelect::PlayerCharacterSelect(bool player1, int x, int y, int width, const std::string& label, const std::string& json_label)
    :Widget(x, y, width, 0)
{
    this->_is_player_one = player1;
    this->_label = label;
    this->_json_label = json_label;
    this->_name = "default";
    this->_prev_character = "";
    Update::get()->set(json_label, "Random"); 
}

void PlayerCharacterSelect::render()
{
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width);

    std::string cname = "";
    int costume = 0;

    if(_is_player_one) {
        cname = Update::get()->getData<std::string>("p1Character");
        if (cname != _prev_character)
        {
            switchCharacterRenders(_prev_character, cname, true);
            _prev_character = cname;
        }

        costume = Update::get()->getData<int>("p1Skin");
        if(ImGui::ImageButton(("##" + _label).c_str(), (ImTextureID)(intptr_t)ImageContainer::get()->getImage(ImageContainer::makeRenderImgKey(cname, costume)) ,ImVec2(_width, _width))) {
            WindowState::get() -> WindowState::set(1);
        }
    } else {
        cname = Update::get()->getData<std::string>("p2Character");
        if (cname != _prev_character)
        {
            switchCharacterRenders(_prev_character, cname, false);
            _prev_character = cname;
        }

        costume = Update::get()->getData<int>("p2Skin");
        if(ImGui::ImageButton(("##" + _label).c_str(), (ImTextureID)(intptr_t)ImageContainer::get()->getImage(ImageContainer::makeRenderImgKey(cname, costume)) ,ImVec2(_width, _width))) {
            WindowState::get() -> WindowState::set(2);
        }
    }
}


std::string PlayerCharacterSelect::getLabel()
{
    return _label;
}
std::string PlayerCharacterSelect::getName()
{
    return _name;
}