#include "objeto_geometrico.h"

ObjetoGeometrico::ObjetoGeometrico(QString nome, Tipo tipo)
    : nome(nome), tipo(tipo)
{
    // Matriz identidade
    matrizTransformacao[0][0] = 1.0f; matrizTransformacao[0][1] = 0.0f; matrizTransformacao[0][2] = 0.0f;
    matrizTransformacao[1][0] = 0.0f; matrizTransformacao[1][1] = 1.0f; matrizTransformacao[1][2] = 0.0f;
    matrizTransformacao[2][0] = 0.0f; matrizTransformacao[2][1] = 0.0f; matrizTransformacao[2][2] = 1.0f;
}

QString ObjetoGeometrico::getNome() const {
    return nome;
}

ObjetoGeometrico::Tipo ObjetoGeometrico::getTipo() const {
    return tipo;
}

void ObjetoGeometrico::aplicarTransformacao(const float (&novaMatriz)[3][3]) {
    float temp[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                temp[i][j] += novaMatriz[i][k] * matrizTransformacao[k][j];
            }
        }
    }

    memcpy(matrizTransformacao, temp, sizeof(temp));
}
