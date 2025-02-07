#include "CostumeSelect.h"
#include "WindowState.h"

#include "Update.h"
#include "ImageContainer.h"
#include "CharacterCache.h"

#include <imgui.h>
#include <imgui_stdlib.h>

CostumeSelect::CostumeSelect(int x, int y, int width, unsigned int player_id)
    :Widget(x, y, width, 0), _player_id(player_id)
{
    Update::get()->set<int>("p" + std::to_string(_player_id) + "Skin", 1);
}

void CostumeSelect::render()
{
    std::string update_key = "p" + std::to_string(_player_id) + "Character";
    std::string character_name = "";
    if (Update::get()->hasKey(update_key))
        character_name = Update::get()->getData<std::string>(update_key);
    Character* c = CharacterCache::get()->getCharacter(character_name);
    int num_costumes = 0;
    if ( c != nullptr )
        num_costumes = c->getNumCostumes();



    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::BeginChild(("##" + std::to_string(_player_id)).c_str(), ImVec2(_width, 40));

    for ( int i = 1; i <= num_costumes; i++ )
    {
        if (ImGui::ImageButton(
            (std::to_string(i) + "##" + std::to_string(_player_id)).c_str(),
            (ImTextureID)(intptr_t)ImageContainer::get()->getImage(ImageContainer::makeCostumeImgKey(character_name, i)),
            ImVec2(30, 30)))
        {
            Update::get()->set<int>("p" + std::to_string(_player_id) + "Skin", i);
        }

        ImGui::SameLine();
    }

    ImGui::EndChild();
}