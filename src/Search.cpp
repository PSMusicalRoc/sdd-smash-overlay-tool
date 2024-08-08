#include "Search.h"

#include "imgui.h"
#include <iostream>
#include <fstream>


Search* Search::_reference = nullptr;

Search::Search()
{
    //0 represents main window
    //1 represents player 1 select
    //2 represents player 2 select
    Search::_search = "";
}

Search* Search::get()
{
    if (_reference == nullptr)
    {
        _reference = new Search();
    }
    return _reference;
}

void Search::destroy()
{
    if (_reference != nullptr)
    {
        delete _reference;
        _reference = nullptr;
    }
}
