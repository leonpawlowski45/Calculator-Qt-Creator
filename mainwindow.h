#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_digit_0_clicked();
    void on_digit_1_clicked();
    void on_digit_2_clicked();
    void on_digit_3_clicked();
    void on_digit_4_clicked();
    void on_digit_5_clicked();
    void on_digit_6_clicked();
    void on_digit_7_clicked();
    void on_digit_8_clicked();
    void on_digit_9_clicked();
    void on_dot_clicked();
    void on_backSpace_clicked();
    void on_clearDisplay_clicked();
    void on_memoryToEquation_clicked();
    void on_memoryToConversion_clicked();
    void on_clearMemory_clicked();
    void on_addToMemory_clicked();

    void handleLogic(QString operation);
    void on_mathOperationClicked(QString text);

    void on_addition_clicked();
    void on_subtraction_clicked();
    void on_division_clicked();
    void on_multiplication_clicked();
    void on_modulo_clicked();
    void on_equals_clicked();
    void on_negativeNumber_clicked();

    void numberInBaseFrom2to9(int base, const QString &arg1);
    void on_numberInBase10_textEdited(const QString &arg1);
    void on_numberInBase2_textEdited(const QString &arg1);
    void on_numberInBase3_textEdited(const QString &arg1);
    void on_numberInBase4_textEdited(const QString &arg1);
    void on_numberInBase5_textEdited(const QString &arg1);
    void on_numberInBase6_textEdited(const QString &arg1);
    void on_numberInBase7_textEdited(const QString &arg1);
    void on_numberInBase8_textEdited(const QString &arg1);
    void on_numberInBase9_textEdited(const QString &arg1);

    void on_actionAboutAuthor_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
