#include "poligono.h"

Poligono::Poligono(QString nome, const QList<QPointF>& pontos)
    : ObjetoGeometrico(nome, POLIGONO), pontos(pontos) {}

QList<QPointF> Poligono::getPontos() const {
    QList<QPointF> pontos_transformados;
    for (QPointF p : pontos) {
        float x = p.x();
        float y = p.y();
        pontos_transformados.append(QPointF(
            matrizTransformacao[0][0] * x + matrizTransformacao[0][1] * y + matrizTransformacao[0][2],
            matrizTransformacao[1][0] * x + matrizTransformacao[1][1] * y + matrizTransformacao[1][2]
            ));
    }
    return pontos_transformados;
}

QPointF Poligono::getCentro() const {
    float somaX = 0, somaY = 0;
    for (const QPointF& p : pontos) {
        somaX += p.x();
        somaY += p.y();
    }
    return QPointF(
        somaX / pontos.size(), // Média X
        somaY / pontos.size()  // Média Y
        );
}
