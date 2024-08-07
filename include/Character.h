#ifndef EZSTREAM_CHARACTER
#define EZSTREAM_CHARACTER
#include <string>
#include <vector>

class Character
{
private:
   std::string _name;
   std::vector<std::string> _aliases;
   int _num_costumes = 0;
   std::string _file_path;

public:
    Character(){ 
        _name = "";
        _aliases = {};
    }
    Character(std::string name, std::vector<std::string> aliases, int n_costumes);
    bool checkName(std::string name);
    std::string getFilePath() const { return this->_file_path; }
    std::string getName() const { return this->_name; }
    int getNumCostumes() const { return this->_num_costumes; }
};

#endif