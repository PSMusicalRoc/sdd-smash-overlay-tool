#include "TextInput.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

TextInput::TextInput(std::string label)
{
    this->label = label;
    this->text = "";
}

void TextInput::render()
{
    //static std::string input = "";
    const char* l = &(label[0]);
    ImGui::InputText(l, &(this->text));
    //text = input;


 //for testing
    if (ImGui::Button("print input"))
    {
        std::cout << text << std::endl;
    }
}