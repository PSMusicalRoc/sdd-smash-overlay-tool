#ifndef EZSTREAM_SCORE_INPUT
#define EZSTREAM_SCORE_INPUT
#include <string>

#include "Widget.h"

// Widget to allow user to change the score
class ScoreInput: public Widget
{
private:
    unsigned int _score; // the current score
    std::string _label; // the label of the widget
    std::string _json_label; // the label used for the json

public:
    ScoreInput(int x, int y, int width, const std::string& label = "", const std::string& json_label = "");

    // render the widget on screen
    void render() override;

    // getters
    unsigned int getScore();
    std::string getLabel();
};

#endif