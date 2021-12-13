#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->HeFuntionImportValueEdit->setText("2");
    ui->PheromoneImportantValueEdit->setText("1");
    ui->PheromoneVolatilizationEdit->setText("0.2");
    ui->cycleTimeEdit->setText("100");
    ui->antSizeEdit->setText("20");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ResultBtn_clicked()
{
    ACO aco(ui->antSizeEdit->text().toInt(),
            ui->cycleTimeEdit->text().toInt(),
            ui->PheromoneImportantValueEdit->text().toInt(),
            ui->HeFuntionImportValueEdit->text().toInt(),
            ui->PheromoneVolatilization->text().toDouble());
    aco.start();
}

