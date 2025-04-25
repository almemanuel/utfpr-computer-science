#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "meu_frame.h"
#include "ponto.h"
#include "reta.h"
#include "poligono.h"
#include "display_file.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // --- Objetos fixos no mundo ---
    // Pontos
    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Ponto>("Ponto1", 0, 0));
    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Ponto>("Ponto2", 30, -40));

    // Retas
    ui->meuFrame->displayFile.adicionarObjeto(
        std::make_unique<Reta>("Reta1", QPointF(-80, -80), QPointF(-50, -50))
    );

    // Polígonos
    QList<QPointF> triangulo = { QPointF(150, 50), QPointF(125, 75), QPointF(200, 50) };
    ui->meuFrame->displayFile.adicionarObjeto(
        std::make_unique<Poligono>("Triangulo", triangulo)
    );

    QList<QPointF> retangulo = {
        QPointF(-130, -20), QPointF(-70, -20), QPointF(-70, 20), QPointF(-130, 20)
    };
    ui->meuFrame->displayFile.adicionarObjeto(
        std::make_unique<Poligono>("Retangulo", retangulo)
    );

    // --- Todos os objetos são visíveis por padrão ---
    for (const auto& obj : ui->meuFrame->displayFile.getObjetos()) {
        ui->meuFrame->objetosVisiveis.push_back(obj.get());
    }

    // Força o redesenho
    ui->meuFrame->update();
}


MainWindow::~MainWindow()
{
    delete ui;
}
