#include "CharacterButton.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

#include "Update.h"

CharacterButton::CharacterButton(int x, int y, int width, const std::string& label, const std::string& jsonLabel, const Character& character)
    :Widget(x, y, width, 0)
{
    this->label = label;
    this->jsonLabel = jsonLabel;
    this->character = character;

    //Update::get()->set(jsonLabel, "default"); 
    //if characterbutton is rendered in multiple times, can not simply set as default as it will
    //override previously selected character. ie. if user presses back, will delete their character
    //need to get json object from update instance and retrieve current p1character/p2character?

    //if p1Char == null, set to default
    //if p1Char exists, set to what it is
    if(Update::get()->checkjson(jsonLabel)){
        Update::get()->set(jsonLabel, ); 
    }
    std::string val = Update::get()->viewjson<std::string>(jsonLabel);
}

void CharacterButton::render()
{
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width);

    //ADD IMGUI::IMAGE_BUTTON
    float my_tex_w = (float)16;
    float my_tex_h = (float)16;

    ImTextureID my_tex_id;
    ImVec2 size = ImVec2(32.0f, 32.0f);                         // Size of the image we want to make visible
    ImVec2 uv0 = ImVec2(0.0f, 0.0f);                            // UV coordinates for lower-left
    ImVec2 uv1 = ImVec2(32.0f / my_tex_w, 32.0f / my_tex_h);    // UV coordinates for (32,32) in our texture
    ImVec4 bg_col = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);             // Black background
    ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);           // No tint
    if(ImGui::ImageButton(("##" + label).c_str(), my_tex_id, size, uv0, uv1, bg_col, tint_col)){
        Update::get()->set(this->jsonLabel, this->getName());
    }
}

const Character& CharacterButton::getCharacter()
{
    return character;
}

std::string CharacterButton::getName()
{
    return character.getName();
}

std::string CharacterButton::getLabel()
{
    return label;
}