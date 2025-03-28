#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "homewidget.h"
#include "problemwidget.h"
#include "submissionwidget.h"
#include "aboutdialog.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    HomeWidget *home_widget;
    ProblemWidget *problem_widget;
    SubmissionWidget *submission_widget;
    AboutDialog *about_dialog;
};
#endif // MAINWINDOW_H
