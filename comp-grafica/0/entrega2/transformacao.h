#ifndef TRANSFORMACAO_H
#define TRANSFORMACAO_H

#include <QPointF>

class Transformacao {
public:
    static QPointF mundoParaSCN(
        const QPointF& pontoMundo,
        double xMin, double xMax,
        double yMin, double yMax
        );

    static QPointF SCNParaViewport(
        const QPointF& pontoSCN,
        double uMin, double uMax,
        double vMin, double vMax
        );
};

#endif
