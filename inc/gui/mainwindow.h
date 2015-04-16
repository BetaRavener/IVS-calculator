#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString example;
private slots:

    void on_Button0_clicked();
    void on_Button1_clicked();
    void on_Button2_clicked();
    void on_Button3_clicked();
    void on_Button4_clicked();
    void on_Button5_clicked();
    void on_Button6_clicked();
    void on_Button7_clicked();
    void on_Button8_clicked();
    void on_Button9_clicked();
    void on_ButtonDest_clicked();


    void on_ButtonBracketL_clicked();
    void on_ButtonBracketR_clicked();


    void on_ButtonAdd_clicked();
    void on_ButtonSub_clicked();

    void on_ButtonPower_clicked();
    void on_ButtonRoot_clicked();

    void on_ButtonDiv_clicked();
    void on_ButtonMul_clicked();

    void on_ButtonLog_clicked();

    void on_ButtonResult_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
