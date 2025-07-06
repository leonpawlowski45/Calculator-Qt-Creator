#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class calculator;
}
QT_END_NAMESPACE

class calculator
{
public:
    double mem;
    double a, b;
    QString number;
    QString currentOperation = "";
    void addition();
    void subtraction();
    void division();
    void multiplication();
    void remainderOfDivision();
    void numberSystemConversionFrom2to9To10(int base, QString &number);
    QString numberSystemConversionFrom10To2to9(int base, QString number);
};

#endif // CALCULATOR_H
