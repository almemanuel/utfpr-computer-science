#ifndef RETA_H
#define RETA_H

#include "objeto_geometrico.h"

class Reta : public ObjetoGeometrico {
public:
    Reta(QString nome, QPointF inicio, QPointF fim);
    QList<QPointF> getPontos() const override;
    QPointF getCentro() const override;

private:
    QPointF inicio;
    QPointF fim;
    QPointF aplicarMatriz(QPointF ponto) const;
};

#endif
