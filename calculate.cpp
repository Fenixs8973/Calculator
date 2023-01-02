#include "calculate.h"
#include <cassert>

#define UnitTest

void calc(QString);
void recMethod(QString&, QString);
double VariableAction(double, double);
double FuncNumberPrecentOfNumber(double, double);
double Addition(double, double);
double Subtraction(double, double);
double Multiplication(double, double);
double Division(double, double);

void Answer(QString, QString&, QString&, double);
void SetAnswer (QString);


#ifdef UnitTest
void TestAddition()
{
    assert(Addition(5, 5) == 10);
    assert(Addition(5, 0) == 5);
    assert(Addition(5, -5) == 0);
    assert(Addition(5, -10) == -5);
    std::cout <<  "Addition\t" << "\t" << "OK" << std::endl;
}
void TestSubtraction()
{
    assert(Subtraction(5, 5) == 0);
    assert(Subtraction(5,0) == 5);
    assert(Subtraction(5, -5) == 10);
    assert(Subtraction(5, 10) == -5);
    std::cout << "Subtraction\t" << "\t" << "OK" << std::endl;
}
void TestMultiplication()
{
    assert(Multiplication(5,5) == 25);
    assert(Multiplication(5, 0) == 0);
    assert(Multiplication(5, -5) == -25);
    assert(Multiplication(-5, -5) == 25);
    std::cout << "Multiplication" << "\t" << "OK" << std::endl;
}
void TestDivision()
{
    assert(Division(5, 5) == 1);
    //assert(Division(5, 0) == 0);
    assert(Division(5, -5) == -1);
    assert(Division(-5, -5) == 1);
    std::cout << "Division\t" << "\t" << "OK" << std::endl;
}
#endif //UnitTest

calculate C;

calculate::calculate()
{
#ifdef UnitTest
    TestAddition();
    TestSubtraction();
    TestMultiplication();
    TestDivision();
#endif
}

void calc(QString EnterStr)
{
    static QRegularExpression rg(" |[А-я]");
    static QRegularExpression rg_Com(",");
    EnterStr.remove(rg);//отчистка строки от пробелов и латиницы
    EnterStr.replace(rg_Com, ".");//замена запятых на точки

    recMethod(EnterStr, EnterStr);
}

void recMethod(QString& EnterStr, QString ActiveStr)
{
    QRegularExpression Bracket_Group("\\(((\\d+\\.?\\d*)([\\+?\\-?\\\?\\*?])(\\d+\\.?\\d*))\\)");//скобоки со знакомдействия
    QRegularExpression NumberMODNubmer("(\\d+)mod(\\d+)");//остаток от деления
    QRegularExpression NumberPrecentOfNumber("((\\d+\\.?\\d*)([\\/?\\*?\\+?\\-?])(\\d+\\.?\\d*))%");//число действие процент от чилса
    QRegularExpression PrecentOfNumber("(\\d*\\.?\\d*)%");//процент от числа
    QRegularExpression MultiplicationDivision("((\\d+\\.?\\d*)([/?\\*?])(\\d+\\.?\\d*))");//деление умножение
    QRegularExpression AdditionSubtraction("((\\d+\\.?\\d*)([\\+?\\-?])(\\d+\\.?\\d*))");//сложение вычитанеие

    QRegularExpressionMatch MBracket_Group = Bracket_Group.match(ActiveStr);//наличие скобок в выражении
    QRegularExpressionMatch MNumberMODNubmer = NumberMODNubmer.match(ActiveStr);
    QRegularExpressionMatch MNumberPrecentOfNumber = NumberPrecentOfNumber.match(ActiveStr);//число действие процент от чилса
    QRegularExpressionMatch MPrecentOfNumber = PrecentOfNumber.match(ActiveStr);//процент от числа
    QRegularExpressionMatch MMultiplicationDivision = MultiplicationDivision.match((ActiveStr));//деление умножение
    QRegularExpressionMatch MAdditionSubtraction = AdditionSubtraction.match(ActiveStr);//сложение вычитанеие

    QString PatternSymbolsReplaceRG;//паттерн для регулярного выражения
    QRegularExpression SymbolsReplace;//регулярка, которая использует паттерн PatternSymbolsReplaceRG

    double Result;

    if(MBracket_Group.hasMatch())//проверяем выражение на скобки
    {
        recMethod(EnterStr, MBracket_Group.captured(1));
    }
    else if(MNumberMODNubmer.hasMatch())
    {
        int a = MNumberMODNubmer.captured(1).toInt();
        int b = MNumberMODNubmer.captured(2).toInt();

        Result = a % b;

        PatternSymbolsReplaceRG = MNumberMODNubmer.captured(1) + "mod" + MNumberMODNubmer.captured(2);

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);//замена выражения на ответ
    }
    else if(MNumberPrecentOfNumber.hasMatch())//число действие процент от числа
    {

        C.SetAction(MNumberPrecentOfNumber.captured(3));

        QString a = MNumberPrecentOfNumber.captured(2);//первое число
        QString b = MNumberPrecentOfNumber.captured(4);//второе число

        Result = VariableAction(a.toDouble(), b.toDouble());

        PatternSymbolsReplaceRG = MNumberPrecentOfNumber.captured(2) + C.GetAction() + MNumberPrecentOfNumber.captured(4) + "%";

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);//замена выражения на ответ
    }
    else if(MPrecentOfNumber.hasMatch())
    {
        Result = MPrecentOfNumber.captured(1).toDouble() * 0.01;

        PatternSymbolsReplaceRG = MPrecentOfNumber.captured(1) + "%";

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);
    }
    else if(MMultiplicationDivision.hasMatch())
    {

        C.SetAction(MMultiplicationDivision.captured(3));//указываем действие

        QString a = MMultiplicationDivision.captured(2);//первое число
        QString b = MMultiplicationDivision.captured(4);//второе число

        if(C.GetAction() == "*")
        {
            Result = VariableAction(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MMultiplicationDivision.captured(2) + C.GetAction() + MMultiplicationDivision.captured(4);
        }
        else if(C.GetAction() == "/")
        {
            if(b.toInt() == 0)
                return;

            Result = VariableAction(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MMultiplicationDivision.captured(2) + C.GetAction() + MMultiplicationDivision.captured(4);
        }

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);
        //std::cout << EnterStr.toStdString() << std::endl;

        if(MMultiplicationDivision.hasMatch())
        {
            recMethod(EnterStr, ActiveStr);
        }
    }
    else if(MAdditionSubtraction.hasMatch())//сложение вычитание
    {

        C.SetAction(MAdditionSubtraction.captured(3));//указываем действие

        QString a = MAdditionSubtraction.captured(2);//первое число
        QString b = MAdditionSubtraction.captured(4);//второе число

        if(C.GetAction() == "+")
        {
            Result = VariableAction(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MAdditionSubtraction.captured(2) + C.GetAction() + MAdditionSubtraction.captured(4);
        }
        else if(C.GetAction() == "-")
        {
            Result = VariableAction(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MAdditionSubtraction.captured(2) + C.GetAction() + MAdditionSubtraction.captured(4);
        }

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);//замена выражения на ответ
        //std::cout << EnterStr.toStdString() << std::endl;

        if(MAdditionSubtraction.hasMatch())
        {
            recMethod(EnterStr, ActiveStr);
        }
    }
    else
    {
        SetAnswer("Не верное выражение");
    }
    SetAnswer(EnterStr);
}

void Answer(QString PatternSymbolsReplaceRG, QString& EnterStr, QString& ActiveStr, double Result)//Замена выражения на ответ
{
    QRegularExpression SymbolsReplace;
    SymbolsReplace.setPattern(PatternSymbolsReplaceRG);
    EnterStr.replace(SymbolsReplace, QString::number(Result));
    QRegularExpression re("\\(\\d*.?\\d*\\)");
    EnterStr.replace(re, QString::number(Result));
    ActiveStr = EnterStr;
}

double VariableAction(double a, double b)
{
    if(C.GetAction() == "+")
    {
        return Addition(a, b);
    }
    else if(C.GetAction() == "-")
    {
        return Subtraction(a, b);
    }
    else if(C.GetAction() == "*")
    {
        return Multiplication(a, b);
    }
    else if(C.GetAction() == "/")
    {
        return Division(a, b);
    }
}

double FuncNumberPrecentOfNumber(double a, double b)
{
    double OnePrecent = a*0.01;
    double VariablePrecent = OnePrecent* b;

    return VariableAction(a, VariablePrecent);
}
double Addition(double a, double b)
{
    C.SetAction("\\+");//меняем для паттерна регулярки
    return a+b;
}
double Subtraction(double a, double b)
{
    C.SetAction("-");
    return a-b;
}
double Multiplication(double a, double b)
{
    C.SetAction("\\*");
    return a*b;
}
double Division(double a, double b)
{
    C.SetAction("/");
    return a/b;
}
