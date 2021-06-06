#ifndef CUBOID_HH
#define CUBOID_HH

#include "figure3D.hh"

/**
 * @brief Class representing cuboid.
 */
class Cuboid : public Figure3D {
    protected:
        /**
         * @brief Cuboid global vertices
         */
        std::vector<Vector> global_vertices = std::vector<Vector> (8);
        /**
         * @brief Cuboid local vertices
         */
        std::vector<Vector> local_vertices = std::vector<Vector> (8);

    public:
        /**
         * @brief Parametric constructor
         * @param file_name file name in which cuboid is saved
         * @param api pointer to a class that is connected with gnuplot
         */
        Cuboid(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api);
        /**
         * @brief Nonparameric constructor
         */
        Cuboid() = default;
        /**
         * @brief Copy constructor
         * @param Cub Cuboid object
         */
        Cuboid(const Cuboid & Cub) = default;
        /**
         * @brief Destructor
         */
        ~Cuboid() = default;
        /**
         * @brief Draw cuboid on scene
         */
        void draw() override;
        /**
         * @brief Rotate cuboid by a given angle around a given axis
         * @param angle Rotation angle
         * @param axis Rotation axis
         */
        void rotate(double angle, char axis) override;
        /**
         * @brief Move cuboid by a given vector
         * @param displacement Displacement vector
         */
        void move(const Vector & displacement) override;
};

#endif 
