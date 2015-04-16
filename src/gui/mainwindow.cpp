#include "inc/gui/mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include <fstream>

#include "inc/core/evaluator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button0_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button0->text());
}

void MainWindow::on_Button1_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button1->text());
}

void MainWindow::on_Button2_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button2->text());
}
void MainWindow::on_Button3_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button3->text());
}

void MainWindow::on_Button4_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button4->text());
}

void MainWindow::on_Button5_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button5->text());
}
void MainWindow::on_Button6_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button6->text());
}

void MainWindow::on_Button7_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button7->text());
}

void MainWindow::on_Button8_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button8->text());
}
void MainWindow::on_Button9_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->Button9->text());
}

void MainWindow::on_ButtonDest_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonDest->text());
}

void MainWindow::on_ButtonAdd_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonAdd->text());
}

void MainWindow::on_ButtonSub_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonSub->text());
}

void MainWindow::on_ButtonDiv_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonDiv->text());
}

void MainWindow::on_ButtonMul_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonMul->text());
}

void MainWindow::on_ButtonBracketL_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonBracketL->text());
}

void MainWindow::on_ButtonBracketR_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonBracketR->text());
}

void MainWindow::on_ButtonPower_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonPower->text());
}

void MainWindow::on_ButtonRoot_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonRoot->text());
}

void MainWindow::on_ButtonLog_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonLog->text());
}

void MainWindow::on_ButtonResult_clicked()
{
    ui->Example->setText(ui->Example->toPlainText()+ui->ButtonResult->text()+"\n");
    this->example=ui->Example->toPlainText();
}


void MainWindow::on_pushButton_clicked()
{
    std::ifstream fin("test.txt");
    std::ofstream fout("test-out.txt");
    std::string input;

    Evaluator eval;

    if (fin.is_open())
    {
        while (std::getline(fin, input))
        {
            try
            {
                fout << eval.evaluate(input) << std::endl;
            }
            catch (std::runtime_error e)
            {
                ui->Example->setText(e.what());
            }
        }
    }
}
