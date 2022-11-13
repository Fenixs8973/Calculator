#include "calculate.h"


void calc(QString);
void recMethod(QString&, QString);
double Addition(double, double);
double Subtraction(double, double);
double Multiplication(double, double);
double Division(double, double);


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
    QRegularExpression INBracket_Group("((\\d\\.?\\d*)([\\+?\\-?])(\\d\\.?\\d*))");//выражение со знаком действия
    QRegularExpression MultiplicationAndDivision("((\\d\\.?\\d*)([/?\\*?])(\\d\\.?\\d*))");

    QRegularExpressionMatch MMultiplicationAndDivision = MultiplicationAndDivision.match((ActiveStr));//умножение и деление
    QRegularExpressionMatch MBracket_Group = Bracket_Group.match(ActiveStr);//наличие скобок в выражении
    QRegularExpressionMatch MINBracket_Group = INBracket_Group.match(ActiveStr);//выражение в скобках

    double Result;

    if(MBracket_Group.hasMatch())//проверяем выражение на скобки
    {
        recMethod(EnterStr, MBracket_Group.captured(1));
    }
    else if(MMultiplicationAndDivision.hasMatch())
    {
        QString Action = MMultiplicationAndDivision.captured(3);//указываем действие
        QString PatternSymbolsReplaceRG;
        QRegularExpression SymbolsReplace;

        QString a = MMultiplicationAndDivision.captured(2);
        QString b = MMultiplicationAndDivision.captured(4);



        if(Action == "*")
        {
            Result = Multiplication(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MMultiplicationAndDivision.captured(2) + "\\*" + MMultiplicationAndDivision.captured(4);

            std::cout << EnterStr.toStdString() << std::endl;
        }
        else if(Action == "/")
        {
            Result = Division(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MMultiplicationAndDivision.captured(2) + "/" + MMultiplicationAndDivision.captured(4);

            std::cout << EnterStr.toStdString() << std::endl;
        }

        SymbolsReplace.setPattern(PatternSymbolsReplaceRG);
        EnterStr.replace(SymbolsReplace, QString::number(Result));
        QRegularExpression re("\\(\\d*\\)");
        EnterStr.replace(re, QString::number(Result));
        ActiveStr = EnterStr;

        if(MMultiplicationAndDivision.hasMatch())
        {
            recMethod(EnterStr, ActiveStr);
        }
    }
    else if(MINBracket_Group.hasMatch())//выделяем выражение без скобок
    {
        QString Action = MINBracket_Group.captured(3);//указываем действие
        QString PatternSymbolsReplaceRG;
        QRegularExpression SymbolsReplace;

        QString a = MINBracket_Group.captured(2);
        QString b = MINBracket_Group.captured(4);

        if(Action == "+")
        {
            Result = Addition(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MINBracket_Group.captured(2) + "\\+" + MINBracket_Group.captured(4);

            std::cout << EnterStr.toStdString() << std::endl;
        }
        else if(Action == "-")
        {
            Result = Subtraction(a.toDouble(), b.toDouble());

            PatternSymbolsReplaceRG = MINBracket_Group.captured(2) + "-" + MINBracket_Group.captured(4);

            std::cout << EnterStr.toStdString() << std::endl;
        }

        SymbolsReplace.setPattern(PatternSymbolsReplaceRG);
        EnterStr.replace(SymbolsReplace, QString::number(Result));
        QRegularExpression re("\\(\\d*\\)");
        EnterStr.replace(re, QString::number(Result));
        ActiveStr = EnterStr;
        std::cout << EnterStr.toStdString() << std::endl;

        if(MINBracket_Group.hasMatch())
        {
            recMethod(EnterStr, ActiveStr);
        }
    }

}

double Addition(double a, double b)
{
    return a+b;
}
double Subtraction(double a, double b)
{
    return a-b;
}
double Multiplication(double a, double b)
{
    return a*b;
}
double Division(double a, double b)
{
    return a/b;
}
