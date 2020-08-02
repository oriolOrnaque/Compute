#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

#include "problemgenerator.h"
#include "problem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateDisplay(void);
    void updateButtons(void);

protected:
    void setButton(QPushButton* button, size_t idx);
    void triggerOperation(size_t op_idx);

private slots:
    void on_pushButton_released();

    void on_pushButton_4_released();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_5_released();

    void on_pushButton_6_released();

    void on_pushButton_7_released();

    void on_pushButton_8_released();

    void on_pushButton_9_released();

    void on_pushButton_10_released();

    void on_pushButton_11_released();

private:
    Ui::MainWindow *ui;

    ProblemGenerator* pgen;
    Problem* p;
};
#endif // MAINWINDOW_H
