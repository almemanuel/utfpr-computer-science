#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "meu_frame.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(
        ui->pushButton_2, // Nome do botão no Qt Designer
        &QPushButton::clicked, // Sinal "clicked()"
        ui->myframe, // Nome do frame (Meu_frame)
        &Meu_frame::muda // Slot que modifica o retângulo
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}
