#include "MainWindow.h"
#include "updateFunctionality/nlohmann/json.hpp"

#include "imgui.h"
#include "Update.h"
#include <iostream>
#include <fstream>

void MainWindow::render()
{
    if (ImGui::Button("TestButton"))
    {
        Update u;
        u.update();

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