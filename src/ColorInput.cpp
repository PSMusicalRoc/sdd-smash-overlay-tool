#include "ColorInput.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

#include "Update.h"

ColorInput::ColorInput(int x, int y, int width, const std::string& label, const std::string& jsonLabel, float r, float g, float b)
    :Widget(x, y, width, 0)
{
    this->label = label;
    this->jsonLabel = jsonLabel;
    this->color = ImVec4(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f); //Red, Green, Blue, Alpha
    this->hex = "";

    Update::get()->set(jsonLabel, getHexCode((this->color).x, (this->color).y, (this->color).z, (this->color).w));
}

void ColorInput::render()
{
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width);

    ImGuiColorEditFlags color_flags = 0 | 0 | 0 | 0 | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview;
    bool popup_open = ImGui::ColorButton((label + " Button").c_str(), color, color_flags); 
    if (popup_open)
    {
        ImGui::OpenPopup(("colorPicker" + label).c_str());
    }

    if (ImGui::BeginPopup(("colorPicker" + label).c_str()))
    {
        ImGui::Text(label.c_str());
        ImGui::ColorPicker4(("##picker" + label).c_str(), (float*)&color, color_flags);

        ImGui::EndPopup();

        Update::get()->set(jsonLabel, getHexCode((this->color).x, (this->color).y, (this->color).z, (this->color).w));
    }
}

ImVec4 ColorInput::getColor()
{
    return color;
}

std::string ColorInput::getLabel()
{
    return label;
}

std::string ColorInput::getHexCode(float r, float g, float b, float a)
{
    //there are some rounding errors sometimes

    int red = (r * 255);
    int green = (g * 255);
    int blue = (b * 255);
    int alpha = (a * 255);

    char hexStr[16];
    snprintf(hexStr, sizeof(hexStr), "#%02x%02x%02x%02x", (red & 0xff), (green & 0xff), (blue & 0xff), (alpha & 0xff));
    return hexStr;
}


