#ifndef CALCULATE_H
#define CALCULATE_H


#include <QString>
#include <string>
#include <QRegularExpression>
#include <iostream>
#include <QRegularExpressionMatch>
#include <iomanip>


class calculate
{
public:
    void SetAction(QString a)
    {
        if(a == "+" || a == "-" || a == "*" || a == "/" || "\\+" || "\\*")
        {
            Action = a;
        }
        else
        {
            Action = "+";
        }
    }
    QString GetAction()
    {
        return Action;
    }

private:
    void recMethod(QString& EnterStr, QString ActiveStr);
    void Answer(QString, QString&, QString&, double);
    double VariableAction(double, double, QString&);
    double FuncNumberPrecentOfNumber(double a, double b);
    double Addition(double a, double b);
    double Subtraction(double a, double b);
    double Multiplication(double a, double b);
    double Division(double a, double b);
    QString Action;

public:
    calculate();
    void calc(QString);
};

#endif // CALCULATE_H
