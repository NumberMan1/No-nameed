#include "Mainwindow.h"
#include "./ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gardenBtn_clicked()
{
   Garden::GardenControl::Instance(this, this)->Init();
}

