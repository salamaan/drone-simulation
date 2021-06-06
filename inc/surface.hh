#ifndef SURFACE_HH
#define SURFACE_HH

#include "drawing_interface.hh"
#include "vector.hh"
#include <string>

/**
 * @brief Class representing surface
 */
class Surface : public DrawingInterface {
    protected:
        /**
         * @brief Array of points with coordinates
         */
        std::vector<Vector> points = std::vector<Vector> (121);
        /**
         * @brief Colour of surface that has to be drawn
         */
        std::string surf_colour;

    public:
        /**
         * @brief Draw surface on the scene
         */
        void draw() override;
};

#endif