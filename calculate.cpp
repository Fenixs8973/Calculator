#include "calculate.h"

void calc(QString);
void recMethod(QString&, QString);
double Addition(double, double, QString& Action);
double Subtraction(double, double, QString& Action);
double Multiplication(double, double, QString& Action);
double Division(double, double, QString& Action);

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
    QRegularExpression INBracket_Group("((\\d\\.?\\d*)([\\+?\\-?])(\\d\\.?\\d*))");//выражение со знаком действия
    QRegularExpression MultiplicationAndDivision("((\\d\\.?\\d*)([/?\\*?])(\\d\\.?\\d*))");

    QRegularExpressionMatch MMultiplicationAndDivision = MultiplicationAndDivision.match((ActiveStr));//умножение и деление
    QRegularExpressionMatch MBracket_Group = Bracket_Group.match(ActiveStr);//наличие скобок в выражении
    QRegularExpressionMatch MINBracket_Group = INBracket_Group.match(ActiveStr);//выражение в скобках

    QString PatternSymbolsReplaceRG;//паттерн для регулярного выражения
    QRegularExpression SymbolsReplace;//регулярка, которая использует паттерн PatternSymbolsReplaceRG

    double Result;

    if(MBracket_Group.hasMatch())//проверяем выражение на скобки
    {
        recMethod(EnterStr, MBracket_Group.captured(1));
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
    else if(MINBracket_Group.hasMatch())//выделяем выражение без скобок
    {
        QString Action = MINBracket_Group.captured(3);//указываем действие

        QString a = MINBracket_Group.captured(2);//первое число
        QString b = MINBracket_Group.captured(4);//второе число

        if(Action == "+")
        {
            Result = Addition(a.toDouble(), b.toDouble(), Action);

            PatternSymbolsReplaceRG = MINBracket_Group.captured(2) + Action + MINBracket_Group.captured(4);
        }
        else if(Action == "-")
        {
            Result = Subtraction(a.toDouble(), b.toDouble(), Action);

            PatternSymbolsReplaceRG = MINBracket_Group.captured(2) + Action + MINBracket_Group.captured(4);
        }

        Answer(PatternSymbolsReplaceRG, EnterStr, ActiveStr, Result);//замена выражения на ответ
        //std::cout << EnterStr.toStdString() << std::endl;

        if(MINBracket_Group.hasMatch())
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

double Addition(double a, double b, QString& Action)
{
    Action = "\\+";
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
