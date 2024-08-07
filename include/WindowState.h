#ifndef EZSTREAM_WINDOW_STATE
#define EZSTREAM_WINDOW_STATE

#include <string>
#include "nlohmann/json.hpp"

class WindowState
{
private:
    static WindowState* _reference;

   

    // Default Constructor (for singleton)
    int _state;


    WindowState();

public:
    static WindowState* get();
    static void destroy();

    
    void set(int new_state) { this -> _state = new_state; }

    int getState() const {return _state; }

};

#endif