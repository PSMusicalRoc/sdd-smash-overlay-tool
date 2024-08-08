#ifndef EZSTREAM_COLOR_INPUT
#define EZSTREAM_COLOR_INPUT
#include <string>

#include "Widget.h"
#include "imgui.h"

//Widget to allow user to choose a color
class ColorInput: public Widget
{
private:
    ImVec4 _color; //the current selected color
    std::string _label; //the label for the widget
    std::string _json_label; //the label used for the json
    ImVec4 _saved_palette[10]; //the preset default colors

    //returns the hex code when given rgb values
    std::string getHexCode(float r, float g, float b, float a);

    //creates the color buttons corresponding to the colors in _saved_palette
    void createPallet();

public:
    ColorInput(int x, int y, int width, const std::string& label = "", const std::string& json_label = "test", float r = 255.0f, float g = 0.0f, float b = 0.0f);
    
    //renders the color button and color picker on screen
    void render() override;

    //getters
    ImVec4 getColor();
    std::string getLabel();
};

#endif