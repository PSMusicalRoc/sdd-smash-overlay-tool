#include "MainWindow.h"
#include "TextInput.h"
#include "ScoreInput.h"
#include "UpdateButton.h"
#include "CharacterButton.h"
#include "ColorInput.h"
#include "CostumeSelect.h"

#include "PlayerCharacterSelect.h"

#include "imgui.h"
#include "Update.h"
#include "ImageContainer.h"
#include "CharacterCache.h"
#include "BackButton.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Character.h"
#include <nlohmann/json.hpp>

#include "WindowState.h"


WindowMode MainWindow::currMode = MAINWINDOW;

MainWindow::MainWindow()
{
    _widgets = {
        new TextInput(225, 350, 550, "Tournament Name", "tournName"),
        new TextInput(250, 390, 500, "Bracket Position", "round"),
        new TextInput(50, 50, 400, "Player 1 Name", "p1Name"),
        new TextInput(550, 50, 400, "Player 2 Name", "p2Name"),
        new ScoreInput(420, 125, 30, "Player 1 Score", "p1Score"),
        new ScoreInput(550, 125, 30, "Player 2 Score", "p2Score"),
        new UpdateButton(450, 450, 100, 40),
        new PlayerCharacterSelect(225,100,100, "Player 1 Character", "p1Character"),
        new ColorInput(10, 10, 30, "Player 1 Color Picker", "p1Color", 255, 0, 0),
        new ColorInput(960, 10, 30, "Player 2 Color Picker", "p2Color", 0, 0, 255),
        new CostumeSelect(50, 300, 400, 1),
        new CostumeSelect(550, 300, 400, 2)
        
    };

    _widgets2 = {
        new BackButton(50, 50, 100, 40)
    };

    //std::vector<Character> charList = loadCharacters(); 
    //is this slow? should we preload and save somewhere otherwise we have to load all characters each
    //time playercharselect is pressed... idk need to test later
    // std::vector<Character> charList =  loadCharacters();
    CharacterCache* ccache = CharacterCache::get();

    //CharacterButton arrangement settings
    int row_max = 13; //buttons per row
    int button_x_len = 70; //look in CharacterButton.cpp -> render() -> size(x, y) for perfect fit
    int button_y_len = 50;
    int button_x_pos_init = 10; //starting x position
    int button_y_pos_init = 100; // starting y position

    int counter = 0;
    int x = button_x_pos_init;
    int y = button_y_pos_init;


    int i = 0;
    for (const std::pair<std::string, Character> p : ccache->getCharacters())
    {
        // load css image
        ImageContainer::get()->loadImage(ImageContainer::makeCSSImgKey(p.second.getName()), "res/characters/" + p.second.getName() + "/css.png");
        _widgets2.push_back(new CharacterButton(x, y, 0, "Player 1 CharacterButton " + std::to_string(i), "p1Character", p.second));
        x+=button_x_len+5;
        counter++;

        if(counter==row_max){
            counter = 0;
            x = button_x_pos_init;
            y+=button_y_len+5;
        }

        for (int j = 1; j <= p.second.getNumCostumes(); j++) {
            ImageContainer::get()->loadImage(ImageContainer::makeCostumeImgKey(p.second.getName(), j), "res/characters/" + p.second.getName()
                + "/icon" + std::to_string(j) + ".png");
        }

        i++;
    }

    // for(int i=0; i<ccache->getCharacters().size(); i++){
    //     // load css image
    //     ImageContainer::get()->loadImage(ImageContainer::makeCSSImgKey(charList[i].getName()), "res/characters/" + charList[i].getName() + "/css.png");
    //     _widgets2.push_back(new CharacterButton(x, y, 0, "Player 1 CharacterButton " + std::to_string(i), "p1Character", charList[i]));
    //     x+=button_x_len+5;
    //     counter++;

        // if(counter==row_max){
        //     counter = 0;
        //     x = button_x_pos_init;
        //     y+=button_y_len+5;
        // }

    //     /////// TEMP

    //     for (int j = 1; j <= 8; j++) {
    //         ImageContainer::get()->loadImage(ImageContainer::makeCostumeImgKey(charList[i].getName(), j), "res/characters/" + charList[i].getName()
    //             + "/icon" + std::to_string(j) + ".png");
    //     }

    //     /////// TEMP
    // }
}




MainWindow::~MainWindow()
{
    for (Widget* w : _widgets)
    {
        delete w;
    }
    for (Widget* w : _widgets2)
    {
        delete w;
    }
}


// std::vector<Character> MainWindow::loadCharacters()
// {
//     std::vector<Character> chars = std::vector<Character>();

//     //loop through all characters in "res/characters"
//     std::string path = "res/characters";
//     for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(path))
//     {
//         //get the character file name 
//         std::string name = entry.path().stem().string();
//         //std::cout << name << std::endl; //print for testing
        
//         //get info from json
//         std::ifstream f("res/characters/" + name + "/info.json");
//         nlohmann::json info = nlohmann::json::parse(f);
//         std::vector<std::string> aliases(info["aliases"]);

//         //add character to vector
//         chars.push_back(Character(name, aliases));
//     }
//     return chars;
// }


void MainWindow::render(SDL_Window* renderwindow)
{
    int flags = ImGuiWindowFlags_NoBringToFrontOnFocus |
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoTitleBar;
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    int windowWidth, windowHeight;
    SDL_GetWindowSize(renderwindow, &windowWidth, &windowHeight);
    ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight));

    ImGui::Begin("MainWindow", (bool*)NULL, flags);
    // PLACE ALL WINDOW RENDERING CODE IN HERE

    // ImGui::SetCursorPos(ImVec2(40, 400));
    // if (ImGui::Button("TestButton"))
    // {
    //     Update::get()->update();
    // }

    //render text inputs
    

    if(WindowState::get() -> getState() == 0){
        for (Widget* w : _widgets)
        {
            w->render();
        }

        
        
        ImGui::SetCursorPos(ImVec2(225, 100));
        ImGui::SetNextItemWidth(100);

        /*
        if (ImGui::Button("Change!", ImVec2(100, 0)))
            {
                //Update::get()->set("SelectScreenOpen", "true");
                
                WindowState::get() -> WindowState::set(1);
            }
            */
    }
    else {
        for (Widget* w : _widgets2)
        {
            w->render();
        }
    }
    //testing text inputs
    // if (ImGui::Button("Print Inputs"))
    // {
    //     std::cout << "----Text Inputs----" << std::endl;
    //     for(int i = 0; i < 4; i++)
    //     {
    //         std::cout << textInputs[i].getLabel() << ": " << textInputs[i].getText() << "\n" << std::endl;
    //     }
    // }

    // PLACE ALL WINDOW RENDERING CODE IN HERE
    ImGui::End();
}

