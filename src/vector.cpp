#include "../inc/vector.hh"
#include <cmath>

Vector::Vector(double x, double y, double z) {
    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;
}

double Vector::length() const {
    double length = 0;     

    for(int i = 0; i < DIMENSION; i++) {      
        length += pow(this->data[i], 2);
    }
    return sqrt(length);      
}

double Vector::operator * (const Vector & V2) const {
    double result;
    result = 0;

    for(int i = 0; i < DIMENSION; i++) {    
        result += this->data[i] * V2[i];
    }
    return result;
}

Vector Vector::operator * (const double & multipler) const {
    Vector result; 

    for(int i = 0; i < DIMENSION; i++) {   
        result[i] = this->data[i] * multipler;
    }
    return result;
}

Vector Vector::operator / (const double & divider) const {
    Vector result;      

    if(abs(divider) < eps) {
        std::cerr << "Error. Division by zero.\n";
        exit(1);
    }
    for(int i = 0; i < DIMENSION; i++) {      
        result[i] = this->data[i] / divider;
    }
    return result;
}

Vector Vector::operator + (const Vector & V2) const {
    Vector result;     

    for(int i = 0; i < DIMENSION; i++) {     
        result[i] = this->data[i] + V2[i];
    }
    return result;
}

Vector Vector::operator - (const Vector & V2) const {
    Vector result;   

    for(int i = 0; i < DIMENSION; i++) {        
        result[i] = this->data[i] - V2[i];
    }
    return result;
}

double & Vector::operator [] (int idx) {
    if(idx < 0 || idx >= DIMENSION) {
        std::cerr << "Error: Index out of range.\n";
        exit(1);
    }
    return this->data[idx];
}

const double & Vector::operator [] (int idx) const {
    if(idx < 0 || idx >= DIMENSION) {
        std::cerr << "Error: Index out of range.\n";
        exit(1);
    }
    return this->data[idx];
}

drawNS::Point3D Vector2Point(const Vector & V) {
    drawNS::Point3D point(0, 0, 0);

    for(int i = 0; i < DIMENSION; ++i) {
        point[i] = V[i];
    }
    return point;
}

std::istream & operator >> (std::istream & str, Vector & V) {
    for(int i = 0; i < DIMENSION; i++) {
        str >> V[i];    
    }
    return str;
}