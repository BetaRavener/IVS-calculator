#include "inc/gui/mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/core/evaluator.h"

#include <sstream>

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

void MainWindow::on_pushButton_clicked()
{
    Evaluator evaluator;
    double result = evaluator.evaluate(ui->input->text().toStdString());

    std::ostringstream oss;
    oss << result;
    ui->result->setText(QString::fromStdString(oss.str()));
}
