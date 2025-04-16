#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "meu_frame.h"
#include "ponto.h"
#include "reta.h"
#include "poligono.h"
#include "display_file.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Ponto>("Ponto", 0, 0));
    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Reta>("Reta", QPointF(50, -50), QPointF(70, -70)));

    QList<QPointF> pontosPoligono = {
        QPointF(-50, -50),
        QPointF(50, -50),
        QPointF(0, 50)
    };
    ui->meuFrame->displayFile.adicionarObjeto(
        std::make_unique<Poligono>("Polígono", pontosPoligono)
    );

    for (const auto& obj : ui->meuFrame->displayFile.getObjetos()) {
        ui->listWidgetObjetos->addItem(obj->getNome());
    }

    connect(ui->btnDesenhar, &QPushButton::clicked, this, &MainWindow::on_btnDesenhar_clicked);
}

void MainWindow::on_btnDesenhar_clicked() {
    // Limpa os objetos visíveis
    ui->meuFrame->objetosVisiveis.clear();

    // Obtém os itens selecionados
    QList<QListWidgetItem*> selecionados = ui->listWidgetObjetos->selectedItems();

    // Adiciona os selecionados à lista de visíveis
    for (auto item : selecionados) {
        QString nome = item->text();
        for (const auto& obj : ui->meuFrame->displayFile.getObjetos()) {
            if (obj->getNome() == nome) {
                ui->meuFrame->objetosVisiveis.push_back(obj.get());
                break;
            }
        }
    }

    // Atualiza a viewport
    ui->meuFrame->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
