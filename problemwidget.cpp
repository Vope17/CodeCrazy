#include "problemwidget.h"
#include "ui_problemwidget.h"

ProblemWidget::ProblemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProblemWidget)
{
    ui->setupUi(this);

    m_problemButtonGroup = new QButtonGroup(this);
    m_solvingDialog = new SolvingDialog(this);

    m_problemButtonGroup->addButton(ui->Example1_Problem_PushButton);

    connect(m_problemButtonGroup, &QButtonGroup::buttonClicked, this, &ProblemWidget::handleProblemButtonClicked);
    connect(this, &ProblemWidget::createSolvingTab, m_solvingDialog, &SolvingDialog::createNewTab);
}

ProblemWidget::~ProblemWidget()
{
    delete ui;
}

void ProblemWidget::handleProblemButtonClicked(QAbstractButton *button)
{
    if (m_solvingDialog == nullptr)
    {
        m_solvingDialog = new SolvingDialog(this);
    }
    emit createSolvingTab(button->text());
    m_solvingDialog->show();
}
