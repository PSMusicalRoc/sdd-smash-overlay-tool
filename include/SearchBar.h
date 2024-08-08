#ifndef EZSTREAM_SEARCH_BAR
#define EZSTREAM_SEARCH_BAR
#include <string>
#include <vector>
#include <regex>

#include "Widget.h"

// widget to allow user search for a character
class SearchBar: public Widget
{
private:
   std::string text; // current inputed text
   std::string label; // label of widget
   std::string jsonLabel; // the label used for the json, why is this here??

public:
   SearchBar(int x, int y, int width, const std::string& label = "");

   // renders the search bar on screen
   void render() override;

   // getters
   std::string getText();
   std::string getLabel();
};

#endif