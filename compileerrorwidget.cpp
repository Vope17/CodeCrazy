#include "compileerrorwidget.h"
#include "ui_compileerrorwidget.h"

CompileErrorWidget::CompileErrorWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CompileErrorWidget)
{
    ui->setupUi(this);
}

CompileErrorWidget::~CompileErrorWidget()
{
    delete ui;
}

void CompileErrorWidget::setErrorMessage(const QString &errorMessage)
{
    ui->CompileError_Message_TextBrowser->setText(errorMessage);
}
