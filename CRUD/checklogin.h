#ifndef CHECKLOGIN_H
#define CHECKLOGIN_H

#include <QDialog>

namespace Ui {
class checklogin;
}

class checklogin : public QDialog
{
    Q_OBJECT

public:
    explicit checklogin(QWidget *parent = nullptr);
    ~checklogin();

private slots:
    void on_btnchecklogin_clicked();

    void on_btnexitlogin_clicked();

private:
    Ui::checklogin *ui;
};

#endif // CHECKLOGIN_H
