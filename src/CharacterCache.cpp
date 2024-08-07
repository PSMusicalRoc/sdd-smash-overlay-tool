#include "CharacterCache.h"

#include <nlohmann/json.hpp>
#include <fstream>

void loadCharacters(std::vector<Character>& characters, const std::string& dirname)
{
    //loop through all characters in "res/characters"
    std::string path = "res/characters";
    std::ifstream iconOrder("res/iconOrder.txt");
    std::string line;
    while(std::getline(iconOrder, line)){
        for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(path))
        {
            //get the character file name 
            std::string name = entry.path().stem().string();
            if(name == line){
                //get info from json
                std::ifstream f("res/characters/" + name + "/info.json");
                nlohmann::json info = nlohmann::json::parse(f);
                std::vector<std::string> aliases(info["aliases"]);
                int num_costumes = info["costumes"];

                //add character to vector
                characters.push_back(Character(name, aliases, num_costumes));
                break;
            }
        }
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

Character* CharacterCache::getCharacter(const std::string& char_name)
{
    for ( Character& c : _characters )
    {
        if ( c.getName() == char_name )
            return &c;
    }
    return nullptr;
}