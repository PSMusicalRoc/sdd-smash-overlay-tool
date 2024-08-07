#include "CharacterCache.h"

#include <nlohmann/json.hpp>
#include <fstream>

void loadCharacters(std::map<std::string, Character>& characters, const std::string& dirname)
{
    //loop through all characters in "res/characters"
    for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(dirname))
    {
        //get the character file name 
        std::string name = entry.path().stem().string();
        //std::cout << name << std::endl; //print for testing
        
        //get info from json
        std::ifstream f(dirname + name + "/info.json");
        nlohmann::json info = nlohmann::json::parse(f);
        std::vector<std::string> aliases(info["aliases"]);
        int costumes = info["costumes"];

        //add character to vector
        characters.emplace(name, Character(name, aliases, costumes));
    }
}



CharacterCache* CharacterCache::_ptr = nullptr;


CharacterCache::CharacterCache()
{
    loadCharacters(this->_characters, this->_characters_path);
}

CharacterCache::~CharacterCache()
{
    this->_characters.clear();
}

CharacterCache* CharacterCache::get()
{
    if (_ptr == nullptr)
    {
        _ptr = new CharacterCache();
    }
    return _ptr;
}

void CharacterCache::destroy()
{
    if (_ptr != nullptr)
    {
        delete _ptr;
    }
    _ptr = nullptr;
}

Character& CharacterCache::getCharacter(const std::string& char_name)
{
    return this->_characters[char_name];
}