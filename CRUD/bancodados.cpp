#include <QtSql>
#include "bancodados.h"
#include "user.h"

bancodados::bancodados()
{
    banco_dado = QSqlDatabase::addDatabase("QSQLITE");
    banco_dado.setDatabaseName("C:/Users/guorl/OneDrive/Documents/CRUD/usuarios.db");
}

bancodados::~bancodados()
{
    banco_dado.removeDatabase("C:/Users/guorl/OneDrive/Documents/CRUD/usuarios.db");
}

user* bancodados::busca(QString nick)
{
   banco_dado.open();
   QSqlQuery query;
   user *User = nullptr;
   int coluna = 3;

   if(query.exec("select * from tbusuarios"))
       {
           while(query.next())
           {
               if(query.value(coluna).toString() == nick)
               {
                   User = new user();
                   User->setcpf(query.value(0).toString());
                   User->setnome(query.value(1).toString());
                   User->setsobrenome(query.value(2).toString());
                   User->setnick(query.value(3).toString());
                   User->setsenha(query.value(4).toString());
                   User->setdata(query.value(5).toString());
                   break;
                }
           }
       }
   query.finish();
   banco_dado.close();
   return User;
}

bool bancodados::login(QString nick, QString senha)
{
    banco_dado.open();
    QSqlQuery query;
    bool b;
    int count=0;
    if(query.exec("select * from tbusuarios where usuario='"+nick+"' and senha = '"+senha+"'"))
        while(query.next())
            count++;
    if (count == 1)
        b = true;
    else
        b=false;
    query.finish();
    banco_dado.close();
    return b;
}

bool bancodados::insere(user User)
{
    banco_dado.open();
    QSqlQuery query;

    query.prepare("insert into tbusuarios (cpf,nome,sobrenome,usuario,senha,data) values"
                  "('"+User.getcpf()+"','"+User.getnome()+"','"+User.getsobrenome()+"','"+User.getnick()+"','"+User.getsenha()+"','"+User.getdata()+"')");
    bool b = query.exec();
    query.finish();
    banco_dado.close();
    return b;
}

bool bancodados::remove(QString nick)
{
    banco_dado.open();
    QSqlQuery query;
    bool b;
    query.prepare("delete from tbusuarios where usuario="+nick);
    b = query.exec();
    query.finish();
    banco_dado.close();
    return b;
}

bool bancodados::atualiza(user User, QString old_nick)
{
    banco_dado.open();
    QSqlQuery query;
    bool b;
    query.prepare("update tbusuarios set nome='"+User.getnome()+"', sobrenome='"+User.getsobrenome()+"', usuario='"+User.getnick()+"',"
                   "senha='"+User.getsenha()+"', cpf='"+User.getcpf()+"' where usuario='"+old_nick+"'");
    b = query.exec();
    query.finish();
    banco_dado.close();
    return b;
}
