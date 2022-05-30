#include "cadastro.h"
#include "ui_cadastro.h"
#include <QMessageBox>
#include "bancodados.h"
#include "user.h"

cadastro::cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastro)
{
    ui->setupUi(this);
}

cadastro::~cadastro()
{
    delete ui;
}

void cadastro::on_pushButton_clicked()
{
    QMessageBox::StandardButton resposta=QMessageBox::question(this,"","Deseja cancelar o cadastro?",QMessageBox::Yes|QMessageBox::No);
    if(resposta==QMessageBox::Yes){
        close();
    }else{}
}


void cadastro::on_btnconfirm_clicked()
{
    QString nome = ui->txtnome->text();
    QString sobrenome = ui->txtsobrenome->text();
    QString nick = ui->txtnick->text();
    QString senha = ui->txtsenha->text();
    QString cpf = ui->txtcpf->text();
    QString data = ui->txtdata->text();

    if(nome.isEmpty() || sobrenome.isEmpty() || nick.isEmpty() || senha.isEmpty() || cpf.isEmpty() || data.isEmpty())
        QMessageBox::warning(this, "Opção não preenchida", "Você deixou de inserir um dado");
    else
    {
        bancodados banco_dado;
        user User(nome, sobrenome, nick, senha, cpf, data);
        if(banco_dado.insere(User))
        {
            QMessageBox::information(this, "Cadastro", "Cadastro realizado com sucesso!\n\nDados recebidos:\n" "Nome: "+nome+"\nSobrenome: "+sobrenome+"\nNome de usuário: "+nick+"\nSenha: "+senha+
            "\nCPF: "+cpf+"\nData: "+data); close();
        }
    }
}


void cadastro::on_btncancel_clicked()
{
    close();
}

