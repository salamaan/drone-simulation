#ifndef ROTARY_MATRIX_HH
#define ROTARY_MATRIX_HH

#include "matrix.hh"

/**
 * @brief Class for rotary matrix in the sense of linear algebra
 */
class RotaryMatrix : public Matrix {
    public:
        /**
         * @brief Parametric constructor with orthogonal matrix
         * @param M Orthogonal matrix
         */
        RotaryMatrix(const Matrix & M);
        /**
         * @brief Nonparametric constructor, creates unit rotary matrix(orthogonal matrix)
         */
        RotaryMatrix();
        /**
         * @brief Copy constructor
         * @param R_M RotaryMatrix object
         */
        RotaryMatrix(const RotaryMatrix & R_M) = default;
        /**
         * @brief Parametric constructor with angle and axis
         * @param angle Rotation angle
         * @param axis Rotation axis
         */
        RotaryMatrix(double angle, char axis);
        /**
         * @brief Destructor
         */
        ~RotaryMatrix() = default;
};

#endif