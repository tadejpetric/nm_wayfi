#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = nm_client_new (NULL, NULL);


    //list << "a" << "b";
    QStringListModel *model = new QStringListModel();
    model->setStringList(get_ssid(client));
    ui->list_wifi->setModel(model);
}


MainWindow::~MainWindow()
{
    g_object_unref(client);
    delete ui;
}

