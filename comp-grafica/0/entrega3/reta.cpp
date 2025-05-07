#include "reta.h"

Reta::Reta(QString nome, QPointF inicio, QPointF fim)
    : ObjetoGeometrico(nome, RETA), inicio(inicio), fim(fim) {}

QList<QPointF> Reta::getPontos() const {
    QPointF inicio_transformado = aplicarMatriz(inicio);
    QPointF fim_transformado = aplicarMatriz(fim);
    return {inicio_transformado, fim_transformado};
}

QPointF Reta::aplicarMatriz(QPointF ponto) const {
    float x = ponto.x();
    float y = ponto.y();
    float w = 1.0f; // Coordenada homogênea

    // Aplica a matriz de transformação do objeto
    float x_new = this->matrizTransformacao[0][0] * x + this->matrizTransformacao[0][1] * y + this->matrizTransformacao[0][2] * w;
    float y_new = this->matrizTransformacao[1][0] * x + this->matrizTransformacao[1][1] * y + this->matrizTransformacao[1][2] * w;

    return QPointF(x_new, y_new);
}

QPointF Reta::getCentro() const {
    return QPointF(
        (inicio.x() + fim.x()) / 2.0f, // Média X
        (inicio.y() + fim.y()) / 2.0f  // Média Y
        );
}
