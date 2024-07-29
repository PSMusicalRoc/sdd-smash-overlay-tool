#ifndef EZSTREAM_COLOR_INPUT
#define EZSTREAM_COLOR_INPUT
#include <string>

#include "Widget.h"
#include "imgui.h"

class ColorInput: public Widget
{
private:
    ImVec4 color;
    std::string label;
    std::string jsonLabel;
    std::string hex;

    std::string getHexCode(float r, float g, float b, float a);

public:
    ColorInput(int x, int y, int width, const std::string& label = "", const std::string& jsonLabel = "", float r = 255.0f, float g = 0.0f, float b = 0.0f);
    void render() override;
    ImVec4 getColor();
    std::string getLabel();
};

#endif