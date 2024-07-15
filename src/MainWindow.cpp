#include "MainWindow.h"

#include "imgui.h"
#include <iostream>



void MainWindow::render()
{
    if (ImGui::Button("Update"))
    {
        std::cout << "Hello World" << std::endl;

    }


    // 2 "name" textboxes
    // 2 "score inputs"
    // Update Button
    // ... all in roughly the posisions they should be
}