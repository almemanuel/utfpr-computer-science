#ifndef POLIGONO_H
#define POLIGONO_H

#include "objeto_geometrico.h"
#include <QList>
#include <QPointF>

class Poligono : public ObjetoGeometrico {
public:
    Poligono(QString nome, const QList<QPointF>& pontos);
    QList<QPointF> getPontos() const override;
    QPointF getCentro() const override;

private:
    QList<QPointF> pontos;
};

#endif
