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
            ui->PheromoneVolatilizationEdit->text().toDouble());
    double da=ui->PheromoneVolatilizationEdit->text().toDouble();
    qDebug()<<"da?"<<da;
    aco.start();
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle(QString("蚁群算法解决旅行商问题\n 信息素重要程度因子:%1 启发函数重要程度因子:%2 信息素挥发速度:%3")
                    .arg(ui->PheromoneImportantValueEdit->text().toInt())
                    .arg(ui->HeFuntionImportValueEdit->text().toInt())
                    .arg(ui->PheromoneVolatilizationEdit->text().toDouble()));
    QValueAxis *aX=new QValueAxis;
    QValueAxis *aY=new QValueAxis;
    aX->setTitleText("次数");
    aX->setLabelFormat("%d");
    aX->setTitleVisible(true);
    aY->setTitleVisible(true);
    aY->setLabelFormat("%d");
    aY->setTitleText("路径长度");
    chart->addAxis(aX,Qt::AlignBottom);
    chart->addAxis(aY,Qt::AlignLeft);
    QLineSeries* series=aco.getSeries();
    chart->addSeries(series);
    series->attachAxis(aX);//需要先addSeries
    series->attachAxis(aY);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow *chartV=new QMainWindow;
    chartV->setCentralWidget(chartView);
    chartV->resize(800, 500);
    chartV->show();
}

