#ifndef EZSTREAM_CHARACTERCACHE
#define EZSTREAM_CHARACTERCACHE

#include "Character.h"
#include <map>
#include <string>

class CharacterCache
{
private:
    std::map<std::string, Character> _characters;
    static CharacterCache* _ptr;

    const std::string _characters_path = "res/characters/";

    CharacterCache();
    ~CharacterCache();

public:
    static CharacterCache* get();
    static void destroy();

    Character& getCharacter(const std::string& char_name);
    const std::map<std::string, Character>& getCharacters() { return _characters; }
};

#endif