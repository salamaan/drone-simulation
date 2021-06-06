#ifndef HEX_PRISM_HH
#define HEX_PRISM_HH

#include "figure3D.hh"

/**
 * @brief Class representing hex prism.
 */
class HexPrism : public Figure3D {
    protected:
        /**
         * @brief Hex prism global vertices
         */
        std::vector<Vector> global_vertices = std::vector<Vector> (12);
        /**
         * @brief Hex prism local vertices
         */
        std::vector<Vector> local_vertices = std::vector<Vector> (12);

    public:
        /**
         * @brief Parametric constructor
         * @param file_name file name in which hex prism is saved
         * @param api pointer to a class that is connected with gnuplot
         */
        HexPrism(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api);
        /**
         * @brief Nonparametric constructor
         */
        HexPrism() = default;
        /**
         * @brief rysuje graniastoslup szesciakatny na scenie
         */
        /**
         * @brief Copy constructor
         * @param H_P HexPrism object
         */
        HexPrism(const HexPrism & H_P) = default;
        /**
         * @brief destruktor
         */
        ~HexPrism() = default;
        /**
         * @brief Draw hex prism on scene
         */
        void draw() override;
        /**
         * @brief Rotate hex prism by a given angle around a given axis
         * @param angle Rotation angle
         * @param axis Rotation axis
         */
        void rotate(double angle, char axis) override;
        /**
         * @brief Move hex prism by a given vector
         * @param displacement Displacement vector
         */
        void move(const Vector & displacement) override;
};

#endif 