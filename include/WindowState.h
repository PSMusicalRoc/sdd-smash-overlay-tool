#ifndef EZSTREAM_WINDOW_STATE
#define EZSTREAM_WINDOW_STATE

#include <string>
#include "nlohmann/json.hpp"

//singleton that holds the state of the main window, meaning which screen is currently being shown
class WindowState
{
private:
    static WindowState* _reference; // reference to singleton
    int _state; // current state

    // Default Constructor (for singleton)
    WindowState();

public:
    // get reference to the singleton
    static WindowState* get();
    
    static void destroy();

    // set the state
    void set(int new_state) { this -> _state = new_state; }

    // get current state
    int getState() const {return _state; }

};

#endif