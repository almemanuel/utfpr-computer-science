#ifndef OBJETO_GEOMETRICO_H
#define OBJETO_GEOMETRICO_H

#include <QString>
#include <QList>
#include <QPointF>

class ObjetoGeometrico {
public:
    enum Tipo { PONTO, RETA, POLIGONO };

    ObjetoGeometrico(QString nome, Tipo tipo);
    virtual ~ObjetoGeometrico() = default;

    QString getNome() const;
    Tipo getTipo() const;

    float matrizTransformacao[3][3];

    void aplicarTransformacao(const float (&novaMatriz)[3][3]);

    virtual QList<QPointF> getPontos() const = 0;
    virtual QPointF getCentro() const = 0;

private:
    QString nome;
    Tipo tipo;
};

#endif
