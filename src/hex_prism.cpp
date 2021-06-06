#include "../inc/hex_prism.hh"
#include <fstream>
#include <cmath>

HexPrism::HexPrism(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api) {
    std::ifstream file;
    file.open(file_name);
    if(!file.good()) {
        std::cerr << "Error. Could not open a file with hex prism model.\n";
        exit(1);
    }

    file >> this->center;
    this->orientation = RotaryMatrix();
    for(int i = 0; i < 12; ++i) {
        file >> this->local_vertices[i];
        global_vertices[i] = local_vertices[i] + this->center; 
    }
    if(!file.good()) {
        std::cerr << "Error. Could not load a hex prism model from a file.\n";
        exit(1);
    }
    file.close();

    this->api_ptr = api;
}

void HexPrism::draw() {
    std::vector<std::vector<drawNS::Point3D>> polyhedron;
    for(int i = 0; i < 2; ++i) {
        std::vector<drawNS::Point3D> tmp;
        for(int j = 0; j < 6; ++j) {
            tmp.push_back(Vector2Point(this->global_vertices[6*i+j]));
        }
        polyhedron.push_back(tmp);
    }
    this->object_index = this->api_ptr->draw_polyhedron(polyhedron);
    this->api_ptr->redraw();
}

void HexPrism::rotate(double angle, char axis) {
    RotaryMatrix rotation(angle, axis);
    this->orientation = this->orientation * rotation;

    for(int i = 0; i < 12; ++i) {
        this->global_vertices[i] = this->orientation * this->local_vertices[i] + this->center;
    }

    this->erase();
    this->draw();
    this->api_ptr->redraw();
}

void HexPrism::move(const Vector & displacement) {
    this->center = center + displacement;
    for(int i = 0; i < 12; ++i) {
        this->global_vertices[i] = this->global_vertices[i] + displacement;
    }

    this->erase();
    this->draw();
    api_ptr->redraw();
}


