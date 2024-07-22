#ifndef EZSTREAM_CHARACTER
#define EZSTREAM_CHARACTER
#include <string>
#include <vector>

class Character
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
};

#endif