#ifndef FIGURE3D_HH
#define FIGURE3D_HH

#include "rotary_matrix.hh"
#include "drawing_interface.hh"

/**
 * @brief Virtual class representing space figure.
 */
class Figure3D : public DrawingInterface {
    protected:
        /**
         * @brief Space figure center
         */
        Vector center;
        /**
         * @brief Space figure orientation
         */
        RotaryMatrix orientation;
        
    public:
        /**
         * @brief Rotate the space figure by a given angle around a given axis
         * @param angle Rotation angle
         * @param axis Rotation axis
         */
        virtual void rotate(double angle, char axis) = 0;
        /**
         * @brief Move space figure by a given vector
         * @param displacement Displacement vector
         */
        virtual void move(const Vector & displacement) = 0;
};

#endif