#ifndef PROBLEMWIDGET_H
#define PROBLEMWIDGET_H

#include "solvingdialog.h"

#include <QWidget>
#include <QButtonGroup>


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

    SolvingDialog *m_solvingDialog = nullptr;
    QButtonGroup *m_problemButtonGroup = nullptr;

signals:
    void createSolvingTab(const QString &problem_name);

private slots:
    void handleProblemButtonClicked(QAbstractButton *button);
};

#endif // PROBLEMWIDGET_H
