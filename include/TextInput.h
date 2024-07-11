#ifndef EZSTREAM_TEXT_INPUT
#define EZSTREAM_TEXT_INPUT
#include <string>

class TextInput
{
private:
    std::string text;
    std::string label;
public:
    TextInput(const std::string& label);
    void render();
};

#endif