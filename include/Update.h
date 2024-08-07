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
    Update(const std::string& output_file_path = "res/overlay-data.json");

public:
    static Update* get();
    static void destroy();

    template <typename T>
    void set(const std::string& json_key, const T& data) { this->_data[json_key] = data; }

    template <typename T>
    const T getData(const std::string& json_key) { return this->_data[json_key]; }

    bool hasKey(const std::string& json_key) { return _data.contains(json_key); }

    void update();
};

#endif