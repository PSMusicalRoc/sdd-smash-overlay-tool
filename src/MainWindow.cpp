#include "MainWindow.h"
#include "TextInput.h"
#include "ScoreInput.h"
#include "UpdateButton.h"

#include "imgui.h"
#include "Update.h"
#include <iostream>
#include <fstream>
#include "Character.h"
#include <nlohmann/json.hpp>


MainWindow::MainWindow()
{
    _widgets = {
        new TextInput(225, 350, 550, "Tournament Name", "tournName"),
        new TextInput(250, 390, 500, "Bracket Position", "round"),
        new TextInput(50, 50, 400, "Player 1 Name", "p1Name"),
        new TextInput(550, 50, 400, "Player 2 Name", "p2Name"),
        new ScoreInput(420, 125, 30, "Player 1 Score", "p1Score"),
        new ScoreInput(550, 125, 30, "Player 2 Score", "p2Score"),
        new UpdateButton(450, 450, 100, 40)
    };
    std::vector<Character> chars = loadCharacters();
    for (Character c : chars)
    {
        //for testing, print all character names
        std::cout << c.getName() << std::endl;
    }
}

MainWindow::~MainWindow()
{
    for (Widget* w : _widgets)
    {
        delete w;
    }
}


std::vector<Character> MainWindow::loadCharacters()
{
    std::vector<Character> chars = std::vector<Character>();

    //loop through all characters in "res/characters"
    std::string path = "res/characters";
    for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(path))
    {
        //get the character file name 
        std::string name = entry.path().stem().string();
        //std::cout << name << std::endl; //print for testing
        
        //get info from json
        std::ifstream f("res/characters/" + name + "/info.json");
        nlohmann::json info = nlohmann::json::parse(f);
        std::vector<std::string> aliases(info["aliases"]);

        //add character to vector
        chars.push_back(Character(name, aliases));
    }
    return chars;
}


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
    for (Widget* w : _widgets)
    {
        w->render();
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