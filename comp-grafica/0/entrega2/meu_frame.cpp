// meu_frame.cpp
#include "meu_frame.h"
#include <QPainter>
#include <QMouseEvent>  // Adicione esta linha
#include "ponto.h"
#include "reta.h"
#include "poligono.h"
#include "transformacao.h"

Meu_frame::Meu_frame(QWidget *parent) : QFrame(parent) {
    setMouseTracking(true);
}

QPointF mundoParaSCN(const QPointF& pMundo,
                     double xMin, double xMax,
                     double yMin, double yMax) {
    double xNorm = 2 * (pMundo.x() - xMin) / (xMax - xMin) - 1;
    double yNorm = 2 * (pMundo.y() - yMin) / (yMax - yMin) - 1;
    return QPointF(xNorm, yNorm);
}

QPointF SCNParaViewport(const QPointF& pSCN,
                        double uMin, double uMax,
                        double vMin, double vMax) {
    double u = uMin + (pSCN.x() + 1) * (uMax - uMin) / 2;
    double v = vMin + (pSCN.y() + 1) * (vMax - vMin) / 2;
    return QPointF(u, v);
}


void Meu_frame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    // Calcula proporções para evitar distorção
    double aspectWindow = (windowXMax - windowXMin) / (windowYMax - windowYMin);
    double aspectViewport = (viewportUMax - viewportUMin) / (viewportVMax - viewportVMin);

    // Ajusta a viewport para manter a proporção da window
    if (aspectWindow > aspectViewport) {
        double novoVSize = (viewportVMax - viewportVMin) * aspectViewport / aspectWindow;
        viewportVMin = 0.5 - novoVSize/2;
        viewportVMax = 0.5 + novoVSize/2;
    } else {
        double novoUSize = (viewportUMax - viewportUMin) * aspectWindow / aspectViewport;
        viewportUMin = 0.5 - novoUSize/2;
        viewportUMax = 0.5 + novoUSize/2;
    }

    // Transformação completa: Mundo → SCN → Viewport
    auto transformar = [&](const QPointF& pMundo) -> QPointF {
        QPointF pSCN = mundoParaSCN(pMundo, windowXMin, windowXMax, windowYMin, windowYMax);
        return SCNParaViewport(
            pSCN,
            viewportUMin * width(), viewportUMax * width(),
            viewportVMin * height(), viewportVMax * height()
            );
    };

    // Desenha todos os objetos visíveis
    painter.setPen(Qt::black);
    for (auto obj : objetosVisiveis) {
        switch (obj->getTipo()) {
        case ObjetoGeometrico::PONTO: {
            QPointF p = transformar(obj->getPontos().first());
            painter.drawPoint(p);
            break;
        }
        case ObjetoGeometrico::RETA: {
            QPointF p1 = transformar(obj->getPontos()[0]);
            QPointF p2 = transformar(obj->getPontos()[1]);
            painter.drawLine(p1, p2);
            break;
        }
        case ObjetoGeometrico::POLIGONO: {
            QPolygonF poligono;
            for (const QPointF& p : obj->getPontos()) {
                poligono << transformar(p);
            }
            painter.drawPolygon(poligono);
            break;
        }
        }
    }
}

// --- Controle do Mouse ---
void Meu_frame::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        arrastando = true;
        mousePosInicial = event->pos();
        windowPosInicial = QPointF(windowXMin, windowYMin);
    }
}

void Meu_frame::mouseMoveEvent(QMouseEvent* event) {
    if (arrastando && (event->buttons() & Qt::LeftButton)) {
        QPointF deslocamentoPixel = event->pos() - mousePosInicial;

        double tamanhoWindowX = windowXMax - windowXMin;
        double tamanhoWindowY = windowYMax - windowYMin;

        // Conversão para unidades do mundo
        double dxMundo = deslocamentoPixel.x() * tamanhoWindowX / width();
        double dyMundo = deslocamentoPixel.y() * tamanhoWindowY / height();

        // Aplica deslocamento
        double novoXMin = windowPosInicial.x() - dxMundo;
        double novoXMax = novoXMin + tamanhoWindowX;
        double novoYMin = windowPosInicial.y() + dyMundo;
        double novoYMax = novoYMin + tamanhoWindowY;

        // Aplica o deslocamento à POSIÇÃO INICIAL
        windowXMin = windowPosInicial.x() - dxMundo;
        windowXMax = windowXMin + tamanhoWindowX;
        windowYMin = windowPosInicial.y() - dyMundo;
        windowYMax = windowYMin + tamanhoWindowY;

        // Aplica travas nos limites (clamping)
        if (novoXMin < MUNDO_X_MIN) {
            novoXMin = MUNDO_X_MIN;
            novoXMax = novoXMin + tamanhoWindowX;
        }
        else if (novoXMax > MUNDO_X_MAX) {
            novoXMax = MUNDO_X_MAX;
            novoXMin = novoXMax - tamanhoWindowX;
        }

        if (novoYMin < MUNDO_Y_MIN) {
            novoYMin = MUNDO_Y_MIN;
            novoYMax = novoYMin + tamanhoWindowY;
        }
        else if (novoYMax > MUNDO_Y_MAX) {
            novoYMax = MUNDO_Y_MAX;
            novoYMin = novoYMax - tamanhoWindowY;
        }

        // Atualiza a window
        windowXMin = novoXMin;
        windowXMax = novoXMax;
        windowYMin = novoYMin;
        windowYMax = novoYMax;

        update();
    }
}

void Meu_frame::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        arrastando = false;
    }
}
