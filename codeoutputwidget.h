#ifndef CODEOUTPUTWIDGET_H
#define CODEOUTPUTWIDGET_H

#include <QWidget>

namespace Ui {
class CodeOutputWidget;
}

class CodeOutputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CodeOutputWidget(QWidget *parent = nullptr);
    ~CodeOutputWidget();

    void setInput(const QString &input);
    void setCorrectOutput(const QString &correctOutput);
    void setUserOutput(const QString &userOutput);

private:
    Ui::CodeOutputWidget *ui;


};

#endif // CODEOUTPUTWIDGET_H
