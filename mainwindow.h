#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculate.h"

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void SetAnswer(QString);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_0_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_C_clicked();

    void on_Button_equal_clicked();

    void on_Button_O_Parenthesis_clicked();

    void on_Button_CParenthesis_clicked();

    void on_Button_Division_clicked();

    void on_Button_Multiplication_clicked();

    void on_Button_Minus_clicked();

    void on_Button_Plus_clicked();

    void on_Button_omma_clicked();

    void on_Button_Mod_clicked();

    void on_Button_Percent_clicked();

    void on_Button_Exp_clicked();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QString answer;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
