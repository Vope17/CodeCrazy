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

    int currentTabCount;

public slots:
    void createNewTab(const QString &problem_name);
    void closeProblemTab(int index);
};

#endif // SOLVINGDIALOG_H
