#ifndef EZSTREAM_SEARCH
#define EZSTREAM_SEARCH

#include <string>
#include "nlohmann/json.hpp"

class Search
{
private:
    static Search* _reference;

   

    // Default Constructor (for singleton)
    std::string search;


    Search();

public:
    static Search* get();
    static void destroy();

    
    void set(std::string new_search) { this -> search = new_search; }

    std::string getSearch() const {return search; }

};

#endif