#ifndef ATUALIZAR_H
#define ATUALIZAR_H

#include <QDialog>

namespace Ui {
class atualizar;
}

class atualizar : public QDialog
{
    Q_OBJECT

public:
    explicit atualizar(QWidget *parent = nullptr, QString old_nick="");
    ~atualizar();

private slots:
    void on_btnconfirm_2_clicked();

    void on_btncancel_2_clicked();

private:
    Ui::atualizar *ui;
    QString old_nick;
};

#endif // ATUALIZAR_H
