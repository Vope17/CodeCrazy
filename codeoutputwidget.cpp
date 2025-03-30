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
