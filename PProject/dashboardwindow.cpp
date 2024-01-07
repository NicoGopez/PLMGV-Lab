#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

#include <QDate>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>

#include "verifydialog.h"

DashboardWindow::DashboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    QApplication::setWindowIcon(QIcon("C:/Users/Windows10/Downloads/PProject-20231129T010832Z-001/PProject/Project-Images/QuadTechLogo.png")); // Replace with your icon file path
    openDatabase();

    //dashboard
    ui->lbl_dashboardDate->setText("Date Today: " + QDate::currentDate().toString(Qt::ISODate));
    dashboardToolCounts();

    //borrowing, available tools
    updateToolCounts();

    //count the tools in the toolsInfo
    updateCountsToolsInfo();

    //open 2024 students
    openStudentsInfo(2024);

    //open returned tools
    openBorrowedTools();

}

DashboardWindow::~DashboardWindow()
{
    delete ui;
    db.close();
}

void DashboardWindow::openDatabase(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Windows10/Downloads/PProject-20231129T010832Z-001/PProject/login.db");

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return;
    }

    qDebug() << "Opened the database file";
}

void DashboardWindow::dashboardToolCounts() // FOR DASHBOARD PURPOSE LIKE I-SHOSHOW NIYA KUNG ILAN AVAILABLE AND IN USE THROUGH PROGRESS BAR
{


    QSqlQuery query;

    // AC Supply
    query.exec("SELECT COUNT(*) FROM borrow WHERE AC_Supply = 'In Use'");
    if (query.next()) {
        int inUseACSupply = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 1");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableACSupply = Quantity - inUseACSupply;
            ui->progressBar_ac->setRange(0, Quantity);
            ui->progressBar_ac->setValue(availableACSupply);
            QString formatText = QString("%1        |        %2").arg(availableACSupply).arg(inUseACSupply);
            ui->progressBar_ac->setFormat(formatText);
        }
    }
    // Alligator Clips
    query.exec("SELECT COUNT(*) FROM borrow WHERE Alligator_Clips = 'In Use'");
    if (query.next()) {
        int inUseAlligatorClips = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 2");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableAlligatorClips = Quantity - inUseAlligatorClips;
            ui->progressBar_alligator->setRange(0, Quantity);
            ui->progressBar_alligator->setValue(availableAlligatorClips);
            QString formatText = QString("%1        |        %2").arg(availableAlligatorClips).arg(inUseAlligatorClips);
            ui->progressBar_alligator->setFormat(formatText);
        }
    }
    // Breadboard
    query.exec("SELECT COUNT(*) FROM borrow WHERE Breadboard = 'In Use'");
    if (query.next()) {
        int inUseBreadboard = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 3");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableBreadboard = Quantity - inUseBreadboard;
            ui->progressBar_bboard->setRange(0, Quantity);
            ui->progressBar_bboard->setValue(availableBreadboard);
            QString formatText = QString("%1        |        %2").arg(availableBreadboard).arg(inUseBreadboard);
            ui->progressBar_bboard->setFormat(formatText);
        }
    }
    // DC Supply
    query.exec("SELECT COUNT(*) FROM borrow WHERE DC_Supply = 'In Use'");
    if (query.next()) {
        int inUseDCSupply = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 4");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableDCSupply = Quantity - inUseDCSupply;
            ui->progressBar_dc->setRange(0, Quantity);
            ui->progressBar_dc->setValue(availableDCSupply);
            QString formatText = QString("%1        |        %2").arg(availableDCSupply).arg(inUseDCSupply);
            ui->progressBar_dc->setFormat(formatText);
        }
    }
    // Digital Multimeter
    query.exec("SELECT COUNT(*) FROM borrow WHERE Digital_Multimeter = 'In Use'");
    if (query.next()) {
        int inUseDigitalMultimeter = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 5");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableDigitalMultimeter = Quantity - inUseDigitalMultimeter;
            ui->progressBar_multi->setRange(0, Quantity);
            ui->progressBar_multi->setValue(availableDigitalMultimeter);
            QString formatText = QString("%1        |        %2").arg(availableDigitalMultimeter).arg(inUseDigitalMultimeter);
            ui->progressBar_multi->setFormat(formatText);
        }
    }
    // Micro Controller
    query.exec("SELECT COUNT(*) FROM borrow WHERE MController = 'In Use'");
    if (query.next()) {
        int inUseMicroController = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 6");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableMicroController = Quantity - inUseMicroController;
            ui->progressBar_control->setRange(0, Quantity);
            ui->progressBar_control->setValue(availableMicroController);
            QString formatText = QString("%1        |        %2").arg(availableMicroController).arg(inUseMicroController);
            ui->progressBar_control->setFormat(formatText);
        }
    }
    // Multi tap transformer
    query.exec("SELECT COUNT(*) FROM borrow WHERE MTransformer = 'In Use'");
    if (query.next()) {
        int inUseMultiTapTransformer = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 7");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableMultiTapTransformer = Quantity - inUseMultiTapTransformer;
            ui->progressBar_transform->setRange(0, Quantity);
            ui->progressBar_transform->setValue(availableMultiTapTransformer);
            QString formatText = QString("%1        |        %2").arg(availableMultiTapTransformer).arg(inUseMultiTapTransformer);
            ui->progressBar_transform->setFormat(formatText);
        }
    }
    // Oscilloscope
    query.exec("SELECT COUNT(*) FROM borrow WHERE Oscilloscope = 'In Use'");
    if (query.next()) {
        int inUseOscilloscope = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 8");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableOscilloscope = Quantity - inUseOscilloscope;
            ui->progressBar_osci->setRange(0, Quantity);
            ui->progressBar_osci->setValue(availableOscilloscope);
            QString formatText = QString("%1        |        %2").arg(availableOscilloscope).arg(inUseOscilloscope);
            ui->progressBar_osci->setFormat(formatText);
        }
    }
    // Variable Power Supply
    query.exec("SELECT COUNT(*) FROM borrow WHERE VP_Supply = 'In Use'");
    if (query.next()) {
        int inUseVariablePowerSupply = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 9");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableVariablePowerSupply = Quantity - inUseVariablePowerSupply;
            ui->progressBar_vp->setRange(0, Quantity);
            ui->progressBar_vp->setValue(availableVariablePowerSupply);
            QString formatText = QString("%1        |        %2").arg(availableVariablePowerSupply).arg(inUseVariablePowerSupply);
            ui->progressBar_vp->setFormat(formatText);
        }
    }
}

/*      ui->stackedWidget->setCurrentIndex(0); Yung integer sa part na 'to default na agad siya sa qt pero pede baguhin depende sa arrangment ng widget or pages ng stacked widget doon sa .ui ng dashboard and stackedWidget component titignan niyo, right clicked lng tas may lalabas na order of pages something
 *      so every time na nagcode ng "ui->stackedWidget->setCurrentIndex('from 0 to 3'); may iba ibang widget na lalabas"
 */

void DashboardWindow::on_pushButton_dashBoard_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lbl_dashboardDate->setText("Date Today: " + QDate::currentDate().toString(Qt::ISODate));

    dashboardToolCounts();
}

void DashboardWindow::on_pushButton_borrowForm_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->timeEdit_borrowTimeBF->setTime(QTime::currentTime());
    ui->dateEdit_borrowDateBF->setDate(QDate::currentDate());
    ui->dateEdit_borrowDateBF->setCalendarPopup(true);
/*
    QTime recentTime = ui->timeEdit_borrowTimeBF->time();
    QTime expectedReturnTime = recentTime.addSecs(3 * 3600);  // Adding 3 hours to the current time
    ui->timeEdit_borrowExpectedTimeBF->setTime(expectedReturnTime);
*/
    updateToolCounts();
}

void DashboardWindow::on_pushButton_returnedTools_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->timeEdit_returnTime->setTime(QTime::currentTime());
    ui->dateEdit_returnDate->setDate(QDate::currentDate());
    ui->dateEdit_returnDate->setCalendarPopup(true);

    openBorrowedTools();
}

void DashboardWindow::on_pushButton_toolsInfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    updateCountsToolsInfo();

}

void DashboardWindow::on_pushButton_studentInfo_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    openStudentsInfo(2024);

}

void DashboardWindow::on_pushButton_logOut_clicked()
{
    this->close();
}

/*
 *  STUDENT INFO STUDENT INFO  STUDENT INFO
 *  STUDENT INFO STUDENT INFO  STUDENT INFO
 *  STUDENT INFO STUDENT INFO  STUDENT INFO
 */

void DashboardWindow::on_pushButton_clearStudent_clicked()
{
    clearStudentInfo();
}

void DashboardWindow::clearStudentInfo(){  //CLEAR FUNCTION PA RIN PERO SA STUDENT INFO LNG
    ui->lineEdit_studentNumberSO->clear();
    ui->lineEdit_studentNameSO->clear();
    ui->lineEdit_yrBlockSO->clear();
    ui->lineEdit_semOneSO->clear();
    ui->lineEdit_semTwoSO->clear();
    ui->lineEdit_professorSO->clear();
    //ui->lineEdit_punishmentSO->clear();
}

void DashboardWindow::on_pushButton_appendStudent_clicked()     //CODE KUNG PAANO MAG ADD NG STUDENTS
{
    QString numberSearch = ui->lineEdit_studentNumberSO->text();

    QSqlQuery query;
    query.prepare("SELECT StudentNumber FROM allStudent WHERE StudentNumber = ?");
    query.bindValue(0, numberSearch);

    if (!query.exec()){
        qWarning() << "Failed to exec:" << query.lastError().text();
        return;
    }

    if (!query.next()){

        //CONDITION NA NEED LAHAT MAGFILL OUT BAGO MAG ADD SA DATABASE
        if (ui->lineEdit_studentNumberSO->text().isEmpty() || ui->lineEdit_studentNameSO->text().isEmpty() || ui->lineEdit_yrBlockSO->text().isEmpty() ||
            ui->lineEdit_semOneSO->text().isEmpty() || ui->lineEdit_semTwoSO->text().isEmpty() || ui->lineEdit_professorSO->text().isEmpty()) //|| ui->lineEdit_punishmentSO->text().isEmpty())

        {
            QMessageBox::warning(this, "Warning", "Please fill in all fields.");
            return;
        }

        newStudent();
    }

    else{
        QMessageBox::information(this, "Warning", "Data already exists");
        return;
    }

    QMessageBox::information(this, "Message", "New data is successfully added");
    clearStudentInfo();
    openStudentsInfo(2024);
}

void DashboardWindow::newStudent(){

    QString StudentnumSO = ui->lineEdit_studentNumberSO->text();
    QString Year = StudentnumSO.mid(0, 4);

    QSqlQuery query;
    query.prepare("INSERT INTO allStudent (Year, StudentNumber, StudentName, YearBlock, FirstSem, SecondSem, Professor) "
                  "VALUES (:Year, :StudentNumber, :StudentName, :YearBlock, :FirstSem, :SecondSem, :Professor)");
    query.bindValue(":Year", Year);
    query.bindValue(":StudentNumber", ui->lineEdit_studentNumberSO->text());
    query.bindValue(":StudentName", ui->lineEdit_studentNameSO->text());
    query.bindValue(":YearBlock", ui->lineEdit_yrBlockSO->text());
    query.bindValue(":FirstSem", ui->lineEdit_semOneSO->text());
    query.bindValue(":SecondSem", ui->lineEdit_semTwoSO->text());
    query.bindValue(":Professor", ui->lineEdit_professorSO->text());
    //query.bindValue(":Punishment", ui->lineEdit_punishmentSO->text());

    if (!query.exec()){
        qWarning() << "Failed to insert newStudent():" << query.lastError().text();
        return;
    }
}

void DashboardWindow::on_pushButton_deleteStudent_clicked()     //DELETE STUDENT AND MAGREFRESH UNG TABLE
{
    // Get the values from the line edits
    QString studentNumber = ui->lineEdit_studentNumberSO->text();
    QString studentName = ui->lineEdit_studentNameSO->text();
    QString yearBlock = ui->lineEdit_yrBlockSO->text();
    QString semOne = ui->lineEdit_semOneSO->text();
    QString semTwo = ui->lineEdit_semTwoSO->text();
    QString professor = ui->lineEdit_professorSO->text();
    //QString punishment = ui->lineEdit_punishmentSO->text();

    // Prepare the delete query
    QSqlQuery query;
    query.prepare("DELETE FROM allStudent WHERE StudentNumber = :studentNumber "
                  "AND StudentName = :studentName "
                  "AND YearBlock = :yearBlock "
                  "AND FirstSem = :semOne "
                  "AND SecondSem = :semTwo "
                  "AND Professor = :professor ");
    query.bindValue(":studentNumber", studentNumber);
    query.bindValue(":studentName", studentName);
    query.bindValue(":yearBlock", yearBlock);
    query.bindValue(":semOne", semOne);
    query.bindValue(":semTwo", semTwo);
    query.bindValue(":professor", professor);
    //query.bindValue(":punishment", punishment);

    // Execute the delete query
    if (query.exec()) {
        // Deletion successful
        qDebug() << "Data deleted successfully.";

        // Perform any additional actions if needed
        // Clear the line edits after successful deletion
        clearStudentInfo();

        refreshTableView(2024); // Pass the appropriate year parameter
    } else {
        // Deletion failed
        qDebug() << "Failed to delete data:" << query.lastError().text();
    }
}

void DashboardWindow::on_tableView_studentInfo_activated(const QModelIndex &index)          //CODE NG TABLE VIEW NA KAPAG PININDOT, MAG AAPPEAR DOON SA CERTAIN LINE EDITS. TABLE VIEW YUNG PINIPINDOT LIKE IF SA MGA EXCEL MAY CELLS NA TINATAWAG TAS NAPIPINDOT YUN, GANUN DIN FUNCTION NG CODE NA TO
{
    QString year = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 0)).toString();
    QString studentNumber = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 1)).toString();
    QString studentName = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 2)).toString();
    QString yearBlock = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 3)).toString();
    QString semOne = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 4)).toString();
    QString semTwo = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 5)).toString();
    QString professor = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 6)).toString();
    //QString punishment = ui->tableView_studentInfo->model()->data(ui->tableView_studentInfo->model()->index(index.row(), 7)).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM allStudent WHERE StudentNumber = :StudentNumber "
                  "AND StudentName = :StudentName "
                  "AND YearBlock = :YearBlock "
                  "AND FirstSem = :FirstSem "
                  "AND SecondSem = :SecondSem "
                  "AND Professor = :Professor "
                  "AND Year = :Year ");
    query.bindValue(":StudentNumber", studentNumber);
    query.bindValue(":StudentName", studentName);
    query.bindValue(":YearBlock", yearBlock);
    query.bindValue(":FirstSem", semOne);
    query.bindValue(":SecondSem", semTwo);
    query.bindValue(":Professor", professor);
    query.bindValue(":Year", year);
    //query.bindValue(":Punishment", punishment);

    if (query.exec()) {
        if (query.next()) {
            ui->lineEdit_studentNumberSO->setText(query.value("StudentNumber").toString());
            ui->lineEdit_studentNameSO->setText(query.value("StudentName").toString());
            ui->lineEdit_yrBlockSO->setText(query.value("YearBlock").toString());
            ui->lineEdit_semOneSO->setText(query.value("FirstSem").toString());
            ui->lineEdit_semTwoSO->setText(query.value("SecondSem").toString());
            ui->lineEdit_professorSO->setText(query.value("Professor").toString());
            //ui->lineEdit_punishmentSO->setText(query.value("Punishment").toString());
        } else {
            qDebug() << "No data found";
        }
    } else {
        QMessageBox::warning(this, "Warning Message", "Failed to retrieve student info.");
    }
}

void DashboardWindow::refreshTableView(int year)    //REFRESH TABLE AFTER DELETING
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(QString("SELECT Year, StudentNumber, StudentName, YearBlock, FirstSem, SecondSem, Professor "
                            "FROM allStudent "
                            "WHERE Year = %1 "
                            "ORDER BY StudentNumber DESC").arg(year)); // Updated the column name
    ui->tableView_studentInfo->setModel(model);
    ui->tableView_studentInfo->resizeColumnsToContents();
}

void DashboardWindow::openStudentsInfo(int year){       //TABLE VIEW, BY DEFAULTS KUNG ANO YUNG TATAWAGING YEAR KAYA KAPAG 2024, PURO 2024 LNG LALABAS NA STUDENTS
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(QString("SELECT Year, StudentNumber, StudentName, YearBlock, FirstSem, SecondSem, Professor "
                            "FROM allStudent "
                            "WHERE Year = %1 "
                            "ORDER BY StudentNumber DESC").arg(year));
    ui->tableView_studentInfo->setModel(model);
    ui->tableView_studentInfo->resizeColumnsToContents();
}

void DashboardWindow::on_pushButton_show2022_clicked() //show 2024 stundent info
{
    openStudentsInfo(2024);
}
void DashboardWindow::on_pushButton_show2021_clicked()  //show 2021 stundent info
{
    openStudentsInfo(2023);
}
void DashboardWindow::on_pushButton_show2020_clicked()  //show 2020 stundent info
{
    openStudentsInfo(2022);
}
void DashboardWindow::on_pushButton_show2019_clicked()  //show 2019 stundent info
{
    openStudentsInfo(2021);
}

void DashboardWindow::on_pushButton_generateSubjectCourse_clicked()                         //STUDENT INFO: GENERATE SUBJECT AND PROF AND NONE FOR PUNISHMENT
{
    if (ui->lineEdit_yrBlockSO->text() == "1-1"){
        ui->lineEdit_semOneSO->setText("Chemistry For Engineer (Lab)");                     //FIRST YEAR
        ui->lineEdit_semTwoSO->setText("Physics For Engineer (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Jennalyn Javier");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "1-2"){
        ui->lineEdit_semOneSO->setText("Chemistry For Engineer (Lab)");
        ui->lineEdit_semTwoSO->setText("Physics For Engineer (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Jennalyn Javier");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "1-3"){
        ui->lineEdit_semOneSO->setText("Chemistry For Engineer (Lab)");
        ui->lineEdit_semTwoSO->setText("Physics For Engineer (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Jennalyn Javier");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "2-1"){
        ui->lineEdit_semOneSO->setText("Fundamental of Electric Circuits (Lab)");           //SECOND YEAR
        ui->lineEdit_semTwoSO->setText("Fundamental of Electronics Circuits (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Thaddeo Garcia");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "2-2"){
        ui->lineEdit_semOneSO->setText("Fundamental of Electric Circuits (Lab)");
        ui->lineEdit_semTwoSO->setText("Fundamental of Electronics Circuits (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Thaddeo Garcia");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "2-3"){
        ui->lineEdit_semOneSO->setText("Fundamental of Electric Circuits (Lab)");
        ui->lineEdit_semTwoSO->setText("Fundamental of Electronics Circuits (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Thaddeo Garcia");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "3-1"){
        ui->lineEdit_semOneSO->setText("Logic Circuits and Design (Lab)");                  //THIRD YEAR
        ui->lineEdit_semTwoSO->setText("Introduction to HDL (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Evangeline P. Lubao");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "3-2"){
        ui->lineEdit_semOneSO->setText("Logic Circuits and Design (Lab)");
        ui->lineEdit_semTwoSO->setText("Introduction to HDL (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Evangeline P. Lubao");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "3-3"){
        ui->lineEdit_semOneSO->setText("Logic Circuits and Design (Lab)");
        ui->lineEdit_semTwoSO->setText("Introduction to HDL (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Evangeline P. Lubao");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "4-1"){
        ui->lineEdit_semOneSO->setText("Embedded System (Lab)");                            //FOURTH YEAR
        ui->lineEdit_semTwoSO->setText("Microprocessors (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Perferinda Caubang");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "4-2"){
        ui->lineEdit_semOneSO->setText("Embedded System (Lab)");
        ui->lineEdit_semTwoSO->setText("Microprocessors (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Perferinda Caubang");
        //ui->lineEdit_punishmentSO->setText("None");
    }
    if (ui->lineEdit_yrBlockSO->text() == "4-3"){
        ui->lineEdit_semOneSO->setText("Embedded System (Lab)");
        ui->lineEdit_semTwoSO->setText("Microprocessors (Lab)");
        ui->lineEdit_professorSO->setText("Engr. Perferinda Caubang");
        //ui->lineEdit_punishmentSO->setText("None");
    }
}


/*
 *  BORROWING FORM  BORROWING FORM  BORROWING FORM
 *  BORROWING FORM  BORROWING FORM  BORROWING FORM
 *  BORROWING FORM  BORROWING FORM  BORROWING FORM
 */

void DashboardWindow::on_pushButton_studentNumSearch_clicked()  //IN BORROWING FORM PARA KAPAG NAGSEARCH NG STUD-NUMBER, MAY LALABAS AGAD BY CLICKY THE BUTTON
{
    QSqlQuery query;
    //get name to check if data is existing
    QString numberSearchBF = ui->lineEdit_studentNumberSearchBF->text();

    qDebug() << "Value of Number Search = " << numberSearchBF;
    query.prepare("SELECT StudentNumber, StudentName, YearBlock, FirstSem, SecondSem, Professor FROM allStudent WHERE StudentNumber = ?");
    query.bindValue(0, numberSearchBF);

    if (!query.exec()){
        qWarning() << "Failed to execute query: " << query.lastError().text();
        return;
    }

    if (!query.next()){
        ui->lineEdit_studentNumberSearchBF->clear();
        ui->lineEdit_studentNumberBF->clear();
        ui->lineEdit_studentNameBF->clear();
        ui->lineEdit_yearSectionBF->clear();
        ui->lineEdit_subjectCourseBF->clear();
        ui->lineEdit_professorBF->clear();

        QMessageBox::information(this, "Warning","Data Not Found");
        return;
    }
    queryGlobal = query;
    moveallStudents();

}

//Year, StudentNumber, StudentName, YearBlock, FirstSem, SecondSem, Professor,

void DashboardWindow::moveallStudents() //FUNCTION NA TINATAWAG PARA MASEARCH YUNG STUDENT AND MAGENERATE GAMIT YUNG SEARCH BUTTON
{
    QString StudentNumber = queryGlobal.value("StudentNumber").toString();
    QString StudentName = queryGlobal.value("StudentName").toString();
    QString YearBlock = queryGlobal.value("YearBlock").toString();
    QString FirstSem = queryGlobal.value("FirstSem").toString();
    QString SecondSem = queryGlobal.value("SecondSem").toString();
    QString Professor = queryGlobal.value("Professor").toString();

    ui->lineEdit_studentNumberBF->setText(StudentNumber);
    ui->lineEdit_studentNameBF->setText(StudentName);
    ui->lineEdit_yearSectionBF->setText(YearBlock);

    QDate currentDate = QDate::currentDate();

    // Check if the current date is within the first semester
    QDate firstSemesterStart(currentDate.year(), 9, 5);
    QDate firstSemesterEnd(currentDate.year() + 1, 1, 21);

    if (currentDate >= firstSemesterStart && currentDate <= firstSemesterEnd){
        ui->lineEdit_subjectCourseBF->setText(FirstSem);}
    else{
        ui->lineEdit_subjectCourseBF->setText(SecondSem);
    }
    ui->lineEdit_professorBF->setText(Professor);
}

void DashboardWindow::refreshTime()     //REFRESH TIME AND SETTING THE DATA AND TIME IN CURRENT
{
    ui->dateEdit_borrowDateBF->setDate(QDate::currentDate());
    ui->timeEdit_borrowTimeBF->setTime(QTime::currentTime());
/*
    QTime recentTime = ui->timeEdit_borrowTimeBF->time();
    QTime expectedReturnTime = recentTime.addSecs(3 * 3600);  // Adding 3 hours to the current time
    ui->timeEdit_borrowExpectedTimeBF->setTime(expectedReturnTime); */
}

void DashboardWindow::on_pushButton_timeRefresh_clicked()
{
    refreshTime();
}

bool DashboardWindow::requiredField(){      //CODE FOR REQUIRED I-FILL OUT MGA LINE EDITS
    //CODE NA REQUIRED MAY LAMAN YUNG MGA FIELDS
    if (ui->lineEdit_studentNumberBF->text().isEmpty() || ui->lineEdit_studentNumberBF->text().isEmpty() || ui->lineEdit_studentNameBF->text().isEmpty() || ui->lineEdit_subjectCourseBF->text().isEmpty() ||
        ui->lineEdit_professorBF->text().isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please fill in all fields.");
        return false;
    }
    return true;
}

bool DashboardWindow::requiredRadioButton(){    //CODE FOR REQUIRED THE RADIO BUTTONS TO BE CLICKED
    //CODE NA REQUIRED PINDUTIN RADIO BUTTON
    //if (!ui->radioButton_PSignatureBF->isChecked() || !ui->radioButton_receiveIDBF->isChecked()){

    if (!ui->radioButton_receiveIDBF->isChecked()){
        QMessageBox::warning(this, "Warning", "Please check the radioButtons.");
        return false;
    }
    return true;
}

void DashboardWindow::on_pushButton_submitBF_clicked()      //submit button in borrow form
{
    if (requiredField() && requiredRadioButton()) {
        insertNewBorrowData();
        insertBorrowHistoryData();
        updateToolCounts();
        clearForm();
    }
}

void DashboardWindow::insertNewBorrowData() //INSERT FROM DATABASE NA NARERECORD LAHAT NG HISTORY NG PAGHIRAM PERO MORE ON RECENT BORROWERS DAPAT ANDITO SINCE NEED I-LIMIT YUNG PAGHIRAM NG TOOLS
{
    QString Date = ui->dateEdit_borrowDateBF->text();
    QString Months = Date.left(1); // Extract the first character
    QString Year = Date.right(4); // Extract the last four characters

    QString AC_Supply = "Did Not Borrow";
    QString Alligator_Clips = "Did Not Borrow";
    QString Breadboard = "Did Not Borrow";
    QString DC_Supply = "Did Not Borrow";
    QString Digital_Multimeter = "Did Not Borrow";
    QString MController = "Did Not Borrow";
    QString MTransformer = "Did Not Borrow";
    QString Oscilloscope = "Did Not Borrow";
    QString VP_Supply = "Did Not Borrow";
    QString ID_Condition = "Unclaim";
    QString PSignature = "Unclaim";

    if (ui->checkBox_acSupply->isChecked()) {
        AC_Supply = "In Use";
    }
    if (ui->checkBox_alligatorClips->isChecked()) {
        Alligator_Clips = "In Use";
    }
    if (ui->checkBox_breadBoard->isChecked()) {
        Breadboard = "In Use";
    }
    if (ui->checkBox_dcSupply->isChecked()) {
        DC_Supply = "In Use";
    }
    if (ui->checkBox_digitalMultimeter->isChecked()) {
        Digital_Multimeter = "In Use";
    }
    if (ui->checkBox_mcontrol->isChecked()) {
        MController = "In Use";
    }
    if (ui->checkBox_MTransformer->isChecked()) {
        MTransformer = "In Use";
    }
    if (ui->checkBox_oscilloscope->isChecked()) {
        Oscilloscope = "In Use";
    }
    if (ui->checkBox_vpSupply->isChecked()) {
        VP_Supply = "In Use";
    }
    if (ui->radioButton_receiveIDBF->isChecked()) {
        ID_Condition = "Receive";
    }

    /*if (ui->radioButton_PSignatureBF->isChecked()) {
        PSignature = "Receive";
    }*/


    requiredField();
    requiredRadioButton();

    QSqlQuery query;
    query.prepare("INSERT INTO borrow (Year, Months, Date, Time, Student_Name, Student_Number, Year_Block, Subject_Course, Professor, AC_Supply, Alligator_Clips, Breadboard, DC_Supply, Digital_Multimeter, MController, MTransformer, Oscilloscope, VP_Supply, PSignature, ID_Condition) "
                  "VALUES (:Year, :Months, :Date, :Time, :Student_Name, :Student_Number, :Year_Block, :Subject_Course, :Professor, :AC_Supply, :Alligator_Clips, :Breadboard, :DC_Supply, :Digital_Multimeter, :MController, :MTransformer, :Oscilloscope, :VP_Supply, :PSignature, :ID_Condition)");

    query.bindValue(":Year", Year);
    query.bindValue(":Months", Months);
    query.bindValue(":Date", ui->dateEdit_borrowDateBF->text());
    query.bindValue(":Time", ui->timeEdit_borrowTimeBF->text());
    //query.bindValue(":Expected_Time", ui->timeEdit_borrowExpectedTimeBF->text());

    query.bindValue(":Student_Name", ui->lineEdit_studentNameBF->text());
    query.bindValue(":Student_Number", ui->lineEdit_studentNumberBF->text());
    query.bindValue(":Year_Block", ui->lineEdit_yearSectionBF->text());
    query.bindValue(":Subject_Course", ui->lineEdit_subjectCourseBF->text());
    query.bindValue(":Professor", ui->lineEdit_professorBF->text());

    query.bindValue(":AC_Supply", AC_Supply);
    query.bindValue(":Alligator_Clips", Alligator_Clips);
    query.bindValue(":Breadboard", Breadboard);
    query.bindValue(":DC_Supply", DC_Supply);
    query.bindValue(":Digital_Multimeter", Digital_Multimeter);
    query.bindValue(":MController", MController);
    query.bindValue(":MTransformer", MTransformer);
    query.bindValue(":Oscilloscope", Oscilloscope);
    query.bindValue(":VP_Supply", VP_Supply);

    query.bindValue(":PSignature", PSignature);
    query.bindValue(":ID_Condition", ID_Condition);

    if(!query.exec()){
        qWarning() <<"Failed to insert record in the borrowHistory: " <<query.lastError().text();
        return;
    }

    else{
        QMessageBox::information(this, "Message", "New data is successfully added");
    }

}

void DashboardWindow::insertBorrowHistoryData() //INSERT FROM DATABASE NA NARERECORD LAHAT NG HISTORY NG PAGHIRAM
{
    QString Date = ui->dateEdit_borrowDateBF->text();
    QString Months = Date.left(1); // Extract the first character
    QString Year = Date.right(4); // Extract the last four characters

    QString AC_Supply = "Did Not Borrow";
    QString Alligator_Clips = "Did Not Borrow";
    QString Breadboard = "Did Not Borrow";
    QString DC_Supply = "Did Not Borrow";
    QString Digital_Multimeter = "Did Not Borrow";
    QString MController = "Did Not Borrow";
    QString MTransformer = "Did Not Borrow";
    QString Oscilloscope = "Did Not Borrow";
    QString VP_Supply = "Did Not Borrow";
    QString ID_Condition = "Unclaim";
    QString PSignature = "Unclaim";

    if (ui->checkBox_acSupply->isChecked()) {
        AC_Supply = "In Use";
    }
    if (ui->checkBox_alligatorClips->isChecked()) {
        Alligator_Clips = "In Use";
    }
    if (ui->checkBox_breadBoard->isChecked()) {
        Breadboard = "In Use";
    }
    if (ui->checkBox_dcSupply->isChecked()) {
        DC_Supply = "In Use";
    }
    if (ui->checkBox_digitalMultimeter->isChecked()) {
        Digital_Multimeter = "In Use";
    }
    if (ui->checkBox_mcontrol->isChecked()) {
        MController = "In Use";
    }
    if (ui->checkBox_MTransformer->isChecked()) {
        MTransformer = "In Use";
    }
    if (ui->checkBox_oscilloscope->isChecked()) {
        Oscilloscope = "In Use";
    }
    if (ui->checkBox_vpSupply->isChecked()) {
        VP_Supply = "In Use";
    }
    /*
    if (ui->radioButton_PSignatureBF->isChecked()) {
        PSignature = "Receive";
    }*/
    if (ui->radioButton_receiveIDBF->isChecked()) {
        ID_Condition = "Receive";
    }

    requiredField();
    requiredRadioButton();

    QSqlQuery query;
    query.prepare("INSERT INTO borrowHistory (Year, Months, Date, Time, Student_Name, Student_Number, Year_Block, Subject_Course, Professor, AC_Supply, Alligator_Clips, Breadboard, DC_Supply, Digital_Multimeter, MController, MTransformer, Oscilloscope, VP_Supply, PSignature, ID_Condition) "
                  "VALUES (:Year, :Months, :Date, :Time, :Student_Name, :Student_Number, :Year_Block, :Subject_Course, :Professor, :AC_Supply, :Alligator_Clips, :Breadboard, :DC_Supply, :Digital_Multimeter, :MController, :MTransformer, :Oscilloscope, :VP_Supply, :PSignature, :ID_Condition)");

    query.bindValue(":Year", Year);
    query.bindValue(":Months", Months);
    query.bindValue(":Date", ui->dateEdit_borrowDateBF->text());
    query.bindValue(":Time", ui->timeEdit_borrowTimeBF->text());
    //query.bindValue(":Expected_Time", ui->timeEdit_borrowExpectedTimeBF->text());

    query.bindValue(":Student_Name", ui->lineEdit_studentNameBF->text());
    query.bindValue(":Student_Number", ui->lineEdit_studentNumberBF->text());
    query.bindValue(":Year_Block", ui->lineEdit_yearSectionBF->text());
    query.bindValue(":Subject_Course", ui->lineEdit_subjectCourseBF->text());
    query.bindValue(":Professor", ui->lineEdit_professorBF->text());

    query.bindValue(":AC_Supply", AC_Supply);
    query.bindValue(":Alligator_Clips", Alligator_Clips);
    query.bindValue(":Breadboard", Breadboard);
    query.bindValue(":DC_Supply", DC_Supply);
    query.bindValue(":Digital_Multimeter", Digital_Multimeter);
    query.bindValue(":MController", MController);
    query.bindValue(":MTransformer", MTransformer);
    query.bindValue(":Oscilloscope", Oscilloscope);
    query.bindValue(":VP_Supply", VP_Supply);

    query.bindValue(":PSignature", PSignature);
    query.bindValue(":ID_Condition", ID_Condition);

    if(!query.exec()){
        qWarning() <<"Failed to insert record in the borrowHistory: " <<query.lastError().text();
        return;
    }

}

void DashboardWindow::clearForm() //CLEAR FUNCTION
{
    refreshTime();

    ui->lineEdit_studentNameBF->clear();
    ui->lineEdit_studentNumberBF->clear();
    ui->lineEdit_studentNumberSearchBF->clear();
    ui->lineEdit_yearSectionBF->clear();
    ui->lineEdit_subjectCourseBF->clear();
    ui->lineEdit_professorBF->clear();

    ui->checkBox_acSupply->setChecked(false);
    ui->checkBox_alligatorClips->setChecked(false);
    ui->checkBox_breadBoard->setChecked(false);
    ui->checkBox_dcSupply->setChecked(false);
    ui->checkBox_digitalMultimeter->setChecked(false);
    ui->checkBox_mcontrol->setChecked(false);
    ui->checkBox_MTransformer->setChecked(false);
    ui->checkBox_oscilloscope->setChecked(false);
    ui->checkBox_vpSupply->setChecked(false);

    //ui->radioButton_PSignatureBF->setChecked(false);
    ui->radioButton_receiveIDBF->setChecked(false);
}

void DashboardWindow::updateToolCounts() //IN THE BORROWING FORM, TAGA LIMIT NG MGA TOOLS NA HINIHIRAM KAYA NAGDIDISABLE YUNG CHECK BOX IF 'IN USE' NA LAHAT NG TOOLS
{
    QSqlQuery query;

    // AC Supply
    query.exec("SELECT COUNT(*) FROM borrow WHERE AC_Supply = 'In Use'");
    if (query.next()) {
        int inUseACSupply = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 1");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableACSupply = Quantity - inUseACSupply;
            ui->label_availableACSupply->setText(QString::number(availableACSupply));
            //ui->label_inUseACSupply->setText(QString::number(inUseACSupply));

            ui->checkBox_acSupply->setEnabled(availableACSupply > 0);
        }
    }

    // Alligator Clips
    query.exec("SELECT COUNT(*) FROM borrow WHERE Alligator_Clips = 'In Use'");
    if (query.next()) {
        int inUseAlligatorClips = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 2");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();
            int availableAlligatorClips = Quantity - inUseAlligatorClips;
            ui->label_availableAlligatorClips->setText(QString::number(availableAlligatorClips));
            //ui->label_inUseAlligatorClips->setText(QString::number(inUseAlligatorClips));

            ui->checkBox_alligatorClips->setEnabled(availableAlligatorClips > 0);
        }
    }

    // Breadboard
    query.exec("SELECT COUNT(*) FROM borrow WHERE Breadboard = 'In Use'");
    if (query.next()) {
        int inUseBreadboard = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 3");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableBreadboard = Quantity - inUseBreadboard;
            ui->label_availableBreadboard->setText(QString::number(availableBreadboard));
            //ui->label_inUseBreadboard->setText(QString::number(inUseBreadboard));

            ui->checkBox_breadBoard->setEnabled(availableBreadboard > 0);
        }
    }

    // DC Supply
    query.exec("SELECT COUNT(*) FROM borrow WHERE DC_Supply = 'In Use'");
    if (query.next()) {
        int inUseDCSupply = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 4");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableDCSupply = Quantity - inUseDCSupply;
            ui->label_availableDCSupply->setText(QString::number(availableDCSupply));
            //ui->label_inUseDCSupply->setText(QString::number(inUseDCSupply));

            ui->checkBox_dcSupply->setEnabled(availableDCSupply > 0);
        }
    }

    // Digital Multimeter
    query.exec("SELECT COUNT(*) FROM borrow WHERE Digital_Multimeter = 'In Use'");
    if (query.next()) {
        int inUseDigitalMultimeter = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 5");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableDigitalMultimeter = Quantity - inUseDigitalMultimeter;
            ui->label_availableDigitalMultimeter->setText(QString::number(availableDigitalMultimeter));
            //ui->label_inUseDigitalMultimeter->setText(QString::number(inUseDigitalMultimeter));

            ui->checkBox_digitalMultimeter->setEnabled(availableDigitalMultimeter > 0);
        }
    }

    // Micro Controller
    query.exec("SELECT COUNT(*) FROM borrow WHERE MController = 'In Use'");
    if (query.next()) {
        int inUseMicroController = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 6");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableMicroController = Quantity - inUseMicroController;
            ui->label_availableMicroController->setText(QString::number(availableMicroController));
            //ui->label_inUseMicroController->setText(QString::number(inUseMicroController));

            ui->checkBox_mcontrol->setEnabled(availableMicroController > 0);
        }
    }

    // Multi tap transformer
    query.exec("SELECT COUNT(*) FROM borrow WHERE MTransformer = 'In Use'");
    if (query.next()) {
        int inUseMultiTapTransformer = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 7");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableMultiTapTransformer = Quantity - inUseMultiTapTransformer;
            ui->label_availableMultiTapTransformer->setText(QString::number(availableMultiTapTransformer));
            //ui->label_inUseMultiTapTransformer->setText(QString::number(inUseMultiTapTransformer));

            ui->checkBox_MTransformer->setEnabled(availableMultiTapTransformer > 0);
        }
    }

    // Oscilloscope
    query.exec("SELECT COUNT(*) FROM borrow WHERE Oscilloscope = 'In Use'");
    if (query.next()) {
        int inUseOscilloscope = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 8");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableOscilloscope = Quantity - inUseOscilloscope;
            ui->label_availableOscilloscope->setText(QString::number(availableOscilloscope));
            //ui->label_inUseOscilloscope->setText(QString::number(inUseOscilloscope));

            ui->checkBox_oscilloscope->setEnabled(availableOscilloscope > 0);
        }
    }

    // Variable Power Supply
    query.exec("SELECT COUNT(*) FROM borrow WHERE VP_Supply = 'In Use'");
    if (query.next()) {
        int inUseVariablePowerSupply = query.value(0).toInt();

        // Retrieve the available quantity from the database
        query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 9");
        if (query.next()) {
            int Quantity = query.value("Quantity").toInt();

            int availableVariablePowerSupply = Quantity - inUseVariablePowerSupply;
            ui->label_availableVariablePowerSupply->setText(QString::number(availableVariablePowerSupply));
            //ui->label_inUseVariablePowerSupply->setText(QString::number(inUseVariablePowerSupply));

            ui->checkBox_vpSupply->setEnabled(availableVariablePowerSupply > 0);
        }
    }

    ui->pushButton_submitBF->setEnabled(true);
}

/*
 *  TOOLS INFO  TOOLS INFO  TOOLS INFO
 *  TOOLS INFO  TOOLS INFO  TOOLS INFO
 *  TOOLS INFO  TOOLS INFO  TOOLS INFO
 */

void DashboardWindow::updateCountsToolsInfo()
{
    QSqlQuery query;

    // AC Supply
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 1");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dAC->setText(QString::number(Quantity));
    }
    // Alligator Clips
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 2");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dALC->setText(QString::number(Quantity));
    }
    // Breadboard
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 3");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dBB->setText(QString::number(Quantity));
    }
    // DC Supply
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 4");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dDC->setText(QString::number(Quantity));
    }
    // Digital Multimeter
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 5");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dMULTI->setText(QString::number(Quantity));
    }
    // Micro Controller
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 6");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dCONTROL->setText(QString::number(Quantity));
    }
    // Multi-tap transformer
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 7");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dTRANSFORM->setText(QString::number(Quantity));
    }
    // Oscilloscope
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 8");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dOSCILLOSCOPE->setText(QString::number(Quantity));
    }
    // Variable Power Supply
    query.exec("SELECT Quantity FROM toolsInfo WHERE ID = 9");
    if (query.next()) {
        int Quantity = query.value("Quantity").toInt();
        ui->lineEdit_dVP->setText(QString::number(Quantity));
    }
}

void DashboardWindow::increaseQuantity(int id) //AUTOMATIC MAG-UPDATE SA DATABASE YUNG VALUES KAPAG NAG-ADD KA NG TOOLS
{
    // Get the current quantity of the tool from the database
    QSqlQuery query;
    query.prepare("SELECT Quantity FROM toolsInfo WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int currentQuantity = query.value(0).toInt();

        // Increase the quantity by 1
        int newQuantity = currentQuantity + 1;

        // Update the quantity in the database
        query.prepare("UPDATE toolsInfo SET Quantity = :quantity WHERE ID = :id");
        query.bindValue(":quantity", newQuantity);
        query.bindValue(":id", id);

        if (query.exec()) {
            qDebug() << "Quantity increased successfully for tool with ID" << id;
            // Update the corresponding QLineEdit field
            switch (id) {
            case 1:
                ui->lineEdit_dAC->setText(QString::number(newQuantity));
                break;
            case 2:
                ui->lineEdit_dALC->setText(QString::number(newQuantity));
                break;
            case 3:
                ui->lineEdit_dBB->setText(QString::number(newQuantity));
                break;
            case 4:
                ui->lineEdit_dDC->setText(QString::number(newQuantity));
                break;
            case 5:
                ui->lineEdit_dMULTI->setText(QString::number(newQuantity));
                break;
            case 6:
                ui->lineEdit_dCONTROL->setText(QString::number(newQuantity));
                break;
            case 7:
                ui->lineEdit_dTRANSFORM->setText(QString::number(newQuantity));
                break;
            case 8:
                ui->lineEdit_dOSCILLOSCOPE->setText(QString::number(newQuantity));
                break;
            case 9:
                ui->lineEdit_dVP->setText(QString::number(newQuantity));
                break;
            default:
                break;
            }
        } else {
            qDebug() << "Error: Failed to increase quantity for tool with ID" << id << query.lastError();
        }
    } else {
        qDebug() << "Error: Failed to retrieve current quantity for tool with ID" << id << query.lastError();
    }
}

void DashboardWindow::decreaseQuantity(int id)  //AUTOMATIC MAG-UPDATE SA DATABASE YUNG VALUES KAPAG NAG BAWAS KA NG TOOLS
{
    // Get the current quantity of the tool from the database
    QSqlQuery query;
    query.prepare("SELECT Quantity FROM toolsInfo WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int currentQuantity = query.value(0).toInt();

        // Decrease the quantity by 1
        int newQuantity = currentQuantity - 1;

        // Update the quantity in the database
        query.prepare("UPDATE toolsInfo SET Quantity = :quantity WHERE ID = :id");
        query.bindValue(":quantity", newQuantity);
        query.bindValue(":id", id);

        if (query.exec()) {
            qDebug() << "Quantity decreased successfully for tool with ID" << id;
            // Update the corresponding QLineEdit field
            switch (id) {
            case 1:
                ui->lineEdit_dAC->setText(QString::number(newQuantity));
                break;
            case 2:
                ui->lineEdit_dALC->setText(QString::number(newQuantity));
                break;
            case 3:
                ui->lineEdit_dBB->setText(QString::number(newQuantity));
                break;
            case 4:
                ui->lineEdit_dDC->setText(QString::number(newQuantity));
                break;
            case 5:
                ui->lineEdit_dMULTI->setText(QString::number(newQuantity));
                break;
            case 6:
                ui->lineEdit_dCONTROL->setText(QString::number(newQuantity));
                break;
            case 7:
                ui->lineEdit_dTRANSFORM->setText(QString::number(newQuantity));
                break;
            case 8:
                ui->lineEdit_dOSCILLOSCOPE->setText(QString::number(newQuantity));
                break;
            case 9:
                ui->lineEdit_dVP->setText(QString::number(newQuantity));
                break;
            default:
                break;
            }
        } else {
            qDebug() << "Error: Failed to decrease quantity for tool with ID" << id << query.lastError();
        }
    } else {
        qDebug() << "Error: Failed to retrieve current quantity for tool with ID" << id << query.lastError();
    }
}

//BUTTONS PARA MAGING FUNCTION YUNG PAG-UPDATE NG DATABASE VALUES LIKE ANDITO YUNG NAG-AADD "INCREASE QUANTITY" AND NAGMA-MINUS "DECREASE QUANTITY".
void DashboardWindow::on_pushButton_minusAC_2_clicked()
{
    increaseQuantity(1);
}
void DashboardWindow::on_pushButton_minusAlligator_2_clicked()
{
    increaseQuantity(2);
}
void DashboardWindow::on_pushButton_minusBboard_2_clicked()
{
    increaseQuantity(3);
}
void DashboardWindow::on_pushButton_minusDC_2_clicked()
{
    increaseQuantity(4);
}
void DashboardWindow::on_pushButton_minusMulti_2_clicked()
{
    increaseQuantity(5);
}
void DashboardWindow::on_pushButton_minusControl_2_clicked()
{
    increaseQuantity(6);
}
void DashboardWindow::on_pushButton_minusTransform_2_clicked()
{
    increaseQuantity(7);
}
void DashboardWindow::on_pushButton_minusOscilloscope_2_clicked()
{
    increaseQuantity(8);
}
void DashboardWindow::on_pushButton_minusVP_2_clicked()
{
    increaseQuantity(9);
}
void DashboardWindow::on_pushButton_minusAC_clicked()
{
    decreaseQuantity(1);
}
void DashboardWindow::on_pushButton_minusAlligator_clicked()
{
    decreaseQuantity(2);
}
void DashboardWindow::on_pushButton_minusBboard_clicked()
{
    decreaseQuantity(3);
}
void DashboardWindow::on_pushButton_minusDC_clicked()
{
    decreaseQuantity(4);
}
void DashboardWindow::on_pushButton_minusMulti_clicked()
{
    decreaseQuantity(5);
}
void DashboardWindow::on_pushButton_minusControl_clicked()
{
    decreaseQuantity(6);
}
void DashboardWindow::on_pushButton_minusTransform_clicked()
{
    decreaseQuantity(7);
}
void DashboardWindow::on_pushButton_minusOscilloscope_clicked()
{
    decreaseQuantity(8);
}
void DashboardWindow::on_pushButton_minusVP_clicked()
{
    decreaseQuantity(9);
}

/*
 *  RETURNED TOOLS  RETURNED TOOLS  RETURNED TOOLS
 *  RETURNED TOOLS  RETURNED TOOLS  RETURNED TOOLS
 *  RETURNED TOOLS  RETURNED TOOLS  RETURNED TOOLS
 */

void DashboardWindow::openBorrowedTools(){       //TABLE VIEW, BY DEFAULTS KUNG ANO YUNG TATAWAGING YEAR KAYA KAPAG 2024, PURO 2024 LNG LALABAS NA STUDENTS
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(QString("SELECT Date, Time, Student_Number, Student_Name, Year_Block, Subject_Course, Professor, AC_Supply, Alligator_Clips, Breadboard, DC_Supply, Digital_Multimeter, MController, MTransformer, Oscilloscope, VP_Supply "
                            "FROM borrow "
                            "ORDER BY Time ASC"));
    ui->tableView_borrowedTools->setModel(model);
    ui->tableView_borrowedTools->resizeColumnsToContents();
}

void DashboardWindow::on_tableView_borrowedTools_activated(const QModelIndex &index)
{
    QString Date = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 0)).toString();
    QString Time = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 1)).toString();
    QString Student_Number = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 2)).toString();
    QString Student_Name = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 3)).toString();
    QString Year_Block = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 4)).toString();
    QString Subject_Course = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 5)).toString();
    QString professor = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 6)).toString();
    QString AC_Supply = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 7)).toString();
    QString Alligator_Clips = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 8)).toString();
    QString Breadboard = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 9)).toString();
    QString DC_Supply = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 10)).toString();
    QString Digital_Multimeter = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 11)).toString();
    QString MController = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 12)).toString();
    QString MTransformer = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 13)).toString();
    QString Oscilloscope = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 14)).toString();
    QString VP_Supply = ui->tableView_borrowedTools->model()->data(ui->tableView_borrowedTools->model()->index(index.row(), 15)).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM borrow WHERE Student_Number = :Student_Number "
                  "AND Student_Name = :Student_Name "
                  "AND Date = :Date "
                  "AND Time = :Time "
                  "AND Year_Block = :Year_Block "
                  "AND Subject_Course = :Subject_Course "
                  "AND Professor = :Professor "
                  "AND AC_Supply = :AC_Supply "
                  "AND Alligator_Clips = :Alligator_Clips "
                  "AND Breadboard = :Breadboard "
                  "AND DC_Supply = :DC_Supply "
                  "AND Digital_Multimeter = :Digital_Multimeter "
                  "AND MController = :MController "
                  "AND MTransformer = :MTransformer "
                  "AND Oscilloscope = :Oscilloscope "
                  "AND VP_Supply = :VP_Supply ");

    query.bindValue(":Student_Number", Student_Number);
    query.bindValue(":Student_Name", Student_Name);
    query.bindValue(":Date", Date);
    query.bindValue(":Time", Time);
    query.bindValue(":Year_Block", Year_Block);
    query.bindValue(":Subject_Course", Subject_Course);
    query.bindValue(":Professor", professor);
    query.bindValue(":AC_Supply", AC_Supply);
    query.bindValue(":Alligator_Clips", Alligator_Clips);
    query.bindValue(":Breadboard", Breadboard);
    query.bindValue(":DC_Supply", DC_Supply);
    query.bindValue(":Digital_Multimeter", Digital_Multimeter);
    query.bindValue(":MController", MController);
    query.bindValue(":MTransformer", MTransformer);
    query.bindValue(":Oscilloscope", Oscilloscope);
    query.bindValue(":VP_Supply", VP_Supply);

    if (query.exec()) {
        if (query.next()) {
            ui->lineEdit_borrowDateRT->setText(query.value("Date").toString());
            ui->lineEdit_borrowTimeRT->setText(query.value("Time").toString());
            ui->lineEdit_studentNameBF_2->setText(query.value("Student_Name").toString());
            ui->lineEdit_studentNumberBF_2->setText(query.value("Student_Number").toString());
            ui->lineEdit_yearSectionBF_2->setText(query.value("Year_Block").toString());
            ui->lineEdit_subjectCourseBF_2->setText(query.value("Subject_Course").toString());
            ui->lineEdit_professorBF_2->setText(query.value("Professor").toString());

            ui->label_BSACSupply->setText(query.value("AC_Supply").toString());
            ui->label_BSAlligatorClips->setText(query.value("Alligator_Clips").toString());
            ui->label_BSBreadboard->setText(query.value("Breadboard").toString());
            ui->label_BSDCSupply->setText(query.value("DC_Supply").toString());
            ui->label_BSMultimeter->setText(query.value("Digital_Multimeter").toString());
            ui->label_BSController->setText(query.value("MController").toString());
            ui->label_BSTransformer->setText(query.value("MTransformer").toString());
            ui->label_BSoscilloscope->setText(query.value("Oscilloscope").toString());
            ui->label_BSvpSupply->setText(query.value("VP_Supply").toString());

        } else {
            qDebug() << "No data found";
        }
    } else {
        QMessageBox::warning(this, "Warning Message", "Failed to retrieve student info.");
    }

    toolCondition();
}

void DashboardWindow::toolCondition(){

    if (ui->label_BSACSupply->text() == "Did Not Borrow") {
        ui->lineEdit_acCondition->setText("Nothing To Return");
    }
    if (ui->label_BSAlligatorClips->text() == "Did Not Borrow") {
        ui->lineEdit_alligatorCondition->setText("Nothing To Return");
    }
    if (ui->label_BSBreadboard->text() == "Did Not Borrow") {
        ui->lineEdit_bbCondition->setText("Nothing To Return");
    }
    if (ui->label_BSDCSupply->text() == "Did Not Borrow") {
        ui->lineEdit_dcCondition->setText("Nothing To Return");
    }
    if (ui->label_BSMultimeter->text() == "Did Not Borrow") {
        ui->lineEdit_multimeterCondition->setText("Nothing To Return");
    }
    if (ui->label_BSController->text() == "Did Not Borrow") {
        ui->lineEdit_controllerCondition->setText("Nothing To Return");
    }
    if (ui->label_BSTransformer->text() == "Did Not Borrow") {
        ui->lineEdit_transformerCondition->setText("Nothing To Return");
    }
    if (ui->label_BSoscilloscope->text() == "Did Not Borrow") {
        ui->lineEdit_osciCondition->setText("Nothing To Return");
    }
    if (ui->label_BSvpSupply->text() == "Did Not Borrow") {
        ui->lineEdit_vpSupplyCondition->setText("Nothing To Return");
    }


}
void DashboardWindow::insertReturn() {
    // Codes for inserting data into the return table in the database

    QString Date = ui->lineEdit_borrowDateRT->text();
    QString Time = ui->lineEdit_borrowTimeRT->text();

    QString Rdate = ui->dateEdit_returnDate->text();
    QString Rtime = ui->timeEdit_returnTime->text();

    QString Student_Number = ui->lineEdit_studentNumberBF_2->text();
    QString Student_Name = ui->lineEdit_studentNameBF_2->text();
    QString Year_Block = ui->lineEdit_yearSectionBF_2->text();
    QString Subject_Course = ui->lineEdit_subjectCourseBF_2->text();
    QString Professor = ui->lineEdit_professorBF_2->text();

    QString AC_Supply = ui->lineEdit_acCondition->text();
    QString Alligator_Clips = ui->lineEdit_alligatorCondition->text();
    QString Breadboard = ui->lineEdit_bbCondition->text();
    QString DC_Supply = ui->lineEdit_dcCondition->text();
    QString Digital_Multimeter = ui->lineEdit_multimeterCondition->text();
    QString MController = ui->lineEdit_controllerCondition->text();
    QString MTransformer = ui->lineEdit_transformerCondition->text();
    QString Oscilloscope = ui->lineEdit_osciCondition->text();
    QString VP_Supply = ui->lineEdit_vpSupplyCondition->text();

    QSqlQuery query;
    query.prepare("INSERT INTO return (Date, Time, Rdate, Rtime, Student_Name, Student_Number, Year_Block, Subject_Course, Professor, AC_Supply, Alligator_Clips, Breadboard, DC_Supply, Digital_Multimeter, MController, MTransformer, Oscilloscope, VP_Supply) "
                  "VALUES (:Date, :Time, :Rdate, :Rtime, :Student_Name, :Student_Number, :Year_Block, :Subject_Course, :Professor, :AC_Supply, :Alligator_Clips, :Breadboard, :DC_Supply, :Digital_Multimeter, :MController, :MTransformer, :Oscilloscope, :VP_Supply)");

    query.bindValue(":Date", Date);
    query.bindValue(":Time", Time);
    query.bindValue(":Rdate", Rdate);
    query.bindValue(":Rtime", Rtime);
    query.bindValue(":Student_Name", Student_Name);
    query.bindValue(":Student_Number", Student_Number);
    query.bindValue(":Year_Block", Year_Block);
    query.bindValue(":Subject_Course", Subject_Course);
    query.bindValue(":Professor", Professor);
    query.bindValue(":AC_Supply", AC_Supply);
    query.bindValue(":Alligator_Clips", Alligator_Clips);
    query.bindValue(":Breadboard", Breadboard);
    query.bindValue(":DC_Supply", DC_Supply);
    query.bindValue(":Digital_Multimeter", Digital_Multimeter);
    query.bindValue(":MController", MController);
    query.bindValue(":MTransformer", MTransformer);
    query.bindValue(":Oscilloscope", Oscilloscope);
    query.bindValue(":VP_Supply", VP_Supply);

    if (!query.exec()) {
        qWarning() << "Failed to insert record in the return: " << query.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to add new data");
        return;
    } else {
        QMessageBox::information(this, "Success", "New data is successfully added");
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM borrow WHERE Student_Number = :Student_Number");
    deleteQuery.bindValue(":Student_Number", Student_Number);

    if (!deleteQuery.exec()) {
        qWarning() << "Failed to delete record with Student_Number: " << Student_Number << deleteQuery.lastError().text();
        //QMessageBox::warning(this, "Error", "Failed to delete record");
        return;
    }
}
void DashboardWindow::clearBorrowedTV(){

    ui->lineEdit_borrowDateRT->clear();
    ui->lineEdit_borrowTimeRT->clear();
    ui->dateEdit_returnDate->setDate(QDate::currentDate());
    ui->dateEdit_returnDate->setCalendarPopup(true);
    ui->timeEdit_returnTime->setTime(QTime::currentTime());
    ui->lineEdit_studentNumberBF_2->clear();
    ui->lineEdit_studentNameBF_2->clear();
    ui->lineEdit_yearSectionBF_2->clear();
    ui->lineEdit_subjectCourseBF_2->clear();
    ui->lineEdit_professorBF_2->clear();
    ui->lineEdit_acCondition->clear();
    ui->lineEdit_alligatorCondition->clear();
    ui->lineEdit_bbCondition->clear();
    ui->lineEdit_dcCondition->clear();
    ui->lineEdit_multimeterCondition->clear();
    ui->lineEdit_controllerCondition->clear();
    ui->lineEdit_transformerCondition->clear();
    ui->lineEdit_osciCondition->clear();
    ui->lineEdit_vpSupplyCondition->clear();
    // Clearing all labels
    ui->label_BSACSupply->clear();
    ui->label_BSAlligatorClips->clear();
    ui->label_BSBreadboard->clear();
    ui->label_BSDCSupply->clear();
    ui->label_BSMultimeter->clear();
    ui->label_BSController->clear();
    ui->label_BSTransformer->clear();
    ui->label_BSoscilloscope->clear();
    ui->label_BSvpSupply->clear();
/*
    ui->comboBox_ac->clear();
    ui->comboBox_alligator->clear();
    ui->comboBox_bb->clear();
    ui->comboBox_Controller->clear();
    ui->comboBox_dc->clear();
    ui->comboBox_multimeter->clear();
    ui->comboBox_oscilloscope->clear();
    ui->comboBox_Transformer->clear();
    ui->comboBox_vpSupply->clear();
*/
}

void DashboardWindow::deleteReturn(){
    /*
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM return WHERE Student_Number = :Student_Number");
    deleteQuery.bindValue(":Student_Number", studentNumber);

    if (!deleteQuery.exec()) {
        qWarning() << "Failed to delete record with Student_Number: " << studentNumber << deleteQuery.lastError().text();
        QMessageBox::warning(this, "Error", "Failed to delete record");
        return;
    } else {
        QMessageBox::information(this, "Success", "Data with Student_Number is successfully deleted");
    }
*/
}
void DashboardWindow::on_pushButton_submitBF_2_clicked()
{
    insertReturn();
    deleteReturn();
    clearBorrowedTV();
    openBorrowedTools();
}

//         no Use       //
void DashboardWindow::on_comboBox_ac_activated(int index)
{
}

void DashboardWindow::on_comboBox_ac_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_acCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_alligator_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_alligatorCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_bb_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_bbCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_dc_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_dcCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_multimeter_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_multimeterCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_Controller_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_controllerCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_Transformer_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_transformerCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_oscilloscope_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_osciCondition->setText(arg1);
}
void DashboardWindow::on_comboBox_vpSupply_currentTextChanged(const QString &arg1)
{
    ui->lineEdit_vpSupplyCondition->setText(arg1);
}


void DashboardWindow::on_pushButton_refreshTReturn_clicked()
{
    ui->dateEdit_returnDate->setDate(QDate::currentDate());
    ui->timeEdit_returnTime->setTime(QTime::currentTime());
}

