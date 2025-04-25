#include "ponto.h"

Ponto::Ponto(QString nome, float x, float y)
    : ObjetoGeometrico(nome, PONTO), coordenada(x, y) {}

QList<QPointF> Ponto::getPontos() const {
    return {coordenada};
}
