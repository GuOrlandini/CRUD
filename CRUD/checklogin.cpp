#include "checklogin.h"
#include "ui_checklogin.h"
#include <QMessageBox>
#include "bancodados.h"
#include "telalogin.h"
checklogin::checklogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checklogin)
{
    ui->setupUi(this);
}

checklogin::~checklogin()
{
    delete ui;
}

void checklogin::on_btnchecklogin_clicked()
{
    QString nomelogin = ui->txtnomelogin->text();
    QString senhalogin = ui->txtsenhalogin->text();
    if(nomelogin.isEmpty() || senhalogin.isEmpty())
        QMessageBox::warning(this, "Opção não preenchida", "Você deixou de inserir um dado");
    else
    {
        bancodados banco;
        if(banco.login(nomelogin, senhalogin))
        {
            telalogin tela(this, nomelogin);
            tela.exec();
            this->close();
        }
        else
          QMessageBox::warning(this, "Dados não encontrados", "Login ou senha incorreto");
    }

}


void checklogin::on_btnexitlogin_clicked()
{
    close();
}

