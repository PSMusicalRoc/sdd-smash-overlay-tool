#include <string>
#include <vector>
#include "Character.h"

Character::Character(std::string name, std::vector<std::string> aliases)
{
    this->name = name;
    this->aliases = aliases;
    this->filePath = "res/characters/" + name;
}


bool Character::checkName(std::string otherName)
{
    for(int i = 0; i < (this->aliases).size(); i++)
    {
        if((otherName) == ((this->aliases)[i]))
        {
            return true;
        }
    }
    return false;
}