#ifndef EZSTREAM_CHARACTER_BUTTON
#define EZSTREAM_CHARACTER_BUTTON
#include <string>

#include "Widget.h"
#include "Character.h"

class CharacterButton: public Widget
{
private:
    Character character;
    std::string label;
    std::string jsonLabel; //either p1Character or p2Character

public:
    CharacterButton(int x, int y, int width, const std::string& label = "", const std::string& jsonLabel = "", const Character& character = Character());
    void render() override;
    const Character& getCharacter();
    std::string getName();
    std::string getLabel();
};

#endif