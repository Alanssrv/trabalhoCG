#include "Cor.h"

Cor::Cor(){
    setCor(0, 0, 0);
}

Cor::Cor(int r, int g, int b) {
    setCor(r, g, b);
}

Cor::~Cor(){}

void Cor::setCor(int r, int g, int b) {
    r = (r > 255) ? 255 : (r < 0 ? 0 : r);
    g = (g > 255) ? 255 : (g < 0 ? 0 : g);
    b = (b > 255) ? 255 : (b < 0 ? 0 : b);

    cor[0] = r/255.0;
    cor[1] = g/255.0;
    cor[2] = b/255.0;
};