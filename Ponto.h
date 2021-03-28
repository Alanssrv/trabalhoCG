#pragma once
#ifndef PONTO_H
#define PONTO_H

#include<cmath>

class Ponto {
    public:
        Ponto();
        Ponto(float x, float y, float z);
        ~Ponto();
        float mag();
        void normaliza();
        Ponto operator*(float k)const;
        Ponto operator+(const Ponto& v)const;
        Ponto operator-(const Ponto& v)const;
    private:
        void setCoord(float x, float y, float z);
        float coord[3];
    public:
        inline float getX() {return coord[0];};
        inline float getY() {return coord[1];};
        inline float getZ() {return coord[2];};
        inline float* getCoord() {return coord;};
};

#endif // PONTO_H