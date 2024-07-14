#include "MainWindow.h"
#include "updateFunctionality/nlohmann/json.hpp"
#include "TextInput.h"

#include "imgui.h"
#include "Update.h"
#include <iostream>
#include <fstream>


MainWindow::MainWindow()
{
    TextInput in1("Tournament", 200), in2("Bracket", 200), in3("Name 1"), in4("Name 2");
    (this->textInputs)[0] = in1; //tournament name input
    (this->textInputs)[1] = in2; //bracket name input
    (this->textInputs)[2] = in3; //Player 1 name input
    (this->textInputs)[3] = in4; //Player 2 name input
}

void MainWindow::render()
{
    if (ImGui::Button("TestButton"))
    {
        Update u;
        u.update();

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

    // 2 "name" textboxes
    // 2 "score inputs"
    // Update Button
    // ... all in roughly the posisions they should be
}