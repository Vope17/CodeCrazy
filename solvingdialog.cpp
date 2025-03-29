#include "solvingdialog.h"
#include "solvingwidget.h"
#include "ui_solvingdialog.h"


SolvingDialog::SolvingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SolvingDialog)
{
    ui->setupUi(this);
}

SolvingDialog::~SolvingDialog()
{
    delete ui;
}

void SolvingDialog::createNewTab(const QString &probleName)
{
    SolvingWidget *newWidget = new SolvingWidget(this);
    ui->Problem_TabWidget->addTab(newWidget, probleName);
}
