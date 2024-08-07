#include <string>
#include <vector>
#include <algorithm>
#include "Character.h"

Character::Character(std::string name, std::vector<std::string> aliases, int n_costumes)
{
    this->_name = name;
    this->_aliases = aliases;
    this->_num_costumes = n_costumes;
    this->_file_path = "res/characters/" + name;
}

char toLowercase(unsigned char c)
{
    return std::tolower(c);
}

bool Character::checkName(std::string other)
{
    //check of other name is contained in any alias
    for(int i = 0; i < (this->_aliases).size(); i++)
    {
        //convert to lovercase
        std::string a = (this->_aliases)[i];
        std::transform(a.begin(), a.end(), a.begin(), toLowercase);
        std::transform(other.begin(), other.end(), other.begin(), toLowercase);
        //check if contains
        if((a).find(other) != -1)
        {
            return true;
        }
    }
    return false;
}
