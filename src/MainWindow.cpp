#include "MainWindow.h"

#include "imgui.h"
#include <iostream>

void MainWindow::render()
{
    if (ImGui::Button("TestButton"))
    {
        std::cout << "Hello World" << std::endl;
    }

    ImGui::Text("A");
    ImGui::SameLine();
    ImGui::Text("A");
    ImGui::Text("A");
    ImGui::Text("A");
    ImGui::Text("A");

    ImGui::NewLine();

    ImGui::Text("A");
    ImGui::Text("A");
    ImGui::Text("A");
    ImGui::Text("A");
    ImGui::Text("A");
    ImGui::Text("A");

    // 2 "name" textboxes
    // 2 "score inputs"
    // Update Button
    // ... all in roughly the posisions they should be
}