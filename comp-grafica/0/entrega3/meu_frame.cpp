#include "meu_frame.h"
#include <QPainter>
#include "ponto.h"
#include "reta.h"
#include "poligono.h"

Meu_frame::Meu_frame(QWidget *parent) : QFrame(parent) {}

void Meu_frame::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);

    // Define a região do mundo
    QRectF mundo(-100, -100, 200, 200); // X: -100 a +100, Y: -100 a +100

    painter.setWindow(mundo.toRect());   // Sistema de coordenadas do mundo
    painter.setViewport(rect());         // Área física da viewport (pixels)

    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);

    for (auto objeto : objetosVisiveis) {
        switch (objeto->getTipo()) {
            case ObjetoGeometrico::PONTO:
                painter.drawPoint(objeto->getPontos().first());
                break;
            case ObjetoGeometrico::RETA: {
                QPointF inicio = objeto->getPontos()[0];
                QPointF fim = objeto->getPontos()[1];
                painter.drawLine(inicio, fim);
                break;
            }
        case ObjetoGeometrico::POLIGONO: {
                QPolygonF poligono;
                for (const QPointF& ponto : objeto->getPontos()) {
                    poligono << ponto;
                }
                painter.drawPolygon(poligono);
                break;
            }
        }
    }
}
