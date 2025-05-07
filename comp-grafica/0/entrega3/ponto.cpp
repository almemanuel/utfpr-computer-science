#include "ponto.h"

Ponto::Ponto(QString nome, float x, float y)
    : ObjetoGeometrico(nome, PONTO), coordenada(x, y) {}


QList<QPointF> Ponto::getPontos() const {
    // Aplica a matriz de transformação
    float x = coordenada.x();
    float y = coordenada.y();
    float x_new = matrizTransformacao[0][0] * x + matrizTransformacao[0][1] * y + matrizTransformacao[0][2];
    float y_new = matrizTransformacao[1][0] * x + matrizTransformacao[1][1] * y + matrizTransformacao[1][2];
    return {QPointF(x_new, y_new)};
}

QPointF Ponto::getCentro() const {
    return coordenada; // Centro é o próprio ponto
}
