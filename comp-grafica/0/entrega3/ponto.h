#ifndef PONTO_H
#define PONTO_H

#include "objeto_geometrico.h"

class Ponto : public ObjetoGeometrico {
public:
    Ponto(QString nome, float x, float y);
    QList<QPointF> getPontos() const override;
    Ponto(QString nome, QPointF coordenada);
    QPointF getCentro() const override;

private:
    QPointF coordenada;
    QPointF coordenadaOriginal;
};

#endif
