#ifndef COMPILEERRORWIDGET_H
#define COMPILEERRORWIDGET_H

#include <QWidget>

namespace Ui {
class CompileErrorWidget;
}

class CompileErrorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CompileErrorWidget(QWidget *parent = nullptr);
    ~CompileErrorWidget();

    void setErrorMessage(const QString &errorMessage);

private:
    Ui::CompileErrorWidget *ui;
};

#endif // COMPILEERRORWIDGET_H
