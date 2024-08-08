#ifndef EZSTREAM_CHARACTERCACHE
#define EZSTREAM_CHARACTERCACHE

#include "Character.h"
#include <map>
#include <string>

// singleton that stores all the Character objects
class CharacterCache
{
private:
    std::vector<Character> _characters; // vector of characters
    static CharacterCache* _ptr; // pointer to singleton

    const std::string _characters_path = "res/characters/"; // file path to characters

    // Default Constructor (for singleton)
    CharacterCache();
    ~CharacterCache();

public:
    // get reference to the singleton
    static CharacterCache* get();

    static void destroy();

    // get a reference to a specific character
    Character* getCharacter(const std::string& char_name);

    // get all characters
    const std::vector<Character>& getCharacters() { return _characters; }
};

#endif