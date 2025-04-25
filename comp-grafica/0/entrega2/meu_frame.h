#ifndef MEU_FRAME_H
#define MEU_FRAME_H

#include <QFrame>
#include <QPointF>
#include "display_file.h"
#include <vector>

class Meu_frame : public QFrame {
    Q_OBJECT
public:
    explicit Meu_frame(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    // Variáveis da Window
    double windowXMin = -100, windowXMax = 100;
    double windowYMin = -100, windowYMax = 100;

    // Variáveis da Viewport
    double viewportUMin = 0.1, viewportUMax = 0.9;
    double viewportVMin = 0.1, viewportVMax = 0.9;

    // Objetos
    DisplayFile displayFile;
    std::vector<ObjetoGeometrico*> objetosVisiveis;

private:
    // Limites do mundo
    const double MUNDO_X_MIN = -250;
    const double MUNDO_X_MAX = 250;
    const double MUNDO_Y_MIN = -100;
    const double MUNDO_Y_MAX = 100;

protected:
    // Controle do mouse
    bool arrastando = false;
    QPointF mousePosInicial;
    QPointF windowPosInicial;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif
