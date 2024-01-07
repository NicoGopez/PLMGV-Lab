#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "verifydialog.h"


namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();


    QSqlQuery queryGlobal;

    //QSqlQuery queryGlobalStudent;

    void dashboardToolCounts();

    void refreshTime();
    void openDatabase();

    //student's info declaration
    void clearStudentInfo();
    void newStudent();
    void openStudentsInfo(int year);
    void openBorrowedTools();
    void toolCondition();
    void clearBorrowedTV();
    void deleteReturn();
    void insertReturn();
    //QString getLastStudentNumber(const QString& year);
    void refreshTableView(int year);


    //BORROWING FORM
    bool requiredField();
    bool requiredRadioButton();
    void moveallStudents();
    void insertNewBorrowData();
    void insertBorrowHistoryData();
    void clearForm();
    void updateToolCounts();

    //TOOLS INFO
    void increaseQuantity(int id);
    void decreaseQuantity(int id);
    void updateCountsToolsInfo();



private slots:
    void on_pushButton_dashBoard_clicked();

    void on_pushButton_borrowForm_clicked();

    void on_pushButton_returnedTools_clicked();

    void on_pushButton_logOut_clicked();

    void on_pushButton_studentInfo_2_clicked();

    void on_pushButton_toolsInfo_clicked();

    void on_pushButton_appendStudent_clicked();

    void on_pushButton_deleteStudent_clicked();

    void on_pushButton_clearStudent_clicked();

    void on_pushButton_generateSubjectCourse_clicked();

    void on_pushButton_show2022_clicked();

    void on_pushButton_show2021_clicked();

    void on_pushButton_show2020_clicked();

    void on_pushButton_show2019_clicked();

    void on_tableView_studentInfo_activated(const QModelIndex &index);

    void on_pushButton_studentNumSearch_clicked();

    void on_pushButton_timeRefresh_clicked();

    void on_pushButton_submitBF_clicked();

    void on_pushButton_minusAC_2_clicked();

    void on_pushButton_minusAlligator_2_clicked();

    void on_pushButton_minusDC_2_clicked();

    void on_pushButton_minusBboard_2_clicked();

    void on_pushButton_minusMulti_2_clicked();

    void on_pushButton_minusControl_2_clicked();

    void on_pushButton_minusTransform_2_clicked();

    void on_pushButton_minusOscilloscope_2_clicked();

    void on_pushButton_minusVP_2_clicked();

    void on_pushButton_minusVP_clicked();

    void on_pushButton_minusOscilloscope_clicked();

    void on_pushButton_minusTransform_clicked();

    void on_pushButton_minusControl_clicked();

    void on_pushButton_minusMulti_clicked();

    void on_pushButton_minusDC_clicked();

    void on_pushButton_minusBboard_clicked();

    void on_pushButton_minusAlligator_clicked();

    void on_pushButton_minusAC_clicked();

    void on_tableView_borrowedTools_activated(const QModelIndex &index);

    void on_pushButton_submitBF_2_clicked();

    void on_comboBox_ac_activated(int index);

    void on_comboBox_ac_currentTextChanged(const QString &arg1);

    void on_comboBox_alligator_currentTextChanged(const QString &arg1);

    void on_comboBox_bb_currentTextChanged(const QString &arg1);

    void on_comboBox_dc_currentTextChanged(const QString &arg1);

    void on_comboBox_multimeter_currentTextChanged(const QString &arg1);

    void on_comboBox_Controller_currentTextChanged(const QString &arg1);

    void on_comboBox_Transformer_currentTextChanged(const QString &arg1);

    void on_comboBox_oscilloscope_currentTextChanged(const QString &arg1);

    void on_comboBox_vpSupply_currentTextChanged(const QString &arg1);

    void on_pushButton_refreshTReturn_clicked();

private:
    Ui::DashboardWindow *ui;
    //VerifyDialog *verifyDialog;
    QSqlDatabase db;


};

#endif // DASHBOARDWINDOW_H
