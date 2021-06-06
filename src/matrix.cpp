#include "../inc/matrix.hh"
#include <cmath>

Matrix::Matrix(Vector V1, Vector V2, Vector V3) {
    this->rows[0] = V1;
    this->rows[1] = V2;
    this->rows[2] = V3;
}

const Vector & Matrix::operator [] (int idx) const {
    if(idx < 0 || idx >= DIMENSION) {
        std::cerr << "Error. Index out of range.\n";
        exit(1);
    }
    return this->rows[idx];
}

Vector & Matrix::operator [] (int idx) {
    if(idx < 0 || idx >= DIMENSION) {
        std::cerr << "Error. Index out of range.\n";
        exit(1);
    }
    return this->rows[idx];
}

Vector Matrix::getColumn(int idx) const {
    if(idx < 0 || idx >= DIMENSION) {
        std::cerr << "Error. Index out of range.\n";
        exit(1);
    }
    Vector V;

    for(int i = 0; i < DIMENSION; i++) {
        V[i] = this->rows[i][idx];       // swap row with a column
    }
    return V;
}

Matrix Matrix::createUnit() const {
    Matrix M;

    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            M[i][j] = 0.0;
        }
        M[i][i] = 1.0;
    }
    return M;
}

void Matrix::swapRows(int idx1, int idx2) {
    Vector tmp;

    tmp = this->rows[idx1];
    this->rows[idx1] = this->rows[idx2];
    this->rows[idx2] = tmp;
}

double Matrix::determinant() const {
    double det;
    det = 1;
    Matrix M = *this;
    double multipler;       

    // calculate determinant - Gauss method
    // under the main diagonal
    for(int i = 0; i < DIMENSION - 1; i++) {       
        for(int j = i + 1; j < DIMENSION; j++) {      
            if(abs(M[i][i]) < eps) {    // check whether current element is already zero
                for(int k = i + 1; k < DIMENSION; k++) {
                    // if it is then try to swap rows
                    if(abs(M[k][i]) >= eps) {
                        M.swapRows(i, k);
                        det *= (-1);
                        break;
                    }
                }
                // if we can't swap rows, then determinant is equal zero
                if(abs(M[i][i]) < eps) {
                    det = 0;
                    return det;
                }
            }
	        if(abs(M[j][i]) < eps) {
                break;
	        }
            multipler = -M[j][i] / M[i][i];      
            M[j] = M[j] + M[i] * multipler;      // reduce elements
        }
    }
    for(int i = 0; i < DIMENSION; i++) {
        det *= M[i][i];       // multiple elements on the main diagonal
    }
    return det;
}

Matrix Matrix::invert() const {
    Matrix diagnal = *this;   
    double multipler;      
    Matrix unit;
    unit = unit.createUnit();
    
    // invert matrix - Gauss method
    // under the main diagonal
    for(int i = 0; i < DIMENSION - 1; i++) {       
        for(int j = i + 1; j < DIMENSION; j++) {   
            if(abs(diagnal[i][i]) < eps) {     // check whether current element is already zero
                for(int k = i + 1; k < DIMENSION; k++) {
                    // if it is then try to swap rows
                    if(abs(diagnal[k][i]) >= eps) {
                        diagnal.swapRows(i, k);
                        unit.swapRows(i, k);
                        break;
                    }
                }
                // if we can't swap rows, then we can't invert matrix
                if(abs(diagnal[i][i]) < eps) {
                    std::cerr << "Error. Division by zero.\n";
                    exit(1);
                }
            }
            if(abs(diagnal[j][i]) < eps) {
                break;
	        }
            multipler = -diagnal[j][i] / diagnal[i][i];     
            diagnal[j] = diagnal[j] + diagnal[i] * multipler;       // reduce element
            unit[j] = unit[j] + unit[i] * multipler;        // reduce element
        }
    }
    // above the main diagonal
    for(int i = DIMENSION - 1; i > 0; i--) {  
        for(int j = i - 1; j >= 0; j--) {    
            if(abs(diagnal[i][i]) < eps) {                                     
                std::cerr << "Error. Division by zero.\n";
                exit(1);
            }
            if(abs(diagnal[j][i]) < eps) {
                break;
	        }
            multipler = -diagnal[j][i] / diagnal[i][i];
            diagnal[j] = diagnal[j] + diagnal[i] * multipler;
            unit[j] = unit[j] + unit[i] * multipler;
        }
    }
    for(int i = 0; i < DIMENSION; i++) {       
        unit[i] = unit[i] / diagnal[i][i];
    }
    return unit;
}

Matrix Matrix::transposition() const {
    Matrix result;

    for(int i = 0; i < DIMENSION; i++) {
        result[i] = this->getColumn(i);       // swap rows with columns
    }
    return result;
}

Matrix Matrix::operator + (const Matrix & M2) const {
    Matrix result;      

    for(int i = 0; i < DIMENSION; i++) {
        result[i] = this->rows[i] + M2[i];
    }
    return result;
}

Matrix Matrix::operator - (const Matrix & M2) const {
    Matrix result;      

    for(int i = 0; i < DIMENSION; i++) {
        result[i] = this->rows[i] - M2[i];
    }
    return result;
}

Matrix Matrix::operator * (const double & multipler) const {
    Matrix result;

    for(int i = 0; i < DIMENSION; i++) {
        result[i] = this->rows[i] * multipler;
    }
    return result;
}

Vector Matrix::operator * (const Vector & V) const {
    Vector result;

    for(int i = 0; i < DIMENSION; i++) {
        result[i] = this->rows[i] * V;
    }
    return result;
}

Matrix Matrix::operator * (const Matrix & M2) const {
    Matrix result;

    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            result[i][j] = this->rows[i] * M2.getColumn(j);
        }
    }
    return result;
}

bool Matrix::operator == (const Matrix & M2) const {
    Matrix M1 = *this;

    for(int i = 0; i < DIMENSION; ++i) {
        for(int j = 0; j < DIMENSION; ++j) {
            if(abs(M1[i][j] - M2[i][j]) >= eps) {
                return false;
            } 
        }
    }
    return true;
}

bool Matrix::operator != (const Matrix & M2) const {
    return !(*this == M2);
}

std::istream & operator >> (std::istream & str, Matrix & M) {
    for(int i = 0; i < DIMENSION; ++i) {
        str >> M[i];    
    }
    return str;
}
