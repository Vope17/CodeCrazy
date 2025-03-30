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

    void setInput();
    void setCorrectOutput();
    void setUserOutput();

private:
    Ui::CodeOutputWidget *ui;


};

#endif // CODEOUTPUTWIDGET_H
