#include "updatedialog.h"
#include "ui_updatedialog.h"
#include <QDebug>
#include <thread>

UpdateDialog::UpdateDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UpdateDialog)
{
    ui->setupUi(this);
    connect(this, &UpdateDialog::MakeChoiced, &::UpdateByUser);
}

UpdateDialog::~UpdateDialog()
{
    delete ui;
    qDebug() << "Update 销毁";
}

void UpdateDialog::on_YesOrNot_accepted()
{
    this->close();
    emit MakeChoiced(true);
}

void UpdateDialog::on_YesOrNot_rejected()
{
    this->close();
    //isWaitting = false;
    emit MakeChoiced(false);
}

void UpdateDialog::closeEvent(QCloseEvent *event) {
    qDebug() << "关闭";
    emit MakeChoiced(false);
}

bool UpdateByUser(bool _choice) {
    qDebug() << _choice;
    return _choice;
}

