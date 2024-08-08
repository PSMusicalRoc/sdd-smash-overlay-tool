#ifndef EZSTREAM_CHARACTER
#define EZSTREAM_CHARACTER
#include <string>
#include <vector>

//stores information on a particular character
class Character
{
private:
   std::string _name; //name of the character
   std::vector<std::string> _aliases; //other names the character may have / be called
   int _num_costumes = 0; //number of costumes the character has
   std::string _file_path; //the file path to the folder containing all of the character's info and images

public:
    Character(){ 
        _name = "";
        _aliases = {};
    }
    Character(std::string name, std::vector<std::string> aliases, int n_costumes);

    //returns true if name is contained in any of the _aliases
    bool checkName(std::string name);

    //getters
    std::string getFilePath() const { return this->_file_path; }
    std::string getName() const { return this->_name; }
    int getNumCostumes() const { return this->_num_costumes; }
};

#endif