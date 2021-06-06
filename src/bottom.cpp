#include "../inc/bottom.hh"
#include <fstream>

Bottom::Bottom(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api, std::string colour) {
    std::ifstream file;
    file.open(file_name);
    if(!file.good()) {
        std::cerr << "Error. Could not open a file with bottom surface.\n";
        exit(1);
    }
    for(int i = 0; i < 121; ++i) {
        file >> this->points[i];
    }
    if(!file.good()) {
        std::cerr << "Error. Could not load a bottom surface from a file.\n";
        exit(1);
    }
    file.close();
    this->api_ptr = api;
    this->surf_colour = colour;
}

