#ifndef BANCODADOS_H
#define BANCODADOS_H
#include <QtSql>
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "user.h"

class bancodados
{
public:
    QSqlDatabase banco_dado;

    bancodados();
    ~bancodados();
    user* busca(QString nick);
    // Pesquisa um usuário e retorna verdadeiro caso encontrado
    bool login(QString nick, QString senha);

    // Cria um usuário
    bool insere(user User);

    // Atualiza as informações de um usuário
    bool atualiza(user User, QString nick_old);

    // Remove usuário
    bool remove(QString nick);
};

#endif // BANCODADOS_H
