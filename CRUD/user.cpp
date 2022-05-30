#include "user.h"
#include <QString>
user::user()
{

}
user::user(QString nome, QString sobrenome, QString nick, QString senha, QString cpf, QString data)
{
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->nick = nick;
    this->senha = senha;
    this->cpf = cpf;
    this->data = data;
}

QString user::getnome(){

    return nome;
}

void user::setnome(QString nome){
    this->nome = nome;
}

QString user::getsobrenome(){

    return sobrenome;
}

void user::setsobrenome(QString sobrenome){
    this->sobrenome = sobrenome;
}

QString user::getnick(){

    return nick;
}

void user::setnick(QString nick){
    this->nick = nick;
}

QString user::getsenha(){

    return senha;
}

void user::setsenha(QString senha){
    this->senha = senha;
}

QString user::getcpf(){

    return cpf;
}

void user::setcpf(QString cpf){
    this->cpf = cpf;
}

QString user::getdata(){

    return data;
}

void user::setdata(QString data){
    this->data = data;
}
