#include "Update.h"

#include "imgui.h"
#include <iostream>
#include <fstream>


Update* Update::_reference = nullptr;

Update::Update(const std::string& output_file_path)
{
    this->_output_file_path = output_file_path;
    this->_data = nlohmann::json();
}

Update* Update::get()
{
    if (_reference == nullptr)
    {
        _reference = new Update();
    }
    return _reference;
}

void Update::destroy()
{
    if (_reference != nullptr)
    {
        delete _reference;
        _reference = nullptr;
    }
}

void Update::update() {
    std::ofstream out(this->_output_file_path);
    out << std::setw(4) << _data << std::endl;
}

