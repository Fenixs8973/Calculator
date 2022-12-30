#ifndef CALCULATE_H
#define CALCULATE_H


#include <QString>
#include <string>
#include <QRegularExpression>
#include <iostream>
#include <QRegularExpressionMatch>


class calculate
{
    //friend double FuncNumberPrecentOfNumber();
private:
    void recMethod(QString& EnterStr, QString ActiveStr);
    void Answer(QString, QString&, QString&, double);
    double VariableAction(double, double, QString&);
    double FuncNumberPrecentOfNumber(double a, double b, QString& Action);
    double Addition(double a, double b, QString& Action);
    double Subtraction(double a, double b, QString& Action);
    double Multiplication(double a, double b, QString& Action);
    double Division(double a, double b, QString& Action);



public:
    calculate();
    void calc(QString);
};

#endif // CALCULATE_H
