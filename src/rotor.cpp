#include "../inc/rotor.hh"
#include <fstream>
#include <cmath>

Rotor::Rotor(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api) {
    std::ifstream file;
    file.open(file_name);
    if(!file.good()) {
        std::cerr << "Error. Could not open a file with rotor model.\n";
        exit(1);
    }

    file >> this->center;
    this->orientation = RotaryMatrix();
    for(int i = 0; i < 12; ++i) {
        file >> this->global_vertices[i];
        local_vertices[i] = global_vertices[i] - this->center; 
    }
    if(!file.good()) {
        std::cerr << "Error. Could not load a rotor model from a file.\n";
        exit(1);
    }
    file.close();

    this->api_ptr = api;
}

void Rotor::rotate(double angle, char axis, const Vector & drone_center) {
    RotaryMatrix rotation(angle, axis);
    this->center = rotation * (this->center - drone_center) + drone_center;
    this->orientation = this->orientation * rotation;

    for(int i = 0; i < 12; ++i) {
        this->global_vertices[i] = this->orientation * this->local_vertices[i] + this->center;
    }
    
    this->erase();
    this->draw();
    this->api_ptr->redraw();
}

const Vector & Rotor::getCenter() const {
    return this->center;
}

void Rotor::spin() {
    RotaryMatrix spin(15, 'y');
    this->orientation = this->orientation * spin;

    for(int i = 0; i < 12; ++i) {
        this->global_vertices[i] = this->orientation * this->local_vertices[i] + this->center;
    }

    this->erase();
    this->draw();
    this->api_ptr->redraw();
}