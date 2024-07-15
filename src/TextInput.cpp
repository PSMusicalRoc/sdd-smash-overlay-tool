#include "TextInput.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

#include "Update.h"

TextInput::TextInput(int x, int y, int width, const std::string& label, const std::string& jsonLabel)
    :Widget(x, y, width, 0)
{
    this->label = label;
    this->text = "";
    this->jsonLabel = jsonLabel;
}

void TextInput::render()
{
    //static std::string input = "";
    
    ImGui::SetCursorPos(ImVec2(_x, _y));
    ImGui::SetNextItemWidth(_width);
    const char* l = label.c_str();
    if (ImGui::InputText(l, &(this->text)))
    {
        Update::get()->set(this->jsonLabel, this->text);
    }


 //for testing
    // The reason that this doesn't work for the second
    // button, despite the fact that the text box works fine
    // has to do with imgui's naming feature.
    // basically, two things can't have the same name, so if
    // they have the same display label, you can append stuff
    // to it so that the underlying "name" is different
    // read more: https://github.com/ocornut/imgui/blob/master/docs/FAQ.md#q-about-the-id-stack-system
    
    //const char* buttonLabel = ("print " + label + " input").c_str();
    //if (ImGui::Button(buttonLabel))
    //{
    //    std::cout << this->text << std::endl;
    //}
}

std::string TextInput::getText()
{
    return text;
}

std::string TextInput::getLabel()
{
    return label;
}