#ifndef SOLVINGWIDGET_H
#define SOLVINGWIDGET_H

#include "codesyntaxhighlighter.h"

#include <QWidget>
#include <QProcess>
#include <QTemporaryFile>
#include <QFileInfo>
#include <QDebug>
#include <QDir>

namespace Ui {
class SolvingWidget;
}

class SolvingWidget : public QWidget
{
    Q_OBJECT
    friend class SolvingDialog;
public:
    explicit SolvingWidget(QWidget *parent = nullptr);
    ~SolvingWidget();

private:
    QProcess *compiler;          // 編譯器進程
    QString tempFilePath;        // 臨時文件路徑
    CodeSyntaxHighlighter *highlighter;
    Ui::SolvingWidget *ui;

private slots:
    void compileCode();
    void handleCompileOutput();
    void handleCompileError();
    void compilationFinished(int exitCode, QProcess::ExitStatus exitStatus);

};


#endif // SOLVINGWIDGET_H
