#include "transformacao.h"
#include <QPointF>

QPointF Transformacao::mundoParaSCN(
    const QPointF& pontoMundo,
    double xMin, double xMax,
    double yMin, double yMax
    ) {
    double xNorm = 2 * (pontoMundo.x() - xMin) / (xMax - xMin) - 1;
    double yNorm = 2 * (pontoMundo.y() - yMin) / (yMax - yMin) - 1;
    return QPointF(xNorm, yNorm);
}

QPointF Transformacao::SCNParaViewport(
    const QPointF& pontoSCN,
    double uMin, double uMax,
    double vMin, double vMax
    ) {
    double u = uMin + (pontoSCN.x() + 1) * (uMax - uMin) / 2;
    double v = vMin + (pontoSCN.y() + 1) * (vMax - vMin) / 2;
    return QPointF(u, v);
}
