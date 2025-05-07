#ifndef TRANSFORMACOES_H
#define TRANSFORMACOES_H

class Transformacoes {
public:
    static void translacao(float (&matriz)[3][3], float dx, float dy);
    static void escala(float (&matriz)[3][3], float sx, float sy);
    static void rotacao(float (&matriz)[3][3], float angulo);
    static void multiplicarMatrizes(float (&resultado)[3][3], const float (&A)[3][3], const float (&B)[3][3]);
};

#endif
