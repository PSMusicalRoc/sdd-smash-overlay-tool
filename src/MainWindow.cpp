#include "MainWindow.h"
#include "TextInput.h"
#include "ScoreInput.h"
#include "UpdateButton.h"

#include "PlayerCharacterSelect.h"

#include "imgui.h"
#include "Update.h"
#include "ImageContainer.h"
#include <iostream>
#include <fstream>

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
        new PlayerCharacterSelect(225,100,100, "Player 1 Character", "p1char")
        
    };

    _widgets2 = {
        new TextInput(225, 350, 550, "PLACEHOLDER", "tournName")
        
    };


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

