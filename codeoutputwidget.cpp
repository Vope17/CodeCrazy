#include "codeoutputwidget.h"
#include "ui_codeoutputwidget.h"

CodeOutputWidget::CodeOutputWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CodeOutputWidget)
{
    ui->setupUi(this);

}

CodeOutputWidget::~CodeOutputWidget()
{
    delete ui;
}


void CodeOutputWidget::setInput(const QString &input)
{
    ui->Input_TextBrowser->setText(input);
}

void CodeOutputWidget::setCorrectOutput(const QString &correctOutput)
{
    ui->CorrectOutput_TextBrowser->setText(correctOutput);
}

void CodeOutputWidget::setUserOutput(const QString &userOutput)
{
    ui->UserOutput_TextBrowser->setText(userOutput);
}
