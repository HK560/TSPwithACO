#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<aco.h>
#include<QVector>
#include"citymap.h"
#include<QMessageBox>
#include"acothread.h"
#include<QProgressDialog>
#include <QMetaType>
QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ResultBtn_clicked();
public slots:
//    void recvPrograssValue(int value);
    void recvMinPath(QVector<int>path);
    void recvMinPathLength(double pathLength);
    void showResult(QLineSeries* series);

private:
    Ui::MainWindow *ui;
    AcoThread* acoThread;
    QProgressDialog* progressBar;
};
#endif // MAINWINDOW_H
