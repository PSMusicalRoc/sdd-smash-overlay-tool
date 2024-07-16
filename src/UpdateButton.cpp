#include "UpdateButton.h"
#include "Update.h"

#include <imgui.h>

UpdateButton::UpdateButton(int x, int y, int width, int height)
    :Widget(x, y, width, height)
{}

void UpdateButton::render()
{
    ImGui::SetCursorPos(ImVec2(_x, _y));
    
    if (ImGui::Button("UPDATE!", ImVec2(_width, _height)))
    {
        Update::get()->update();
    }
}