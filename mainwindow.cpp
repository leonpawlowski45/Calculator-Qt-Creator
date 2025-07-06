#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calculator.h"
#include <QRegularExpressionValidator>
#include <QMessageBox>

calculator c1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numberInBase10->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9]{0,18}(\\.[0-9]{0,18})?$"), this));
    ui->numberInBase9->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-8]{0,19}(\\.[0-8]{0,19})?$"), this));
    ui->numberInBase8->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-7]{0,19}(\\.[0-7]{0,19})?$"), this));
    ui->numberInBase7->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-6]{0,19}(\\.[0-6]{0,19})?$"), this));
    ui->numberInBase6->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-5]{0,19}(\\.[0-5]{0,19})?$"), this));
    ui->numberInBase5->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-4]{0,19}(\\.[0-4]{0,19})?$"), this));
    ui->numberInBase4->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-3]{0,19}(\\.[0-3]{0,19})?$"), this));
    ui->numberInBase3->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-2]{0,19}(\\.[0-2]{0,19})?$"), this));
    ui->numberInBase2->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-1]{0,19}(\\.[0-1]{0,19})?$"), this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_digit_0_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"0");
}
void MainWindow::on_digit_1_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"1");
}
void MainWindow::on_digit_2_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"2");
}
void MainWindow::on_digit_3_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"3");
}
void MainWindow::on_digit_4_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"4");
}
void MainWindow::on_digit_5_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"5");
}
void MainWindow::on_digit_6_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"6");
}
void MainWindow::on_digit_7_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"7");
}
void MainWindow::on_digit_8_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"8");
}
void MainWindow::on_digit_9_clicked()
{
    QString currentText=ui->display->text();
    ui->display->setText(currentText+"9");
}
void MainWindow::on_dot_clicked()
{
    QString currentText=ui->display->text();
    if(!currentText.contains('.'))
        ui->display->setText(currentText+".");
}
void MainWindow::on_backSpace_clicked()
{
    QString text = ui->display->text();
    text.chop(1);
    ui->display->setText(text);
}
void MainWindow::on_clearDisplay_clicked()
{
    ui->display->clear();
    ui->displayOperation->clear();
    ui->displayFirstNumber->clear();
}
void MainWindow::on_memoryToEquation_clicked()
{
    QString currentText=ui->displayMemory->text();
    if(!(currentText==""))
        ui->display->setText(currentText);
}
void MainWindow::on_clearMemory_clicked()
{
    ui->displayMemory->clear();
}
void MainWindow::on_addToMemory_clicked()
{
    QString currentText=ui->display->text();
    if(currentText!="" && ui->displayOperation->text()=="" && ui->displayFirstNumber->text()==""){
        ui->displayMemory->setText(currentText);
        ui->display->clear();
    }
}
void MainWindow::on_memoryToConversion_clicked()
{
    QString currentText=ui->displayMemory->text();
    if(!(currentText=="")){
        if(currentText[0]=='-')
            currentText.remove(0,1);
        ui->numberInBase10->setText(currentText);
        on_numberInBase10_textEdited(currentText);
    }
}

void MainWindow::handleLogic(QString operation){
    if(operation=="+"){
        c1.addition();
    }
    else if(operation=="-"){
        c1.subtraction();
    }
    else if(operation=="/"){
        c1.division();
    }
    else if(operation=="*"){
        c1.multiplication();
    }
    else if(operation=="%"){
        c1.remainderOfDivision();
    }
}

void MainWindow::on_mathOperationClicked(QString text){
    QString operation=ui->displayOperation->text();
    if(operation==""){
        QString currentText=ui->display->text();
        if(!(currentText=="")){
            bool ok;
            c1.a=currentText.toDouble(&ok);
            ui->displayFirstNumber->setText(QString::number(c1.a));
            ui->displayOperation->setText(text);
            ui->display->clear();
        }
        //else if(text=="-"){
        //    ui->display->setText(text);
        //}
    }
    else{
        QString currentText=ui->display->text();
        if(currentText=="")
            ui->displayOperation->setText(text);
        else{
            bool ok;
            c1.b=currentText.toDouble(&ok);
            if(c1.b==0&&(operation=="/"||operation=="%")){
                QMessageBox::warning(this, "Error", "Cannot divide by 0!");
                ui->display->clear();
            }
            else{
                handleLogic(operation);
                ui->displayMemory->setText(QString::number(c1.mem));
                c1.a=c1.mem;
                ui->displayFirstNumber->setText(QString::number(c1.a));
                ui->displayOperation->setText(text);
                ui->display->clear();
            }
        }
    }
}

void MainWindow::on_addition_clicked()
{
    on_mathOperationClicked("+");
}
void MainWindow::on_subtraction_clicked()
{
    on_mathOperationClicked("-");
}
void MainWindow::on_division_clicked()
{
    on_mathOperationClicked("/");
}
void MainWindow::on_multiplication_clicked()
{
    on_mathOperationClicked("*");
}
void MainWindow::on_modulo_clicked()
{
    on_mathOperationClicked("%");
}
void MainWindow::on_equals_clicked()
{
    QString currentText=ui->display->text();
    if(!(currentText=="")){
        QString operation=ui->displayOperation->text();
        bool ok;
        c1.b=currentText.toDouble(&ok);
        if(c1.b==0&&(operation=="/"||operation=="%")){
            QMessageBox::warning(this, "Error", "Cannot divide by 0!");
            ui->display->clear();
        }
        else{
            handleLogic(operation);
            ui->displayMemory->setText(QString::number(c1.mem));

            c1.a=c1.mem;
            ui->displayFirstNumber->clear();
            ui->displayOperation->clear();
            ui->display->clear();
        }
    }
}

void MainWindow::on_negativeNumber_clicked()
{
    QString currentText=ui->display->text();
    if(currentText!=""){
        if(currentText[0]=="-")
            currentText.remove(0,1);
        else
            currentText="-"+currentText;
        ui->display->setText(currentText);
    }
    else
        ui->display->setText("-");
}

void MainWindow::numberInBaseFrom2to9(int base,const QString &arg1){
    c1.number=arg1;
    c1.numberSystemConversionFrom2to9To10(base,c1.number);
    if(base!=2)
        ui->numberInBase2->setText(c1.numberSystemConversionFrom10To2to9(2,c1.number));
    if(base!=3)
        ui->numberInBase3->setText(c1.numberSystemConversionFrom10To2to9(3,c1.number));
    if(base!=4)
        ui->numberInBase4->setText(c1.numberSystemConversionFrom10To2to9(4,c1.number));
    if(base!=5)
        ui->numberInBase5->setText(c1.numberSystemConversionFrom10To2to9(5,c1.number));
    if(base!=6)
        ui->numberInBase6->setText(c1.numberSystemConversionFrom10To2to9(6,c1.number));
    if(base!=7)
        ui->numberInBase7->setText(c1.numberSystemConversionFrom10To2to9(7,c1.number));
    if(base!=8)
        ui->numberInBase8->setText(c1.numberSystemConversionFrom10To2to9(8,c1.number));
    if(base!=9)
        ui->numberInBase9->setText(c1.numberSystemConversionFrom10To2to9(9,c1.number));
    ui->numberInBase10->setText(c1.number);
}
void MainWindow::on_numberInBase10_textEdited(const QString &arg1)
{
    c1.number=arg1;
    ui->numberInBase2->setText(c1.numberSystemConversionFrom10To2to9(2,c1.number));
    ui->numberInBase3->setText(c1.numberSystemConversionFrom10To2to9(3,c1.number));
    ui->numberInBase4->setText(c1.numberSystemConversionFrom10To2to9(4,c1.number));
    ui->numberInBase5->setText(c1.numberSystemConversionFrom10To2to9(5,c1.number));
    ui->numberInBase6->setText(c1.numberSystemConversionFrom10To2to9(6,c1.number));
    ui->numberInBase7->setText(c1.numberSystemConversionFrom10To2to9(7,c1.number));
    ui->numberInBase8->setText(c1.numberSystemConversionFrom10To2to9(8,c1.number));
    ui->numberInBase9->setText(c1.numberSystemConversionFrom10To2to9(9,c1.number));
}

void MainWindow::on_numberInBase2_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(2,arg1);
}
void MainWindow::on_numberInBase3_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(3,arg1);
}
void MainWindow::on_numberInBase4_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(4,arg1);
}
void MainWindow::on_numberInBase5_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(5,arg1);
}
void MainWindow::on_numberInBase6_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(6,arg1);
}
void MainWindow::on_numberInBase7_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(7,arg1);
}
void MainWindow::on_numberInBase8_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(8,arg1);
}
void MainWindow::on_numberInBase9_textEdited(const QString &arg1)
{
    numberInBaseFrom2to9(9,arg1);
}

void MainWindow::on_actionAboutAuthor_triggered()
{
    QMessageBox::about(this,"About the author","Author: Leon Pawlowski\nIndex number: 287089");
}

