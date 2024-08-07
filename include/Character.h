#ifndef EZSTREAM_CHARACTER
#define EZSTREAM_CHARACTER
#include <string>
#include <vector>

class Character
{
private:
   std::string _name;
   std::vector<std::string> _aliases;
   std::string _file_path;

public:
    Character(){ 
        _name = "";
        _aliases = {};
    }
    Character(std::string name, std::vector<std::string> aliases);
    bool checkName(std::string name);
    std::string getFilePath() { return this->_file_path; }
    std::string getName() { return this->_name; }
};

#endif