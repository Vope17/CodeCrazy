#include "solvingdialog.h"
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
