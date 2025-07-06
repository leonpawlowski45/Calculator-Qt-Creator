#include "calculator.h"

void calculator::addition() {
    mem = a + b;
}

void calculator::subtraction() {
    mem = a - b;
}

void calculator::division() {
    mem = a / b;
}

void calculator::multiplication() {
    mem = a * b;
}

void calculator::remainderOfDivision() {
    mem = a - (int)(a / b) * b;
}

void calculator::numberSystemConversionFrom2to9To10(int base, QString &number) {
    if (number.contains('.')) {
        QString number1 = "", number2 = "";
        int i = 0;
        while (number[i] != '.') {
            number1 += number[i];
            ++i;
        }
        ++i;
        while (i < number.length()) {
            number2 += number[i];
            ++i;
        }

        bool ok;
        long long numberInt = number1.toLongLong(&ok);
        long long counter = 1, result = 0;
        while (numberInt > 0) {
            result += counter * (numberInt % 10);
            counter *= base;
            numberInt /= 10;
        }
        number = QString::number(result);

        numberInt = number2.toLongLong(&ok);
        counter = 1;
        result = 0;
        while (numberInt > 0) {
            result += counter * (numberInt % 10);
            counter *= base;
            numberInt /= 10;
        }
        number = number + '.' + QString::number(result);
    } else {
        bool ok;
        long long numberInt = number.toLongLong(&ok);
        long long counter = 1, result = 0;
        while (numberInt > 0) {
            result += counter * (numberInt % 10);
            counter *= base;
            numberInt /= 10;
        }
        number = QString::number(result);
    }
}

QString calculator::numberSystemConversionFrom10To2to9(int base, QString number) {
    if (number.contains('.')) {
        QString number1 = "", number2 = "";
        int i = 0;
        while (number[i] != '.') {
            number1 += number[i];
            ++i;
        }
        ++i;
        while (i < number.length()) {
            number2 += number[i];
            ++i;
        }

        bool ok;
        long long numberInt = number1.toLongLong(&ok);
        QString result = "";
        while (numberInt > 0) {
            result = QString::number(numberInt % base) + result;
            numberInt /= base;
        }

        numberInt = number2.toLongLong(&ok);
        number = result + '.';
        result = "";
        while (numberInt > 0) {
            result = QString::number(numberInt % base) + result;
            numberInt /= base;
        }
        return number + result;
    } else {
        bool ok;
        long long numberInt = number.toLongLong(&ok);
        number = "";
        while (numberInt > 0) {
            number = QString::number(numberInt % base) + number;
            numberInt /= base;
        }
        return number;
    }
}
