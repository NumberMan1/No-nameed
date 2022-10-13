#include "Mainwindow.h"
#include "updatedialog.h"

#include <thread>
#include <future>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    UpdateDialog updateDialog;
    updateDialog.show();
    return a.exec();
}
