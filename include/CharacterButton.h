#ifndef EZSTREAM_CHARACTER_BUTTON
#define EZSTREAM_CHARACTER_BUTTON
#include <string>

#include "Widget.h"
#include "Character.h"

//the button that allows the user to select a character
class CharacterButton: public Widget
{
private:
    Character _character; //the Character that the button corresponds to
    std::string _label; //the label of the button
    std::string _json_label; //the label used for the json, either p1Character or p2Character

public:
    CharacterButton(int x, int y, int width, const std::string& label = "", const std::string& json_label = "", const Character& character = Character());
    
    //renders the button on screen
    void render() override;

    //getters
    const Character& getCharacter();
    std::string getName();
    std::string getLabel();
};

#endif