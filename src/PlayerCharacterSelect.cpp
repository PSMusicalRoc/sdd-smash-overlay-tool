#include "PlayerCharacterSelect.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"
#include <SDL.h>

#include "Update.h"
#include "MainWindow.h"
#include "ImageContainer.h"

#include "WindowState.h"


PlayerCharacterSelect::PlayerCharacterSelect(bool player1, int x, int y, int width, const std::string& label, const std::string& json_label)
    :Widget(x, y, width, 0)
{
    this->_is_player_one = player1;
    this->_label = label;
    this->_json_label = json_label;
    this->_name = "default";

    //SDL_Window* selectWindow = SDL_CreateWindow( "Player Select Screen",
      //  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        //1000, 500, SDL_WINDOW_SHOWN
    //);
     bool r = false;
}

void PlayerCharacterSelect::render()
{
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width);
    
   
    // if(player1) {
    //     if (ImGui::Button("P1Select", ImVec2(_width, _height)))
    //     {
    //         //Update::get()->set("SelectScreenOpen", "true");
    //         WindowState::get() -> WindowState::set(1);
    //     }
    // } else {
    //     if (ImGui::Button("P2Select", ImVec2(_width, _height)))
    //     {
    //         //Update::get()->set("SelectScreenOpen", "true");
    //         WindowState::get() -> WindowState::set(2);

    //     }
    // }

    //Update::get()->getData<std::string>("p1Character"),

    // ImageButton(ImageContainer::get()->loadImage(Update::get()->getData<std::string>("p1Character"), );

    // const std::string path = ""Update::get()->getData<std::string>("p1Character") + 

    std::string cname = "";
    int costume = 0;

    if(_is_player_one) {
        cname = Update::get()->getData<std::string>("p1Character");
        costume = Update::get()->getData<int>("p1Skin");
        if(ImGui::ImageButton(("##" + _label).c_str(), ImageContainer::get()->getImage(ImageContainer::makeRenderImgKey(cname, costume)) ,ImVec2(_width, _width))) {
            Update::get()->set("SelectScreenOpen", "true");
            WindowState::get() -> WindowState::set(1);
        }
    } else {
        cname = Update::get()->getData<std::string>("p2Character");
        costume = Update::get()->getData<int>("p2Skin");
        if(ImGui::ImageButton(("##" + _label).c_str(), ImageContainer::get()->getImage(ImageContainer::makeRenderImgKey(cname, costume)) ,ImVec2(_width, _width))) {
            Update::get()->set("SelectScreenOpen", "true");
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