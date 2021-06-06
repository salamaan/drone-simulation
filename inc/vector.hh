#ifndef VECTOR_HH
#define VECTOR_HH
 
#include <iostream>
#include <fstream>
#include "epsilon.hh"
#include "Dr3D_gnuplot_api.hh"

#define DIMENSION 3

/**
 * @brief Class for vector of coordinates in the sense of linear algebra
 */
class Vector {
        /**
        * @brief Vector coordinates (x, y, z)
        */
        double data[DIMENSION];

    public:
        /**
         * @brief Parametric constructor
         * @param x x coordinate
         * @param y y coordinate
         * @param z z coordinate
         */
        Vector(double x, double y, double z);
        /**
         * @brief Nonparametric constructor
        */ 
        Vector() = default;
        /**
         * @brief Copy constructor
         * @param V Vector object
         */ 
        Vector(const Vector & V) = default;
        /**
         * @brief Destructor
         */ 
        ~Vector() = default;
        /**
         * @brief Calculate vector length
         * @return Vector length
         */ 
        double length() const;
        /**
         * @brief Scalar product operator
         * @param V2 Second Vector
         * @return Scalar product of two vectors
         */
        double operator * (const Vector & V2) const;
        /**
         * @brief Operator of multiplication a vector by a number
         * @param multipler Multipler 
         * @return New vector
         */
        Vector operator * (const double & multipler) const;
        /**
         * @brief Operator of division a vector by a number
         * @param divider Divider
         * @return New vector 
         */
        Vector operator / (const double & divider) const;
        /**
         * @brief Operator of addition for two vectors
         * @param V2 Second Vector
         * @return New vector
         */
        Vector operator + (const Vector & V2) const;
        /**
         * @brief Operator of subtraction for two vectors
         * @param V2 Second Vector
         * @return New vector
         */
        Vector operator - (const Vector & V2) const;
        /**
         * @brief Setter-type operator
         * @param idx Index of vector coordinate
         * @return Vector coordinate
         */
        double & operator [] (int idx);
        /**
         * @brief Getter-type operator
         * @param idx Index of vector coordinate
         * @return Vector coordinate
         */
        const double & operator [] (int idx) const;
};

/**
 * @brief Convert Vector object to Point3D object
 * @param V Vector object
 * @return Point3D object
 */
drawNS::Point3D Vector2Point(const Vector & V);
/**
 * @brief Right-shift operator for reading Vectors from a stream
 * @param str Input stream
 * @param V Vector object
 * @return istream object
 */
std::istream & operator >> (std::istream & str, Vector & V);

#endif
