#ifndef USER_H
#define USER_H
#include <QString>

class user
{
private:
    QString nome;
    QString sobrenome;
    QString nick;
    QString senha;
    QString cpf;
    QString data;

public:
    user(QString nome, QString sobrenome, QString nick, QString senha, QString cpf, QString data);

    user();

    QString getnome();
    void setnome(QString nome);

    QString getsobrenome();
    void setsobrenome(QString sobrenome);

    QString getnick();
    void setnick(QString nick);

    QString getsenha();
    void setsenha(QString senha);

    QString getcpf();
    void setcpf(QString cpf);

    QString getdata();
    void setdata(QString data);
};

#endif // USER_H
