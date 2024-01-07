#include "verifydialog.h"
#include "ui_verifydialog.h"

#include "dashboardwindow.h"
#include <QMessageBox>

VerifyDialog::VerifyDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VerifyDialog)
{
    ui->setupUi(this);
}

VerifyDialog::~VerifyDialog()
{
    delete ui;
}
/*
void VerifyDialog::on_pushButton_login_clicked()

QString email = ui->lineEdit_email->text();
QString password = ui->lineEdit_password->text();

QSqlQuery query;
query.prepare("SELECT UserID FROM UserInfo WHERE Email = :Email AND Password = :Password");
query.bindValue(":Email", email);
query.bindValue(":Password", password);

if (!query.exec()) {
    qDebug() << "Failed to execute query:" << query.lastError().text();
    return;
}

if (query.next()) {
    loggedInUserID = query.value(0).toString(); // Store the UserID of the logged-in user
    QMessageBox::information(this, "Login", "Login Success!");
    this->hide();
    // Proceed with your next steps after successful login
} else {
    QMessageBox::warning(this, "Login", "Invalid Username or Password.");
}
*/

void VerifyDialog::on_pushButton_backMain_clicked()
{
    this->hide();
    DashboardWindow * dashboardWindow = new DashboardWindow(this);
    dashboardWindow->show();
}

void VerifyDialog::on_pushButton_Vlogin_clicked()
{
    QString email = ui->lineEdit_Vmail->text();
    QString password = ui->lineEdit_Vpass->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM UserInfo WHERE Email = :Email AND Password = :Password");
    query.bindValue(":Email", email);
    query.bindValue(":Password", password);

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        loggedInUserID = query.value(0).toString(); // Store the UserID of the logged-in user
        QMessageBox::information(this, "Login", "Login Success!");
        this->hide();

    }
    else {
        QMessageBox::warning(this, "Login", "Invalid Username or Password.");
    }
}

