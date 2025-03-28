#ifndef PROBLEMWIDGET_H
#define PROBLEMWIDGET_H

#include "solvingdialog.h"

#include <QWidget>


namespace Ui {
class ProblemWidget;
}

class ProblemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProblemWidget(QWidget *parent = nullptr);
    ~ProblemWidget();

private:

    Ui::ProblemWidget *ui;

    SolvingDialog *solving_dialog;


private:

    bool openNewSolvingDialog();
};

#endif // PROBLEMWIDGET_H
