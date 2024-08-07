#ifndef EZSTREAM_TEXT_INPUT
#define EZSTREAM_TEXT_INPUT
#include <string>

#include "Widget.h"

class TextInput: public Widget
{
private:
    std::string _text;
    std::string _label;
    std::string _json_label;

public:
    TextInput(int x, int y, int width, const std::string& label = "", const std::string& json_label = "");
    void render() override;
    std::string getText();
    std::string getLabel();
};

#endif