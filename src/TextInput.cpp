#include "TextInput.h"

#include "imgui.h"
#include <iostream>
#include "misc/cpp/imgui_stdlib.h"

TextInput::TextInput(const std::string& label)
{
    this->label = label;
    this->text = "";
}

void TextInput::render()
{
    //static std::string input = "";
    
    // by the by, instead of doing:
    // const char* l = &(label[0]);
    // ... you can do:
    const char* l = label.c_str();
    ImGui::InputText(l, &(this->text));
    //text = input;


 //for testing
    // The reason that this doesn't work for the second
    // button, despite the fact that the text box works fine
    // has to do with imgui's naming feature.
    // basically, two things can't have the same name, so if
    // they have the same display label, you can append stuff
    // to it so that the underlying "name" is different
    // read more: https://github.com/ocornut/imgui/blob/master/docs/FAQ.md#q-about-the-id-stack-system
    if (ImGui::Button("print input"))
    {
        std::cout << this->text << std::endl;
    }
}