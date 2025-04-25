#include "reta.h"

Reta::Reta(QString nome, QPointF inicio, QPointF fim)
    : ObjetoGeometrico(nome, RETA), inicio(inicio), fim(fim) {}

QList<QPointF> Reta::getPontos() const {
    return {inicio, fim};
}
