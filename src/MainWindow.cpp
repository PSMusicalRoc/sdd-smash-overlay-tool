#include "MainWindow.h"
#include "TextInput.h"

#include "imgui.h"
#include "Update.h"
#include <iostream>
#include <fstream>


MainWindow::MainWindow()
{
    TextInput in1("Tournament", 200, "tournName"), in2("Bracket", 200, "round"), in3("Name 1", 100, "p1Name"), in4("Name 2", 100, "p2Name");
    (this->textInputs)[0] = in1; //tournament name input
    (this->textInputs)[1] = in2; //bracket name input
    (this->textInputs)[2] = in3; //Player 1 name input
    (this->textInputs)[3] = in4; //Player 2 name input
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
    for(int i = 0; i < 4; i++)
    {
        textInputs[i].render();
        if(i == 2){ImGui::SameLine();} //so that name inputs are on the same line
    }

    //testing text inputs
    if (ImGui::Button("Print Inputs"))
    {
        std::cout << "----Text Inputs----" << std::endl;
        for(int i = 0; i < 4; i++)
        {
            std::cout << textInputs[i].getLabel() << ": " << textInputs[i].getText() << "\n" << std::endl;
        }
    }

    // PLACE ALL WINDOW RENDERING CODE IN HERE
    ImGui::End();
}