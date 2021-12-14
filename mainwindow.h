#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<aco.h>
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

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
