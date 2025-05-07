#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ponto.h"
#include "reta.h"
#include "poligono.h"
#include "transformacoes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupObjetosIniciais();
    configurarUI();
    conectarSinais();
}

void MainWindow::setupObjetosIniciais()
{
    QList<QPointF> pontosPoligono = {QPointF(-50, -50), QPointF(50, -50), QPointF(0, 50)};
    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Poligono>("Triângulo", pontosPoligono));
    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Reta>("Reta", QPointF(50, -50), QPointF(70, -70)));
    ui->meuFrame->displayFile.adicionarObjeto(std::make_unique<Ponto>("Ponto", 0, 0));

    for (const auto& obj : ui->meuFrame->displayFile.getObjetos()) {
        ui->listWidgetObjetos->addItem(obj->getNome());
    }
}

void MainWindow::configurarUI()
{
    // Configurar combobox de transformações
    ui->comboTransformacoes->clear();
    ui->comboTransformacoes->addItems({"Selecione", "Translação", "Escala", "Rotação"});

    // Esconder parâmetros inicialmente
    ui->leParam1->setVisible(false);
    ui->leParam2->setVisible(false);
    ui->leParam3->setVisible(false);
    ui->labelParam1->setVisible(false);
    ui->labelParam2->setVisible(false);
    ui->labelParam3->setVisible(false);
}

void MainWindow::conectarSinais()
{
    connect(ui->btnDesenhar, &QPushButton::clicked, this, &MainWindow::onExibirClicked);
    connect(ui->btnAplicarTransformacao, &QPushButton::clicked, this, &MainWindow::onTransformarClicked);
    connect(ui->btnAdicionarTransformacao, &QPushButton::clicked, this, &MainWindow::onAdicionarTransformacaoClicked);
    connect(ui->comboTransformacoes, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onTipoTransformacaoMudou);
}

void MainWindow::atualizarListaTransformacao()
{
    ui->listTransformarObjetos->clear();
    for (auto item : ui->listWidgetObjetos->selectedItems()) {
        ui->listTransformarObjetos->addItem(item->text());
    }
}

ObjetoGeometrico* MainWindow::buscarObjeto(const QString& nome) const
{
    for (const auto& obj : ui->meuFrame->displayFile.getObjetos()) {
        if (obj->getNome() == nome) {
            return obj.get();
        }
    }
    return nullptr;
}

void MainWindow::onExibirClicked()
{
    // Limpa os objetos visíveis e a lista de transformação
    ui->meuFrame->objetosVisiveis.clear();
    ui->listTransformarObjetos->clear();

    // Adiciona os selecionados tanto aos visíveis quanto à lista de transformação
    for (auto item : ui->listWidgetObjetos->selectedItems()) {
        QString nome = item->text();
        if (auto obj = buscarObjeto(nome)) {
            ui->meuFrame->objetosVisiveis.push_back(obj);

            // Adiciona à lista de transformação
            if (ui->listTransformarObjetos->findItems(nome, Qt::MatchExactly).empty()) {
                ui->listTransformarObjetos->addItem(nome);
            }
        }
    }

    ui->meuFrame->update();
}

void MainWindow::onAdicionarTransformacaoClicked()
{
    auto selecionados = ui->listWidgetObjetos->selectedItems();
    if (selecionados.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Selecione um objeto na lista principal!");
        return;
    }
    QString nome = selecionados.first()->text();
    if (ui->listTransformarObjetos->findItems(nome, Qt::MatchExactly).empty()) {
        ui->listTransformarObjetos->addItem(nome);
    }
}

void MainWindow::onTransformarClicked()
{
    if (ui->listTransformarObjetos->selectedItems().isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Selecione um objeto para transformar!");
        return;
    }

    QString nomeObjeto = ui->listTransformarObjetos->currentItem()->text();
    auto obj = buscarObjeto(nomeObjeto);
    if (!obj) {
        QMessageBox::critical(this, "Erro", "Objeto não encontrado!");
        return;
    }

    // Obter parâmetros
    bool ok1, ok2;
    float param1 = ui->leParam1->text().toFloat(&ok1);
    float param2 = ui->leParam2->text().toFloat(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Erro", "Parâmetros inválidos!");
        return;
    }

    // Aplicar transformação
    float matriz[3][3];
    QString transformacao = ui->comboTransformacoes->currentText();

    if (transformacao == "Translação") {
        Transformacoes::translacao(matriz, param1, param2);
    }
    else if (transformacao == "Escala") {
        QPointF centro = obj->getCentro();
        float T1[3][3], S[3][3], T2[3][3], temp[3][3];
        Transformacoes::translacao(T1, -centro.x(), -centro.y());
        Transformacoes::escala(S, param1, param2);
        Transformacoes::translacao(T2, centro.x(), centro.y());
        Transformacoes::multiplicarMatrizes(temp, T2, S);
        Transformacoes::multiplicarMatrizes(matriz, temp, T1);
    }
    else if (transformacao == "Rotação") {
        // Rotação usando apenas param1 (ângulo) e centro do objeto
        QPointF centro = obj->getCentro();
        float T1[3][3], R[3][3], T2[3][3], temp[3][3];
        Transformacoes::translacao(T1, -centro.x(), -centro.y());
        Transformacoes::rotacao(R, param1); // Apenas o ângulo
        Transformacoes::translacao(T2, centro.x(), centro.y());
        Transformacoes::multiplicarMatrizes(temp, T2, R);
        Transformacoes::multiplicarMatrizes(matriz, temp, T1);
    }

    obj->aplicarTransformacao(matriz);
    ui->meuFrame->update();
    QMessageBox::information(this, "Sucesso", "Transformação aplicada com sucesso!");
}

void MainWindow::onTipoTransformacaoMudou(int index)
{
    // Esconder todos os parâmetros inicialmente
    ui->leParam1->setVisible(false);
    ui->leParam2->setVisible(false);
    ui->leParam3->setVisible(false);
    ui->labelParam1->setVisible(false);
    ui->labelParam2->setVisible(false);
    ui->labelParam3->setVisible(false);

    switch(index) {
    case 1: // Translação
        ui->leParam1->setVisible(true);
        ui->leParam2->setVisible(true);
        ui->labelParam1->setVisible(true);
        ui->labelParam2->setVisible(true);
        ui->labelParam1->setText("dx:");
        ui->labelParam2->setText("dy:");
        break;

    case 2: // Escala
        ui->leParam1->setVisible(true);
        ui->leParam2->setVisible(true);
        ui->labelParam1->setVisible(true);
        ui->labelParam2->setVisible(true);
        ui->labelParam1->setText("Fator X:");
        ui->labelParam2->setText("Fator Y:");
        break;

    case 3: // Rotação
        ui->leParam1->setVisible(true);
        ui->labelParam1->setVisible(true);
        ui->labelParam1->setText("Ângulo (graus):");
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
