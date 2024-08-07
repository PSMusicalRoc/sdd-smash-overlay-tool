#ifndef EZSTREAM_SEARCH_BAR
#define EZSTREAM_SEARCH_BAR
#include <string>
#include <vector>
#include <regex>

#include "Widget.h"

class SearchBar: public Widget
{
private:
   std::string text;
   std::string label;
   std::string jsonLabel;

public:
   SearchBar(int x, int y, int width, const std::string& label = "", const std::string& jsonLabel = "");
   void render() override;

   std::string getText();
   std::string getLabel();
};

#endif