#include "../inc/drone.hh"
#include <unistd.h>
#include <fstream>
#include <cmath>

Drone::Drone(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api) {
    std::ifstream file;
    file.open(file_name);
    if(!file.good()) {
        std::cerr << "Error. Could not open a file with drone model.\n";
        exit(1);
    }

    file >> this->center;
    this->orientation = RotaryMatrix();
    for(int i = 0; i < 8; ++i) {
        file >> this->local_vertices[i];
        global_vertices[i] = local_vertices[i] + this->center; 
    }
    if(!file.good()) {
        std::cerr << "Error. Could not load a drone model from a file.\n";
        exit(1);
    }
    file.close();

    this->rotor1 = Rotor("models/rotor1.dat", api);
    this->rotor2 = Rotor("models/rotor2.dat", api);

    this->api_ptr = api;
}

void Drone::draw() {
    std::vector<std::vector<drawNS::Point3D>> polyhedron;
    for(int i = 0; i < 2; ++i) {
        std::vector<drawNS::Point3D> tmp;
        for(int j = 0; j < 4; ++j) {
            tmp.push_back(Vector2Point(this->global_vertices[4*i+j]));
        }
        polyhedron.push_back(tmp);
    }
    this->object_index = this->api_ptr->draw_polyhedron(polyhedron);
    this->rotor1.draw();
    this->rotor2.draw();
    this->api_ptr->redraw();
}

void Drone::erase() {
    this->api_ptr->erase_shape(this->object_index);
    this->rotor1.erase();
    this->rotor2.erase();
}

void Drone::rotate(double angle, char axis) {
    RotaryMatrix rotation(angle / 50, axis);

    for(int frames = 1; frames <= 50; ++frames) {
        this->orientation = this->orientation * rotation;
        for(int i = 0; i < 8; ++i) {
            this->global_vertices[i] = this->orientation * this->local_vertices[i] + this->center;
        }
        this->rotor1.rotate(angle / 50, axis, this->center);
        this->rotor2.rotate(angle / 50, axis, this->center); 
        this->rotor1.spin();
        this->rotor2.spin();

        this->erase();
        this->draw();
        this->api_ptr->redraw();
    }
}

void Drone::move(double distance) {
    Vector tmp1 = (this->local_vertices[0] + this->local_vertices[1]) / 2;
    Vector tmp2 = (this->local_vertices[4] + this->local_vertices[5]) / 2;
    Vector tmp3 = (tmp1 + tmp2) / 2;
    Vector displacement = tmp3 * (distance / tmp3.length());
    displacement = this->orientation * displacement;
    displacement = displacement / 50;

    for(int frames = 1; frames <= 50; ++frames) {
        this->center = center + displacement;
        for(int i = 0; i < 8; ++i) {
            this->global_vertices[i] = this->global_vertices[i] + displacement;
        }
        this->rotor1.move(displacement);
        this->rotor2.move(displacement);
        this->rotor1.spin();
        this->rotor2.spin();

        this->erase();
        this->draw();
        this->api_ptr->redraw();
    }
}