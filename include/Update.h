#ifndef EZSTREAM_UPDATE
#define EZSTREAM_UPDATE

#include <string>
#include "nlohmann/json.hpp"

class Update
{
private:
    static Update* _reference;

    // json data
    nlohmann::json _data;

    // output file path
    std::string _output_file_path;

    // Default Constructor (for singleton)
    Update(const std::string& output_file_path = "src/overlay-data.json");

public:
    static Update* get();
    static void destroy();

    template <typename T>
    void set(const std::string& jsonKey, const T& data) { this->_data[jsonKey] = data; }

    void update();
};

#endif