#include "ScoreInput.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

#include "Update.h"

ScoreInput::ScoreInput(int x, int y, int width, const std::string& label, const std::string& jsonLabel)
    :Widget(x, y, width, 0)
{
    this->label = label;
    this->jsonLabel = jsonLabel;
    this->score = 0;

    Update::get()->set(jsonLabel, 0);
}

void ScoreInput::render()
{
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width);
    // const char* l = label.c_str();
    // if (ImGui::InputTextWithHint(("##" + label).c_str(), "0",  &(this->score), ImGuiInputTextFlags_CharsDecimal))
    // {
    //     Update::get()->set(this->jsonLabel, this->score);
    // }
    if(ImGui::InputScalar(("##" + label).c_str(), ImGuiDataType_U16, &(this->score), NULL, NULL, "%u"))
    {
        Update::get()->set(this->jsonLabel, this->score);
    }
    ImGui::SetCursorPos(ImVec2(_x, _y-25));
    if (ImGui::ArrowButton(("##" + label + "upButton").c_str(), ImGuiDir_Up)) 
    { 
        score++;
        Update::get()->set(this->jsonLabel, this->score);
    }
    ImGui::SetCursorPos(ImVec2(_x, _y+25));
    if (ImGui::ArrowButton(("##" + label + "downButton").c_str(), ImGuiDir_Down)) 
    { 
        if(score==0){
            
        }
        else{
            score--;
            Update::get()->set(this->jsonLabel, this->score);
        }
    }
}

unsigned int ScoreInput::getScore()
{
    return score;
}

std::string ScoreInput::getLabel()
{
    return label;
}