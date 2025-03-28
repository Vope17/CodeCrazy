#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    home_widget = new HomeWidget(this);
    problem_widget = new ProblemWidget(this);
    submission_widget = new SubmissionWidget(this);
    about_dialog = new AboutDialog(this);

    ui->MainPage_stackedWidget->addWidget(home_widget);
    ui->MainPage_stackedWidget->addWidget(problem_widget);
    ui->MainPage_stackedWidget->addWidget(submission_widget);

    ui->MainPage_stackedWidget->setCurrentIndex(0);

    connect(ui->All_Problem_Action, &QAction::triggered, [this](){
        ui->MainPage_stackedWidget->setCurrentIndex(1);
    });

    connect(ui->Submission_Action, &QAction::triggered, [this](){
        ui->MainPage_stackedWidget->setCurrentIndex(2);
    });

    connect(ui->AboutThis_Action, &QAction::triggered, [this](){
        about_dialog->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
