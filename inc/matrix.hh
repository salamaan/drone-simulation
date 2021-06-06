#ifndef MATRIX_HH
#define MATRIX_HH

#include "vector.hh"

/** 
 * @brief Class for square matrix in the sense of linear algebra
 */
class Matrix {  
    protected:
        /**
         * @brief Matrix rows that are Vector objects
         */
        Vector rows[DIMENSION];

    public:
        /**
         * @brief Nonparametric constructor
         */
        Matrix() = default;
        /**
         * @brief Copy constructor
         * @param M Matrix object
         */
        Matrix(const Matrix & M) = default;
        /**
         * @brief Parametric constructor
         * @param V1 First row
         * @param V2 Second row
         * @param V3 Third row
         */
        Matrix(Vector V1, Vector V2, Vector V3);
        /**
         * @brief Destructor
         */
        ~Matrix() = default;
        /**
         * @brief Invert matrix
         * @return Inverse matrix
         */
        Matrix invert() const;
        /**
         * @brief get matrix column under specific index
         * @param idx Index of column
         * @return Matrix column
         */
        Vector getColumn(int idx) const;
        /** 
         * @brief Create unit matrix 
         * @return Unit matrix
         */
        Matrix createUnit() const;
        /**
         * @brief Swap rows under specific indexes
         * @param idx1 index of first row
         * @param idx2 index of second row
         */
        void swapRows(int idx1, int idx2);
        /**
         * @brief Calculate matrix determinant using Gauss method
         * @return Matrix determinant
         */
        double determinant() const;
        /**
         * @brief Transpose matrix 
         * @return Transposed matrix
         */
        Matrix transposition() const;
        /**
         * @brief Getter-type operator
         * @param idx Index of matrix row
         * @return Matrix row
         */
        const Vector & operator [] (int idx) const;
        /**
         * @brief Setter-type operator
         * @param idx Index of matrix row
         * @return Matrix row
         */
        Vector & operator [] (int idx);
        /**
         * @brief Operator of addition for two matrices
         * @param M2 Second Matrix
         * @return New matrix
         */
        Matrix operator + (const Matrix & M2) const;
        /**
         * @brief Operator of subtraction for two matrices
         * @param M2 Second Matrix
         * @return New matrix
         */
        Matrix operator - (const Matrix & M2) const;
        /**
         * @brief Operator of multiplication for two matrices
         * @param M2 Second Matrix
         * @return New matrix
         */
        Matrix operator * (const Matrix & M2) const;
        /**
         * @brief Operator of multiplication a matrix by a number
         * @param multipler Multipler 
         * @return New matrix
         */
        Matrix operator * (const double & multipler) const;
        /**
         * @brief Operator of multiplication a matrix by a vector
         * @param V Vector object 
         * @return New vector
         */
        Vector operator * (const Vector & V) const;
        /**
         * @brief Comparison operator for two matrices
         * @param M2 Second matrix
         * @return Boolean value
         * @retval True if matrices are identical
         * @retval False if matrices are diffrent
         */
        bool operator == (const Matrix & M2) const;
        /**
         * @brief Comparison operator for two matrices
         * @param M2 Second matrix
         * @return Boolean value
         * @retval True if matrices are diffrent
         * @retval False if matrices are identical
         */
        bool operator != (const Matrix & M2) const;
};

/**
 * @brief Right-shift operator for reading Matrices from a stream
 * @param str Input stream
 * @param M Matrix object
 * @return istream object
 */
std::istream & operator >> (std::istream & str, Matrix & M);

#endif
