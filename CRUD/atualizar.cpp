#include "atualizar.h"
#include "ui_atualizar.h"
#include "user.h"
#include "bancodados.h"
#include <QMessageBox>

atualizar::atualizar(QWidget *parent, QString old_nick) :
    QDialog(parent),
    ui(new Ui::atualizar)
{
    ui->setupUi(this);
    this->old_nick=old_nick;
}

atualizar::~atualizar()
{
    delete ui;
}

void atualizar::on_btnconfirm_2_clicked()
{
    bancodados banco_dados;
    user *old_user;
    old_user = banco_dados.busca(old_nick);
    QString nome = ui->txtnome_2->text();
    QString sobrenome = ui->txtsobrenome_2->text();
    QString nick = ui->txtnick_2->text();
    QString senha = ui->txtsenha_2->text();
    QString cpf = ui->txtcpf_2->text();
    QString data = old_user->getdata();

    if(nome.isEmpty() || sobrenome.isEmpty() || nick.isEmpty() || senha.isEmpty() || cpf.isEmpty())
        QMessageBox::warning(this, "Opção não preenchida", "Você deixou de inserir um dado");
    else
    {
        bancodados banco_dado;
        user User(nome, sobrenome, nick, senha, cpf, data);
        if(banco_dado.atualiza(User, old_nick))
        {
            QMessageBox::information(this, "Cadastro", "Cadastro atualizado com sucesso!\n\nDados recebidos:\n" "Nome: "+nome+"\nSobrenome: "+sobrenome+"\nNome de usuário: "+nick+"\nSenha: "+senha+
            "\nCPF: "+cpf); close();
        }
    }
}


void atualizar::on_btncancel_2_clicked()
{
    QMessageBox::StandardButton resposta=QMessageBox::question(this,"","Deseja fechar o editor?",QMessageBox::Yes|QMessageBox::No);
    if(resposta==QMessageBox::Yes){
        close();
    }
}

