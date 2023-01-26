#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <glib.h>
#include <NetworkManager.h>
#include <QMainWindow>
#include <QStringListModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    NMClient* client;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
