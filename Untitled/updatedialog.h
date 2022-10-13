#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

/*
UpdateDialog类可自动调用UpdateByUser函数来返回用户选择结果
*/

namespace Ui {
class UpdateDialog;
}


bool UpdateByUser(bool _choice);

class UpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateDialog(QWidget *parent = nullptr);
    ~UpdateDialog();

private slots:
    void on_YesOrNot_accepted();
    void on_YesOrNot_rejected();

private:
    Ui::UpdateDialog *ui;
    void closeEvent(QCloseEvent *event) override;
signals:
    void MakeChoiced(bool _choice);
};

#endif // UPDATEDIALOG_H
