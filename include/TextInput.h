#ifndef EZSTREAM_TEXT_INPUT
#define EZSTREAM_TEXT_INPUT
#include <string>

#include "Widget.h"

//Widget to allow user to change text
class TextInput: public Widget
{
private:
    std::string _text; // the current text
    std::string _label; // the label of the widget
    std::string _json_label; // the label used for the json

public:
    TextInput(int x, int y, int width, const std::string& label = "", const std::string& json_label = "");

    // render the widget on screen
    void render() override;

    // getters
    std::string getText();
    std::string getLabel();
};

#endif