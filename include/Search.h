#ifndef EZSTREAM_SEARCH
#define EZSTREAM_SEARCH

#include <string>
#include "nlohmann/json.hpp"

// singleton that stores the current search term
class Search
{
private:
    static Search* _reference; // reference to singleton

    std::string _search; //current search

    // Default Constructor (for singleton)
    Search();

public:
    // get reference to the singleton
    static Search* get();

    static void destroy();

    // set _search
    void set(std::string new_search) { this -> _search = new_search; }

    // get _search
    std::string getSearch() const {return _search; }

};

#endif