#ifndef EZSTREAM_SCORE_INPUT
#define EZSTREAM_SCORE_INPUT
#include <string>

#include "Widget.h"

class ScoreInput: public Widget
{
private:
    unsigned int _score;
    std::string _label;
    std::string _json_label;

public:
    ScoreInput(int x, int y, int width, const std::string& label = "", const std::string& json_label = "");
    void render() override;
    unsigned int getScore();
    std::string getLabel();
};

#endif