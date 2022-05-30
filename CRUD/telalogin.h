#ifndef TELALOGIN_H
#define TELALOGIN_H
#include "user.h"
#include <QDialog>

namespace Ui {
class telalogin;
}

class telalogin : public QDialog
{
    Q_OBJECT

public:
    // Passa o usuário da tela anterior para próx tela
    explicit telalogin(QWidget *parent = nullptr, QString nick="");
    ~telalogin();

private slots:
    void on_btnexitmenu_clicked();

    void on_btndadoslogin_clicked();

    void on_btnexcluilogin_clicked();

    void on_btneditalogin_clicked();

private:
    Ui::telalogin *ui;
    // Variavel que recebe o usuário da tela anterior
    QString nick;
};

#endif // TELALOGIN_H
