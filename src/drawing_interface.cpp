#include "../inc/drawing_interface.hh"

void DrawingInterface::erase() {
    this->api_ptr->erase_shape(object_index);
}
