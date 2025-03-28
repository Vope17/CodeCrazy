#ifndef SUBMISSIONWIDGET_H
#define SUBMISSIONWIDGET_H

#include <QWidget>

namespace Ui {
class SubmissionWidget;
}

class SubmissionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubmissionWidget(QWidget *parent = nullptr);
    ~SubmissionWidget();

private:
    Ui::SubmissionWidget *ui;
};

#endif // SUBMISSIONWIDGET_H
