#ifndef ROTOR_HH
#define ROTOR_HH

#include "hex_prism.hh"

/**
 * @brief Class representing drone rotor.
 */
class Rotor : public HexPrism {
    public: 
        /**
         * @brief Parametric constructor
         * @param file_name file name in which rotor is saved
         * @param api pointer to a class that is connected with gnuplot
         */
        Rotor(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api);
        /**
         * @brief Nonparametric constructor
         */
        Rotor() = default;
        /**
         * @brief Copy constructor
         * @param R Rotor object
         */
        Rotor(const Rotor & R) = default;
        /**
         * @brief Destructor
         */
        ~Rotor() = default;
        /**
         * @brief Rotate rotor by a given angle around a given axis
         * @param angle Rotation angle
         * @param axis Rotation axis
         * @param drone_center Drone center
         */
        void rotate(double angle, char axis, const Vector & drone_center);
        /**
         * @brief Get rotor center
         * @return Rotor center
         */
        const Vector & getCenter() const;
        /**
         * @brief Spin the rotor as the drone is being moved
         */
        void spin();

};

#endif