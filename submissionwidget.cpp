#include "submissionwidget.h"
#include "ui_submissionwidget.h"

SubmissionWidget::SubmissionWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SubmissionWidget)
{
    ui->setupUi(this);
}

SubmissionWidget::~SubmissionWidget()
{
    delete ui;
}
