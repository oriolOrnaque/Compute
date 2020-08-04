#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Compute");

    this->pgen = new ProblemGenerator();

    this->p = this->pgen->nextProblem();

    this->updateDisplay();
    this->updateButtons();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete this->p;
    delete this->pgen;
}

void MainWindow::updateDisplay(void)
{
    ui->label->setText(QString::number(this->p->getCurrentMovs()));
    ui->label_4->setText(QString::number(this->p->getGoal()));
    if(this->p->isSolved())
        ui->label_5->setText("SOLVED");
    else
        ui->label_5->setText(QString::number(this->p->getCurrentValue()));
}

void MainWindow::updateButtons(void)
{
    setButton(ui->pushButton, 0);
    setButton(ui->pushButton_2, 1);
    setButton(ui->pushButton_3, 2);
    setButton(ui->pushButton_4, 3);
    setButton(ui->pushButton_5, 4);
    setButton(ui->pushButton_6, 5);
    setButton(ui->pushButton_7, 6);
    setButton(ui->pushButton_8, 7);
    setButton(ui->pushButton_9, 8);
}

void MainWindow::setButton(QPushButton* button, size_t idx)
{
    const Operation* op = this->p->getOperation(idx);
    if(op == nullptr)
    {
        button->setDisabled(true);
        button->setText("  ");
    }
    else
    {
        button->setDisabled(false);
        button->setText(op->toQString());
    }
}

void MainWindow::triggerOperation(size_t op_idx)
{
    this->p->input(this->p->getOperation(op_idx));
    this->updateDisplay();
}


void MainWindow::on_pushButton_released()
{
    triggerOperation(0);
}

void MainWindow::on_pushButton_4_released()
{
    triggerOperation(3);
}

void MainWindow::on_pushButton_2_released()
{
    triggerOperation(1);
}

void MainWindow::on_pushButton_3_released()
{
    triggerOperation(2);
}

void MainWindow::on_pushButton_5_released()
{
    triggerOperation(4);
}

void MainWindow::on_pushButton_6_released()
{
    triggerOperation(5);
}

void MainWindow::on_pushButton_7_released()
{
    triggerOperation(6);
}

void MainWindow::on_pushButton_8_released()
{
    triggerOperation(7);
}

void MainWindow::on_pushButton_9_released()
{
    triggerOperation(8);
}

void MainWindow::on_pushButton_10_released()
{
    delete this->p;

    this->p = this->pgen->nextProblem();
    this->updateDisplay();
    this->updateButtons();
}

void MainWindow::on_pushButton_11_released()
{
    this->p->reset();
    this->updateDisplay();
}
