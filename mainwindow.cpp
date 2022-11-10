#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QLineEdit>
#include <QKeyEvent>

void Calculate(QString str);

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

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {

        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        //std::cout << keyEvent->key() << std::endl;
        if(keyEvent->key() == 16777220)//16777220 = Button_Enter
        {
            Calculate(ui->lineEdit->text());
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
    Calculate(ui->lineEdit->text());
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

