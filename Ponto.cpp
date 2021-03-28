#include "Ponto.h"

Ponto::Ponto(float x, float y, float z){
    setCoord(x, y, z);
}

Ponto::Ponto(){
    setCoord(0, 0, 0);
}

Ponto::~Ponto(){}

void Ponto::setCoord(float x, float y, float z) {
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
}

float Ponto::mag(){
    return sqrt(pow(coord[0], 2) + pow(coord[1], 2) + pow(coord[2], 2));
}

void Ponto::normaliza(){
    float m = mag();
    coord[0] = coord[0]/m;
    coord[1] = coord[1]/m;
    coord[2] = coord[2]/m;
}

Ponto Ponto::operator*(float k)const { 
    return Ponto(coord[0]*k, coord[1]*k, coord[2]*k);
}

Ponto Ponto::operator+(const Ponto& v)const { 
    return Ponto(coord[0] + v.coord[0], coord[1] + v.coord[1], coord[2] + v.coord[2]); 
}

Ponto Ponto::operator-(const Ponto & v) const{
    return Ponto(coord[0] - v.coord[0], coord[1] - v.coord[1], coord[2] - v.coord[2]);
}