#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "meu_frame.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void setupObjetosIniciais();
    void configurarUI();
    void conectarSinais();
    void atualizarListaTransformacao();
    ObjetoGeometrico* buscarObjeto(const QString& nome) const;

private slots:
    void onExibirClicked();
    void onTransformarClicked();
    void onAdicionarTransformacaoClicked();
    void onTipoTransformacaoMudou(int index);
};
#endif
