#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <windows.h>
#include <GL/gl.h>

#include "Ponto.h"

using namespace std;

enum Poligono{TRIANG = 3, QUAD = 4};

struct face {
    Poligono poligono;    
    int vertice[4];
    int normal[4];
    face(Poligono tipo,
        int v1, int v2, int v3, int v4,
        int n1, int n2, int n3, int n4) {
        vertice[0] = v1; vertice[1] = v2;
        vertice[2] = v3; vertice[3] = v4;
        normal[0] = n1; normal[1] = n2;
        normal[2] = n3; normal[3] = n4;
        poligono = tipo;
        
    }
};

namespace ObjLoader {
    Ponto getVertice(string s);
    Ponto getNormal(string s);
    face getFace(Poligono tipo, string s);
    void loadObj(unsigned& id, const char* file);
};