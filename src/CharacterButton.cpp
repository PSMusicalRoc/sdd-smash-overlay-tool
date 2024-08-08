#include "CharacterButton.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

#include "Update.h"
#include "ImageContainer.h"
#include "WindowState.h"
#include "Search.h"

CharacterButton::CharacterButton(int x, int y, int width, const std::string& label, const std::string& json_label, const Character& character)
    :Widget(x, y, width, 0)
{
    this->_label = label;
    this->_json_label = json_label;
    this->_character = character;
}

void CharacterButton::render()
{    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImTextureID my_tex_id = ImageContainer::get()->getImage(ImageContainer::makeCSSImgKey(_character.getName()));
    ImVec2 size = ImVec2(70.0f, 50.0f);

    if(this->_character.checkName(Search::get()->getSearch())){
        if(ImGui::ImageButton(("##" + _label).c_str(), my_tex_id, size)){
            Update::get()->set(this->_json_label, this->getName());
            WindowState::get()->WindowState::set(0);
            Search::get()->Search::set("");
        }
    }
}

const Character& CharacterButton::getCharacter()
{
    return _character;
}

std::string CharacterButton::getName()
{
    return _character.getName();
}

std::string CharacterButton::getLabel()
{
    return _label;
}