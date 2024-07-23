#include "BackButton.h"

#include <imgui.h>

BackButton::BackButton(int x, int y, int width, int height)
    :Widget(x, y, width, height)
{}

void BackButton::render()
{
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::Button("Back", ImVec2(_width, _height));
}