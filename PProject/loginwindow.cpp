#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QApplication::setWindowIcon(QIcon("C:/Users/Windows10/Downloads/PProject-20231129T010832Z-001/PProject/Project-Images/QuadTechLogo.png")); // Replace with your icon file path


}

LoginWindow::~LoginWindow()
{
    delete ui;
}

/*
void LoginWindow::on_pushButton_login_clicked()
{
    QString Username = ui->lineEdit_email->text();
    QString Password = ui->lineEdit_password->text();
    if (Username == "admin" && Password == "admin")
    {
        QMessageBox::information(this, "QT with QT", "Login Success!");
        this->hide();
        dashboardWindow = new DashboardWindow();
        dashboardWindow->show();
    }
    else
    {
        QMessageBox::warning(this, "QT with QT", "Please enter valid Username or Password.");
    }
}

bool LoginWindow::validateEmail(const QString& Email)
{
    return Email.endsWith("@gmail.com");
}
*/


void LoginWindow::on_pushButton_login_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Windows10/Downloads/PProject-20231129T010832Z-001/PProject/login.db");

    if (!db.open()) {
        qDebug() << "Failed to connect to the database.";
        return;
    }

    qDebug() << "Connected to the database.";
    QSqlQuery query;
    //queryGlobal = query;

    QString Email = ui->lineEdit_email->text();
    QString Password = ui->lineEdit_password->text();

    // Check if the user exists in the database
    //QSqlQuery query;
    query.prepare("SELECT * FROM UserInfo WHERE Email = :Email AND Password = :Password");
    query.bindValue(":Email", Email);
    query.bindValue(":Password", Password);

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        loggedInUserID = query.value(0).toString(); // Store the UserID of the logged-in user
        QMessageBox::information(this, "QT with QT", "Login Success!");
        this->hide();
        dashboardWindow = new DashboardWindow();
        dashboardWindow->show();

    } else {
        QMessageBox::warning(this, "QT with QT", "Please enter valid Username or Password.");
    }


}

/*
void LoginWindow::on_pushButton_signUp_clicked()
{

    hide();
    SignupWindow*signupwindow = new SignupWindow (this);
    signupwindow->show();
}

*/
