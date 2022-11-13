#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QLineEdit>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setFocus();
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void calc(QString EnterStr);

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //std::cout << keyEvent->key() << std::endl;
        if(keyEvent->key() == 16777220)//16777220 = Button_Enter
        {
            QString qwe = ui->lineEdit->text();
            calc(qwe);
        }
    }
    QObject::eventFilter(watched, event);
}





void MainWindow::on_Button_0_clicked()
{
    QString *num = new QString;
    *num = "0";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_1_clicked()
{
    QString *num = new QString;
    *num = "1";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_2_clicked()
{
    QString *num = new QString;
    *num = "2";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_3_clicked()
{
    QString *num = new QString;
    *num = "3";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_4_clicked()
{
    QString *num = new QString;
    *num = "4";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_5_clicked()
{
    QString *num = new QString;
    *num = "5";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_6_clicked()
{
    QString *num = new QString;
    *num = "6";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_7_clicked()
{
    QString *num = new QString;
    *num = "7";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_8_clicked()
{
    QString *num = new QString;
    *num = "8";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_9_clicked()
{
    QString *num = new QString;
    *num = "9";
    ui->lineEdit->insert(*num);
}

void MainWindow::on_Button_C_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_Button_equal_clicked()
{
    QString qwe = ui->lineEdit->text();
    calc(qwe);
}


void MainWindow::on_Button_O_Parenthesis_clicked()
{
    QString *num = new QString;
    *num = "(";
    ui->lineEdit->insert(*num);
}


void MainWindow::on_Button_CParenthesis_clicked()
{
    QString *num = new QString;
    *num = ")";
    ui->lineEdit->insert(*num);
}


void MainWindow::on_Button_Division_clicked()
{
    QString *num = new QString;
    *num = "/";
    ui->lineEdit->insert(*num);
}


void MainWindow::on_Button_Multiplication_clicked()
{
    QString *num = new QString;
    *num = "*";
    ui->lineEdit->insert(*num);
}


void MainWindow::on_Button_Minus_clicked()
{
    QString *num = new QString;
    *num = "-";
    ui->lineEdit->insert(*num);
}


void MainWindow::on_Button_Plus_clicked()
{
    QString *num = new QString;
    *num = "=";
    ui->lineEdit->insert(*num);
}


void MainWindow::on_Button_omma_clicked()
{
    QString *num = new QString;
    *num = ",";
    ui->lineEdit->insert(*num);
}

/*
#include <QString>
#include <QRegularExpression>
#include <iostream>

void Sorting(QString *PStr);

void Calculate(QString str)
{
    static QRegularExpression Bracket_Group("\\(((\\d\\.?\\d*)([\\+?\\-?\\\?\\*?])(\\d\\.?\\d*))\\)");//скобоки со знакомдействия
    static QRegularExpression INBracket_Group("((\\d\\.?\\d*)([\\+?\\-?\\\?\\*?])(\\d\\.?\\d*))");//выражение со знаком действия
    static QRegularExpression Addition("((\\d\\.?\\d*)(\\+)(\\d\\.?\\d*))");//сложеине
    static QRegularExpression Subtraction("((\\d\\.?\\d*)(\\-)(\\d\\.?\\d*))");//вычитание
    static QRegularExpression Multiplication("((\\d\\.?\\d*)(\\*)(\\d\\.?\\d*))");//умножение
    static QRegularExpression Division("((\\d\\.?\\d*)(\\)(\\d\\.?\\d*))");//деление

    QString &Str = str;
    QString *PStr = &Str;
    static QRegularExpression rg(" |[А-я]");
    static QRegularExpression rg_Com(",");
    Str.remove(rg);//отчистка строки от пробелов и латиницы
    Str.replace(rg_Com, ".");//замена запятых на точки
    //std::cout << str.toStdString() << std::endl;
    Sorting(PStr);
    //std::cout << str.toStdString() << std::endl;
    //prioritization(*Str);


}




//    QRegularExpressionMatch MAddition = Addition.match(Str);
//    QString qwe = MAddition.captured(3);
//    std::cout << qwe.toStdString() << std::endl;

void Prioritization(QString &Str)
{
    //vector <string> expression;

}
*/
