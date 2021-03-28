#pragma once
#ifndef COR_N
#define COR_N

class Cor {
    public:
        Cor();
        Cor(int r, int g, int b);
        ~Cor();
        inline float* getCor() {return cor;};
    private:
        void setCor(int r, int g, int b);
        float cor[3];
};

#endif //COR_H