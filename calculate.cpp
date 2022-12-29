#include "calculate.h"

void calc(QString);
void recMethod(QString&, QString);
double VariableAction(double, double, QString&);
double FuncNumberPrecentOfNumber(double, double, QString&);
double Addition(double, double, QString&);
double Subtraction(double, double, QString&);
double Multiplication(double, double, QString&);
double Division(double, double, QString&);

void Answer(QString, QString&, QString&, double);
void SetAnswer (QString);

calculate::calculate()
{

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
    QRegularExpression Bracket_Group("\\(((\\d\\.?\\d*)([\\+?\\-?\\\?\\*?])(\\d\\.?\\d*))\\)");//скобоки со знакомдействия
    QRegularExpression NumberPrecentOfNumber("((\\d*\\.?\\d*)([\\/?\\*?\\+?\\-?])(\\d*\\.?\\d*))%");//число действие процент от чилса
    QRegularExpression PrecentOfNumber("(\\d*\\.?\\d*)%");//процент от числа
    QRegularExpression MultiplicationAndDivision("((\\d\\.?\\d*)([/?\\*?])(\\d\\.?\\d*))");//деление умножение
    QRegularExpression AdditionSubtraction("((\\d\\.?\\d*)([\\+?\\-?])(\\d\\.?\\d*))");//сложение вычитанеие

    QRegularExpressionMatch MBracket_Group = Bracket_Group.match(ActiveStr);//наличие скобок в выражении
    QRegularExpressionMatch MNumberPrecentOfNumber = NumberPrecentOfNumber.match(ActiveStr);//число действие процент от чилса
    QRegularExpressionMatch MPrecentOfNumber = PrecentOfNumber.match(ActiveStr);//процент от числа
    QRegularExpressionMatch MMultiplicationAndDivision = MultiplicationAndDivision.match((ActiveStr));//деление умножение
    QRegularExpressionMatch MAdditionSubtraction = AdditionSubtraction.match(ActiveStr);//сложение вычитанеие

    QString PatternSymbolsReplaceRG;//паттерн для регулярного выражения
    QRegularExpression SymbolsReplace;//регулярка, которая использует паттерн PatternSymbolsReplaceRG

    double Result;

    if(MBracket_Group.hasMatch())//проверяем выражение на скобки
    {
        recMethod(EnterStr, MBracket_Group.captured(1));
    }
    else if(MNumberPrecentOfNumber.hasMatch())//число действие процент от числа
    {
        QString Action = MNumberPrecentOfNumber.captured(3);

        QString a = MNumberPrecentOfNumber.captured(2);//первое число
        QString b = MNumberPrecentOfNumber.captured(4);//второе число

        Result = FuncNumberPrecentOfNumber(a.toDouble(), b.toDouble(), Action);

        PatternSymbolsReplaceRG = MNumberPrecentOfNumber.captured(2) + Action + MNumberPrecentOfNumber.captured(4) + "%";

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);//замена выражения на ответ
    }
    else if(MPrecentOfNumber.hasMatch())
    {
        Result = MPrecentOfNumber.captured(1).toDouble() * 0.01;

        PatternSymbolsReplaceRG = MPrecentOfNumber.captured(1) + "%";

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);
    }
    else if(MMultiplicationAndDivision.hasMatch())
    {
        QString Action = MMultiplicationAndDivision.captured(3);//указываем действие

        QString a = MMultiplicationAndDivision.captured(2);//первое число
        QString b = MMultiplicationAndDivision.captured(4);//второе число

        if(Action == "*")
        {
            Result = Multiplication(a.toDouble(), b.toDouble(), Action);

            PatternSymbolsReplaceRG = MMultiplicationAndDivision.captured(2) + Action + MMultiplicationAndDivision.captured(4);
        }
        else if(Action == "/")
        {
            if(b.toInt() == 0)
                return;

            Result = Division(a.toDouble(), b.toDouble(), Action);

            PatternSymbolsReplaceRG = MMultiplicationAndDivision.captured(2) + Action + MMultiplicationAndDivision.captured(4);
        }

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);
        //std::cout << EnterStr.toStdString() << std::endl;

        if(MMultiplicationAndDivision.hasMatch())
        {
            recMethod(EnterStr, ActiveStr);
        }
    }
    else if(MAdditionSubtraction.hasMatch())//сложение вычитание
    {
        QString Action = MAdditionSubtraction.captured(3);//указываем действие

        QString a = MAdditionSubtraction.captured(2);//первое число
        QString b = MAdditionSubtraction.captured(4);//второе число

        if(Action == "+")
        {
            Result = Addition(a.toDouble(), b.toDouble(), Action);

            PatternSymbolsReplaceRG = MAdditionSubtraction.captured(2) + Action + MAdditionSubtraction.captured(4);
        }
        else if(Action == "-")
        {
            Result = Subtraction(a.toDouble(), b.toDouble(), Action);

            PatternSymbolsReplaceRG = MAdditionSubtraction.captured(2) + Action + MAdditionSubtraction.captured(4);
        }

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);//замена выражения на ответ
        //std::cout << EnterStr.toStdString() << std::endl;

        if(MAdditionSubtraction.hasMatch())
        {
            recMethod(EnterStr, ActiveStr);
        }
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

double VariableAction(double a, double b, QString& Action)
{
    if(Action == "+")
    {
        return Addition(a, b, Action);
    }
    else if(Action == "-")
    {
        return Subtraction(a, b, Action);
    }
    else if(Action == "*")
    {
        return Multiplication(a, b, Action);
    }
    else if(Action == "/")
    {
        return Division(a, b, Action);
    }
}

double FuncNumberPrecentOfNumber(double a, double b, QString& Action)
{
    double OnePrecent = a*0.01;
    double VariablePrecent = OnePrecent* b;

    return VariableAction(a, VariablePrecent, Action);
}
double Addition(double a, double b, QString& Action)
{
    Action = "\\+";//меняем для паттерна регулярки
    return a+b;
}
double Subtraction(double a, double b, QString& Action)
{
    Action = "-";
    return a-b;
}
double Multiplication(double a, double b, QString& Action)
{
    Action = "\\*";
    return a*b;
}
double Division(double a, double b, QString& Action)
{
    Action = "/";
    return a/b;
}
