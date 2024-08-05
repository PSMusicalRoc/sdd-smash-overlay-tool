#ifndef EZSTREAM_SEARCH_BAR
#define EZSTREAM_SEARCH_BAR
#include <string>
#include <vector>

class SearchBar
{
private:
   std::string name;
   std::vector<std::string> aliases;
   std::string filePath;

public:
    Character(std::string name, std::vector<std::string> aliases);
    bool checkName(std::string name);
    std::string getFilePath() { return this->filePath; }
    std::string getName() { return this->name; }

    std::vector<Character> sea
};

#endif