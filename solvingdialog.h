#ifndef SOLVINGDIALOG_H
#define SOLVINGDIALOG_H

#include <QDialog>

namespace Ui {
class SolvingDialog;
}

class SolvingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SolvingDialog(QWidget *parent = nullptr);
    ~SolvingDialog();

private:
    Ui::SolvingDialog *ui;
};

#endif // SOLVINGDIALOG_H
