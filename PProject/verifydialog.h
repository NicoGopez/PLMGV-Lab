#ifndef VERIFYDIALOG_H
#define VERIFYDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "dashboardwindow.h"

namespace Ui {
class VerifyDialog;
}

class VerifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VerifyDialog(QWidget *parent = nullptr);
    ~VerifyDialog();

    //DashboardWindow *dashboardWindow;


private slots:
    void on_pushButton_backMain_clicked();

    void on_pushButton_Vlogin_clicked();

private:
    Ui::VerifyDialog *ui;
    //DashboardWindow *dashboardWindow;
    QSqlDatabase db;
    QString loggedInUserID; // Store the ID of the logged-in user


};

#endif // VERIFYDIALOG_H
