#ifndef DRONE_HH
#define DRONE_HH

#include "cuboid.hh"
#include "rotor.hh"
#include <string>

/**
 * @brief Class representing drone.
 */
class Drone : public Cuboid {
        /**
         * @brief Drone rotor
         */
        Rotor rotor1, rotor2;

    public:
        /**
         * @brief Parametric constructor
         * @param file_name file name in which drone is saved
         * @param api pointer to a class that is connected with gnuplot
         */
        Drone(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api);
        /**
         * @brief Nonparametric constructor
         */
        Drone() = default;
        /**
         * @brief Copy constructor
         * @param R Drone object
         */
        Drone(const Drone & D) = default;
        /**
         * @brief Destructor
         */
        ~Drone() = default;
        /**
         * @brief Draw the drone on the scene
         */
        void draw();
        /**
         * @brief Erase the drone from the scene
         */
        void erase();
        /**
         * @brief Rotate the drone by a given angle around a given axis
         * @param angle Rotation angle
         * @param axis Rotation axis
         */
        void rotate(double angle, char axis);
        /**
         * @brief Moves the drone in the direction of its orientation by the given distance
         * @param distance Displacement distance
         */
        void move(double distance);
};

#endif