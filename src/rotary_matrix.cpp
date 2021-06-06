#include "../inc/rotary_matrix.hh"
#include <cmath>

RotaryMatrix::RotaryMatrix() {
    Matrix M;
    *this = M.createUnit();
}

RotaryMatrix::RotaryMatrix(const Matrix & M) {
    if(M * M.transposition() != M.transposition() * M) {
        std::cerr << "Error. This is not orthogonal matrix.\n";
        exit(1);
    }
    for(int i = 0; i < DIMENSION; ++i) {
        this->rows[i] = M[i];
    }
}

RotaryMatrix::RotaryMatrix(double angle, char axis) {
    switch(axis) {
        case 'x': {
            Vector V1(1.0, 0.0, 0.0);
            Vector V2(0.0, cos(angle*M_PI/180), -sin(angle*M_PI/180));
            Vector V3(0.0, sin(angle*M_PI/180), cos(angle*M_PI/180));
            Matrix M(V1, V2, V3);
            RotaryMatrix R_M(M);
            *this = R_M;
            break;
        }
        case 'y': {
            Vector V1(cos(angle*M_PI/180), 0.0, sin(angle*M_PI/180));
            Vector V2(0.0, 1.0, 0.0);
            Vector V3(-sin(angle*M_PI/180), 0.0, cos(angle*M_PI/180));
            Matrix M(V1, V2, V3);
            RotaryMatrix R_M(M);
            *this = R_M;
            break;
        }
        case 'z': {
            Vector V1(cos(angle*M_PI/180), -sin(angle*M_PI/180), 0.0);
            Vector V2(sin(angle*M_PI/180), cos(angle*M_PI/180), 0.0);
            Vector V3(0.0, 0.0, 1.0);
            Matrix M(V1, V2, V3);
            RotaryMatrix R_M(M);
            *this = R_M;
            break;
        }
    }
}
