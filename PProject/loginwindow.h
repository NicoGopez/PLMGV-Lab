#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>


#include "dashboardwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    //QSqlQuery queryGlobal;

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase db;
    DashboardWindow *dashboardWindow;

    QString loggedInUserID; // Store the ID of the logged-in user

    //QSqlDatabase db;
    //bool validateEmail(const QString& Email);
};
#endif // LOGINWINDOW_H
