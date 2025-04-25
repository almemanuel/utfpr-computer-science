#ifndef PONTO_H
#define PONTO_H

#include "objeto_geometrico.h"

class Ponto : public ObjetoGeometrico {
public:
    Ponto(QString nome, float x, float y);
    QList<QPointF> getPontos() const override;

private:
    QPointF coordenada;
};

#endif
