#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    connect(ui->Close_PushButton, &QPushButton::clicked, [this]{
        this->close();
    });
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
