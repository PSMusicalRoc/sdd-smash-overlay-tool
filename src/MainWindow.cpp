#include "MainWindow.h"
#include "updateFunctionality/nlohmann/json.hpp"

#include "imgui.h"
#include <iostream>
#include <fstream>

void MainWindow::render()
{
    if (ImGui::Button("TestButton"))
    {
        std::cout << "Hello World" << std::endl;
        using json = nlohmann::json;

        std::ifstream f("/Users/choia8/SDND/EZStream/ez-stream-tool/src/overlay-data.json");
        
        json data = json::parse(f);
        data["p1Name"] = "Tester";
        std::ofstream out("/Users/choia8/SDND/EZStream/ez-stream-tool/src/overlay-data.json");
        
        out << std::setw(4) << data << std::endl;

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