#ifndef MEU_FRAME_H
#define MEU_FRAME_H

#include <QFrame>
#include <QPaintEvent>
#include <QRect>

class Meu_frame : public QFrame
{
    Q_OBJECT
private:
    QRect rec;
public:
    explicit Meu_frame(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

public slots:
    void muda();

signals:
};

#endif // MEU_FRAME_H
