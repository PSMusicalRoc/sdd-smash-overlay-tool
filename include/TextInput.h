#ifndef EZSTREAM_TEXT_INPUT
#define EZSTREAM_TEXT_INPUT
#include <string>

#include "Widget.h"

class TextInput: public Widget
{
private:
    std::string text;
    std::string label;
    std::string jsonLabel;

public:
    TextInput(int x, int y, int width, const std::string& label = "", const std::string& jsonLabel = "");
    void render() override;
    std::string getText();
    std::string getLabel();
};

#endif