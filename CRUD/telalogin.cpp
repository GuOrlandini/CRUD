#include "telalogin.h"
#include "ui_telalogin.h"
#include "user.h"
#include "bancodados.h"
#include <QMessageBox>
#include "atualizar.h"

telalogin::telalogin(QWidget *parent,QString nick) :
    QDialog(parent),
    ui(new Ui::telalogin)
{
    ui->setupUi(this);
    this->nick =nick;
}

telalogin::~telalogin()
{
    delete ui;
}

void telalogin::on_btnexitmenu_clicked()
{
    close();
}


void telalogin::on_btndadoslogin_clicked()
{
    bancodados banco;
    user *User = banco.busca(nick);
    if(User!=nullptr)
    {
        QMessageBox::information(this, "Cadastro","Nome: "+User->getnome()+"\nSobrenome: "+User->getsobrenome()+
        "\nNome de usuário: "+User->getnick()+"\nSenha: "+User->getsenha()+"\nCPF: "+User->getcpf()+"\nData: "+User->getdata());

    }
    else
        QMessageBox::information(this, "Cadastro","nao deu");
}

void telalogin::on_btnexcluilogin_clicked()
{
    bancodados banco;
    if(banco.remove(nick))
    {
       // QMessageBox::StandardButton resposta=QMessageBox::question(this,"Excluir","Deseja mesmo excluir o usuário?",QMessageBox::Yes|QMessageBox::No);
        //if(resposta==QMessageBox::Yes){
            QMessageBox::information(this, "Excluir", "Usuário excluído com sucesso"); close();
        //}
    }
    else
     QMessageBox::warning(this, "Excluir","nao deu");
}


void telalogin::on_btneditalogin_clicked()
{
    atualizar att(this, nick);
    att.exec();
    close();
}

