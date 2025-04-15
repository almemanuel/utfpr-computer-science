#include "meu_frame.h"
#include <QPainter>
#include <iostream>

using namespace std;

Meu_frame::Meu_frame(QWidget *parent)
    : QFrame(parent) // , rec(0, 0, 100, 50)
{}

void Meu_frame::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 2));

    painter.drawRect(rec);
}


void Meu_frame::muda() {
    rec.adjust(5, 5, 2, 2);
    update();
}
