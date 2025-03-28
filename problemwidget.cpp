#include "problemwidget.h"
#include "ui_problemwidget.h"

ProblemWidget::ProblemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProblemWidget)
{
    ui->setupUi(this);



    connect(ui->Example1_Problem_PushButton, &QPushButton::clicked, this, &ProblemWidget::openNewSolvingDialog);
}

ProblemWidget::~ProblemWidget()
{
    delete ui;
}

bool ProblemWidget::openNewSolvingDialog()
{
    solving_dialog = new SolvingDialog(this);

    solving_dialog->show();
    return false;
}
