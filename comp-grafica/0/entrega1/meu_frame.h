#ifndef MEU_FRAME_H
#define MEU_FRAME_H

#include <QFrame>
#include "display_file.h"
#include <vector>

class Meu_frame : public QFrame {
    Q_OBJECT
public:
    explicit Meu_frame(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    DisplayFile displayFile;
    std::vector<ObjetoGeometrico*> objetosVisiveis;

// public slots:
};

#endif // MEU_FRAME_H
