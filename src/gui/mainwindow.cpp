#include "inc/gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QShortcut>

#include <fstream>

#include "inc/core/evaluator.h"
#include "inc/core/myexception.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new QShortcut(QKeySequence(Qt::Key_0), this, SLOT(on_Button0_clicked()));
    new QShortcut(QKeySequence(Qt::Key_1), this, SLOT(on_Button1_clicked()));
    new QShortcut(QKeySequence(Qt::Key_2), this, SLOT(on_Button2_clicked()));
    new QShortcut(QKeySequence(Qt::Key_3), this, SLOT(on_Button3_clicked()));
    new QShortcut(QKeySequence(Qt::Key_4), this, SLOT(on_Button4_clicked()));
    new QShortcut(QKeySequence(Qt::Key_5), this, SLOT(on_Button5_clicked()));
    new QShortcut(QKeySequence(Qt::Key_6), this, SLOT(on_Button6_clicked()));
    new QShortcut(QKeySequence(Qt::Key_7), this, SLOT(on_Button7_clicked()));
    new QShortcut(QKeySequence(Qt::Key_8), this, SLOT(on_Button8_clicked()));
    new QShortcut(QKeySequence(Qt::Key_9), this, SLOT(on_Button9_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Period), this, SLOT(on_ButtonDest_clicked()));
    new QShortcut(QKeySequence(Qt::Key_ParenLeft), this, SLOT(on_ButtonBracketL_clicked()));
    new QShortcut(QKeySequence(Qt::Key_ParenRight), this, SLOT(on_ButtonBracketR_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Plus), this, SLOT(on_ButtonAdd_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Minus), this, SLOT(on_ButtonSub_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Asterisk), this, SLOT(on_ButtonMul_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Slash), this, SLOT(on_ButtonDiv_clicked()));
    new QShortcut(QKeySequence(Qt::Key_P), this, SLOT(on_ButtonPower_clicked()));
    new QShortcut(QKeySequence(Qt::Key_AsciiCircum), this, SLOT(on_ButtonPower_clicked()));
    new QShortcut(QKeySequence(Qt::Key_F), this, SLOT(on_ButtonFak_clicked()));
    new QShortcut(QKeySequence(Qt::Key_S), this, SLOT(on_ButtonRoot_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Backspace), this, SLOT(on_ButtonClear_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Enter), this, SLOT(on_ButtonResult_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Return), this, SLOT(on_ButtonResult_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button0_clicked()
{
    QString input = getInput();
    input.append('0');
    setInput(input);
}

void MainWindow::on_Button1_clicked()
{
    QString input = getInput();
    input.append('1');
    setInput(input);
}

void MainWindow::on_Button2_clicked()
{
    QString input = getInput();
    input.append('2');
    setInput(input);
}
void MainWindow::on_Button3_clicked()
{
    QString input = getInput();
    input.append('3');
    setInput(input);
}

void MainWindow::on_Button4_clicked()
{
    QString input = getInput();
    input.append('4');
    setInput(input);
}

void MainWindow::on_Button5_clicked()
{
    QString input = getInput();
    input.append('5');
    setInput(input);
}
void MainWindow::on_Button6_clicked()
{
    QString input = getInput();
    input.append('6');
    setInput(input);
}

void MainWindow::on_Button7_clicked()
{
    QString input = getInput();
    input.append('7');
    setInput(input);
}

void MainWindow::on_Button8_clicked()
{
    QString input = getInput();
    input.append('8');
    setInput(input);
}
void MainWindow::on_Button9_clicked()
{
    QString input = getInput();
    input.append('9');
    setInput(input);
}

void MainWindow::on_ButtonDest_clicked()
{
    QString input = getInput();
    input.append('.');
    setInput(input);
}

void MainWindow::on_ButtonAdd_clicked()
{
    QString input = getInput();
    input.append('+');
    setInput(input);
}

void MainWindow::on_ButtonSub_clicked()
{
    QString input = getInput();
    input.append('-');
    setInput(input);
}

void MainWindow::on_ButtonDiv_clicked()
{
    QString input = getInput();
    input.append('/');
    setInput(input);
}

void MainWindow::on_ButtonMul_clicked()
{
    QString input = getInput();
    input.append('*');
    setInput(input);
}

void MainWindow::on_ButtonBracketL_clicked()
{
    QString input = getInput();
    input.append('(');
    setInput(input);
}

void MainWindow::on_ButtonBracketR_clicked()
{
    QString input = getInput();
    input.append(')');
    setInput(input);
}

void MainWindow::on_ButtonPower_clicked()
{
    QString input = getInput();
    input.append('^');
    setInput(input);
}

void MainWindow::on_ButtonRoot_clicked()
{
    QString input = getInput();
    input.prepend("sqrt(");
    input.append(')');
    setInput(input);
}

void MainWindow::on_ButtonFak_clicked()
{
    QString input = getInput();
    input.prepend("fact(");
    input.append(')');
    setInput(input);
}

void MainWindow::on_ButtonResult_clicked()
{
    Evaluator eval;
    QString input = getInput();
    try
    {
        double x = eval.evaluate(input.toStdString());
        setResult(QString::number(x));
    }
    catch (MathException e)
    {
        setResult("Math error");
    }
    catch (LexicalException e)
    {
        setResult("Invalid input");
    }
    catch (SyntaxException e)
    {
        setResult("Invalid input");
    }
}

QString MainWindow::getInput()
{
    return ui->Input->text();
}

void MainWindow::setInput(QString input)
{
    ui->Input->setText(input);
}

void MainWindow::setResult(QString result)
{
    ui->Result->setText(result);
}

void MainWindow::on_ButtonClear_clicked()
{
    ui->Input->setText("");
    ui->Result->setText("");
}
