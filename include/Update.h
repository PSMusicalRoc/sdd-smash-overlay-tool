#ifndef EZSTREAM_UPDATE
#define EZSTREAM_UPDATE

#include <string>
#include "nlohmann/json.hpp"

// singleton that updates the json
class Update
{
private:
    static Update* _reference; // reference to singleton    
    nlohmann::json _data; // json data    
    std::string _output_file_path; // output file path

    // Default Constructor (for singleton)
    Update(const std::string& output_file_path = "res/overlay-data.json");

public:
    // get reference to the singleton
    static Update* get();

    static void destroy();

    // set _data
    template <typename T>
    void set(const std::string& json_key, const T& data) { this->_data[json_key] = data; }

    // get _data
    template <typename T>
    const T getData(const std::string& json_key) { return this->_data[json_key]; }

    // check if json has a key
    bool hasKey(const std::string& json_key) { return _data.contains(json_key); }

    // update json with _data
    void update();
};

#endif