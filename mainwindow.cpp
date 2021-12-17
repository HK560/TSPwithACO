#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qRegisterMetaType<QVector<int>>("QVector<int>");
    ui->setupUi(this);
    ui->HeFuntionImportValueEdit->setText("2");
    ui->PheromoneImportantValueEdit->setText("1");
    ui->PheromoneVolatilizationEdit->setText("0.2");
    ui->cycleTimeEdit->setText("100");
    ui->antSizeEdit->setText("5");
    acoThread=new AcoThread(this);
    connect(acoThread,SIGNAL(sendSeries(QLineSeries*)),this,SLOT(showResult(QLineSeries*)));
    connect(acoThread,SIGNAL(minPath(QVector<int>)),this,SLOT(recvMinPath(QVector<int>)));
    connect(acoThread,SIGNAL(minPathLength(double)),this,SLOT(recvMinPathLength(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showResult(QLineSeries* series)
{
    int needtime=qtime.elapsed();
    ui->timeLabel->setText(QString("花费时间：%1ms").arg(needtime));
    Q_ASSERT(series!=nullptr);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->setTitle(QString("蚁群算法解决旅行商问题\n 信息素重要程度因子:%1 启发函数重要程度因子:%2 信息素挥发速度:%3")
                    .arg(ui->PheromoneImportantValueEdit->text(),
                         ui->HeFuntionImportValueEdit->text(),
                         ui->PheromoneVolatilizationEdit->text()));

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
    chart->addSeries(series);
    series->attachAxis(aX);//需要先addSeries
    series->attachAxis(aY);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow *chartV=new QMainWindow;
    chartV->setCentralWidget(chartView);
    chartV->resize(800, 500);
    chartV->show();
    delete progressDialog;
    acoThread->terminate();
}


void MainWindow::on_ResultBtn_clicked()
{
    if(ui->antSizeEdit->text().toInt()<=0
            ||ui->cycleTimeEdit->text().toInt()<=0
            ||ui->PheromoneImportantValueEdit->text().toInt()<=0
            ||ui->HeFuntionImportValueEdit->text().toInt()<=0
            ||ui->PheromoneVolatilizationEdit->text().toDouble()<=0
            ){
        QMessageBox::warning(this,"oops遇到些问题","输入的参数非法，请重新输入！");
        return;
    }
    progressDialog=new QProgressDialog(this);
    connect(acoThread,SIGNAL(progressValue(int)),this->progressDialog,SLOT(setValue(int)));
    progressDialog->setMinimum(0);
    progressDialog->setMaximum(100);
    progressDialog->setLabelText("计算中...");
    progressDialog->setCancelButton(nullptr);
    progressDialog->setFixedSize(200,50);
    progressDialog->setWindowFlag(Qt::ToolTip);
    progressDialog->show();
    acoThread->getParameter(ui->antSizeEdit->text().toInt(),
                            ui->cycleTimeEdit->text().toInt(),
                            ui->PheromoneImportantValueEdit->text().toInt(),
                            ui->HeFuntionImportValueEdit->text().toInt(),
                            ui->PheromoneVolatilizationEdit->text().toDouble());
    qtime.start();
    acoThread->start();
}



void MainWindow::recvMinPath(QVector<int> path)
{

    QString outputPathStr;
    outputPathStr.append("路径:[");
    for(auto i=path.begin();i!=path.end();i++){
        outputPathStr.append(QString::number((*i)+1));
        outputPathStr.append(' ');
    }
    outputPathStr.append("]");
    ui->outputLabel->setText(outputPathStr);
}

void MainWindow::recvMinPathLength(double pathLength)
{
    ui->pathLengthLabel->setText(QString("最短路径长度:%1").arg(pathLength));
}


