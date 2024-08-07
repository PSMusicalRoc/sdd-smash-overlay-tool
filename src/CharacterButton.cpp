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

    //if characterbutton is rendered in multiple times, can not simply set as default as it will
    //override previously selected character. ie. if user presses back, will delete their character
    //need to get json object from update instance and retrieve current p1character/p2character?

    //if p1Char == null, set to default
    //if p1Char exists, set to what it is // actually, don't need to do anything
    if(Update::get()->hasKey(json_label)){
        
    }
    else{
        Update::get()->set(json_label, "default"); 
        //tbh playercharacterselect should set p1/p2 character to default since it needs to display
        //the characters before characterbuttons are rendered in anyway
        //if thats the case then characterbutton doesn't have to change json unless its pressed
        //and the hasKey() function can be deleted
    }
}

void CharacterButton::render()
{
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width); //don't think this is being used on ImageButton

    ImTextureID my_tex_id = ImageContainer::get()->getImage(_character.getName() + "_css");
    ImVec2 size = ImVec2(70.0f, 50.0f);
    if(this->_character.checkName(Search::get() -> getSearch())){
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