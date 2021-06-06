#include "../inc/surface.hh"

void Surface::draw() {
    std::vector<std::vector<drawNS::Point3D>> surf;
    for(int x = 0; x < 11; ++x) {
        std::vector<drawNS::Point3D> tmp;
        for(int y = 0; y < 11; ++y) {
            tmp.push_back(Vector2Point(this->points[11*x+y]));
        }
        surf.push_back(tmp);
    }

    this->object_index = this->api_ptr->draw_surface(surf, this->surf_colour);
    this->api_ptr->redraw();
}