#ifndef EZSTREAM_CHARACTER
#define EZSTREAM_CHARACTER
#include <string>
#include <vector>

class Character
{
private:
   std::string name;
   std::vector<std::string> aliases;
   int _num_costumes = 0;
   std::string filePath;

public:
    Character(){ 
        name = "";
        aliases = {};
    }
    Character(std::string name, std::vector<std::string> aliases, int n_costumes);
    bool checkName(std::string name);
    std::string getFilePath() const { return this->filePath; }
    std::string getName() const { return this->name; }
    int getNumCostumes() const { return this->_num_costumes; }
};

#endif