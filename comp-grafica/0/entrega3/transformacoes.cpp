#define _USE_MATH_DEFINES
#include "transformacoes.h"
#include <cmath>
#include <cstring>

void Transformacoes::translacao(float (&matriz)[3][3], float dx, float dy) {
    float temp[3][3] = {{1,0,dx}, {0,1,dy}, {0,0,1}};
    memcpy(matriz, temp, sizeof(temp));
}

void Transformacoes::escala(float (&matriz)[3][3], float sx, float sy) {
    float temp[3][3] = {{sx,0,0}, {0,sy,0}, {0,0,1}};
    memcpy(matriz, temp, sizeof(temp));
}

void Transformacoes::rotacao(float (&matriz)[3][3], float angulo) {
    angulo = fmod(angulo, 360.0f);
    if (angulo < 0) angulo += 360.0f;

    float radianos = angulo * M_PI / 180.0f;
    float cosTheta = cos(radianos);
    float sinTheta = sin(radianos);

    float temp[3][3] = {{cosTheta, -sinTheta, 0}, {sinTheta, cosTheta, 0}, {0,0,1}};
    memcpy(matriz, temp, sizeof(temp));
}

void Transformacoes::multiplicarMatrizes(float (&resultado)[3][3], const float (&A)[3][3], const float (&B)[3][3]) {
    float temp[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    memcpy(resultado, temp, sizeof(temp));
}
