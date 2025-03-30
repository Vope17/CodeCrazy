#include "solvingdialog.h"
#include "solvingwidget.h"
#include "ui_solvingdialog.h"


SolvingDialog::SolvingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SolvingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window |
                         Qt::WindowTitleHint |
                         Qt::WindowCloseButtonHint |
                         Qt::WindowMinimizeButtonHint |
                         Qt::WindowMaximizeButtonHint);

    currentTabCount = 0;

    // tabwidget close event
    connect(ui->Problem_TabWidget, &QTabWidget::tabCloseRequested, this, &SolvingDialog::closeProblemTab);
}

SolvingDialog::~SolvingDialog()
{
    delete ui;
}

void SolvingDialog::createNewTab(const QString &probleName)
{
    SolvingWidget *newWidget = new SolvingWidget(this);
    ui->Problem_TabWidget->addTab(newWidget, probleName);
    currentTabCount++;
}

void SolvingDialog::closeProblemTab(int index)
{
    QWidget *tab = ui->Problem_TabWidget->widget(index);
    ui->Problem_TabWidget->removeTab(index);
    tab->deleteLater();
    currentTabCount--;
    if (currentTabCount == 0)
    {
        this->hide();
    }
}
