#include "../inc/cuboid.hh"
#include <fstream>
#include <cmath>

Cuboid::Cuboid(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api) {
    std::ifstream file;
    file.open(file_name);
    if(!file.good()) {
        std::cerr << "Error. Could not open a file with cuboid model.\n";
        exit(1);
    }

    file >> this->center;
    this->orientation = RotaryMatrix();
    for(int i = 0; i < 8; ++i) {
        file >> this->local_vertices[i];
        global_vertices[i] = local_vertices[i] + this->center; 
    }
    if(!file.good()) {
        std::cerr << "Error. Could not load a cuboid model from a file.\n";
        exit(1);
    }
    file.close();

    this->api_ptr = api;
}

void Cuboid::draw() {
    std::vector<std::vector<drawNS::Point3D>> polyhedron;
    for(int i = 0; i < 2; ++i) {
        std::vector<drawNS::Point3D> tmp;
        for(int j = 0; j < 4; ++j) {
            tmp.push_back(Vector2Point(this->global_vertices[4*i+j]));
        }
        polyhedron.push_back(tmp);
    }
    this->object_index = this->api_ptr->draw_polyhedron(polyhedron);
    this->api_ptr->redraw();
}

void Cuboid::rotate(double angle, char axis) {
    RotaryMatrix rotation(angle, axis);
    this->orientation = this->orientation * rotation;

    for(int i = 0; i < 8; ++i) {
        this->global_vertices[i] = this->orientation * this->local_vertices[i] + this->center;
    }

    this->erase();
    this->draw();
    this->api_ptr->redraw();
}


void Cuboid::move(const Vector & displacement) {
    this->center = center + displacement;
    for(int i = 0; i < 8; ++i) {
        this->global_vertices[i] = this->global_vertices[i] + displacement;
    }

    this->erase();
    this->draw();
    this->api_ptr->redraw();
}
