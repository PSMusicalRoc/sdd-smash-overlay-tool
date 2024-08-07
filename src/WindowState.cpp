#include "WindowState.h"

#include "imgui.h"
#include <iostream>
#include <fstream>


WindowState* WindowState::_reference = nullptr;

WindowState::WindowState()
{
    //0 represents main window
    //1 represents player 1 select
    //2 represents player 2 select
    WindowState::_state = 0;
}

WindowState* WindowState::get()
{
    if (_reference == nullptr)
    {
        _reference = new WindowState();
    }
    return _reference;
}

void WindowState::destroy()
{
    if (_reference != nullptr)
    {
        delete _reference;
        _reference = nullptr;
    }
}
