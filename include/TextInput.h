#ifndef EZSTREAM_TEXT_INPUT
#define EZSTREAM_TEXT_INPUT
#include <string>

class TextInput
{
private:
    std::string text;
    std::string label;
    std::string jsonLabel;
    int width;
public:
    TextInput(const std::string& label = "", int width = 100, const std::string& jsonLabel = "");
    void render();
    std::string getText();
    std::string getLabel();
};

#endif