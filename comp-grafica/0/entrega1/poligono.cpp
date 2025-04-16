#include "poligono.h"

Poligono::Poligono(QString nome, const QList<QPointF>& pontos)
    : ObjetoGeometrico(nome, POLIGONO), pontos(pontos) {}

QList<QPointF> Poligono::getPontos() const {
    return pontos;
}
