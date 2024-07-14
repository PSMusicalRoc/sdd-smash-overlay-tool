#include "Update.h"

#include "imgui.h"
#include <iostream>
#include <fstream>

void Update::update() {
    std::cout << "Hello World" << std::endl;
    using json = nlohmann::json;

    std::ifstream f("src/overlay-data.json");
    
    json data = json::parse(f);
    data["p1Name"] = "Tester";
    std::ofstream out("src/overlay-data.json");
    
    out << std::setw(4) << data << std::endl;
}

