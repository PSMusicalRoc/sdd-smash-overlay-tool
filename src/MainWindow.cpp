#include "MainWindow.h"
#include "TextInput.h"

#include "imgui.h"
#include "Update.h"
#include <iostream>
#include <fstream>


MainWindow::MainWindow()
{
    _widgets = {
        new TextInput(225, 350, 450, "Tournament Name", "tournName"),
        new TextInput(250, 390, 400, "Bracket Position", "round"),
        new TextInput(50, 50, 400, "Player 1 Name", "p1Name"),
        new TextInput(550, 50, 400, "Player 2 Name", "p2Name")
    };
}

MainWindow::~MainWindow()
{
    for (Widget* w : _widgets)
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

    ImGui::SetCursorPos(ImVec2(40, 400));
    if (ImGui::Button("TestButton"))
    {
        Update::get()->update();
    }

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