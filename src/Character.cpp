#include <string>
#include <vector>
#include <algorithm>
#include "Character.h"

Character::Character(std::string name, std::vector<std::string> aliases)
{
    this->name = name;
    this->aliases = aliases;
    this->filePath = "res/characters/" + name;
}

char to_lowercase(unsigned char c)
{
    return std::tolower(c);
}

bool Character::checkName(std::string otherName)
{
    //check of other name is contained in any alias
    for(int i = 0; i < (this->aliases).size(); i++)
    {
        //convert to lovercase
        std::string a = (this->aliases)[i];
        std::string other = otherName;
        std::transform(a.begin(), a.end(), a.begin(), to_lowercase);
        std::transform(other.begin(), other.end(), other.begin(), to_lowercase);
        //check if contains
        if((a).find(other) != -1)
        {
            return true;
        }
    }
    return false;
}