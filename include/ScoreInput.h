#ifndef EZSTREAM_SCORE_INPUT
#define EZSTREAM_SCORE_INPUT
#include <string>

#include "Widget.h"

class ScoreInput: public Widget
{
private:
    int score;
    std::string label;
    std::string jsonLabel;

public:
    TextInput(int x, int y, int width, const std::string& label = "", const std::string& jsonLabel = "");
    void render() override;
    int getScore();
    std::string getLabel();

    void increment();
    void decrement();
};

#endif