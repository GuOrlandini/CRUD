#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"
#include "checklogin.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btncadastro_clicked()
{
    cadastro registeer;
    registeer.exec();
}

void MainWindow::on_btnlogin_clicked()
{
    checklogin login;
    login.exec();
}


void MainWindow::on_btnexit_clicked()
{
    QMessageBox::StandardButton resposta=QMessageBox::question(this,"","Deseja fechar o formulário?",QMessageBox::Yes|QMessageBox::No);
    if(resposta==QMessageBox::Yes){
        close();
    }
}

