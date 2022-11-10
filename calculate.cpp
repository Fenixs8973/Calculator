#include <QString>
#include <QRegularExpression>
#include <iostream>

void Sorting(QString &Str);

void Calculate(QString str)
{
    QString &Str = str;
    QString *PStr = &Str;
    QRegularExpression rg(" |[А-я]");
    QRegularExpression rgCom(",");
    Str.remove(rg);//отчистка строки от пробелов и латиницы
    Str.replace(rgCom, ".");//замена запятых на точки
    std::cout << str.toStdString() << std::endl;
    Sorting(Str);
    //prioritization(*Str);


}
void Sorting(QString &Str)
{

    std::cout << Str.toStdString() << std::endl;
    int FirstPos = 0;
    int SeondPos = 0;
    QRegularExpression regex_numbers("\\d");
    QRegularExpression regex_sign("+-\\*\\");
    for(int i = 0; i < Str.length(); i++)
    {
        QRegularExpressionMatch match = regex_numbers.match(Str[i]);
       if(match.hasMatch())
       {
           SeondPos++;
           std::cout << "SecondPos: " << SeondPos << std::endl;
       }
       else
       {

       }

    }


}

void Prioritization(QString &Str)
{
    //vector <string> expression;

}
