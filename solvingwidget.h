#ifndef SOLVINGWIDGET_H
#define SOLVINGWIDGET_H

#include "codesyntaxhighlighter.h"
#include "codeoutputwidget.h"
#include "compileerrorwidget.h"
#include "compilerprocess.h"

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
    //friend class SolvingDialog;
public:
    explicit SolvingWidget(QWidget *parent = nullptr);
    ~SolvingWidget();

private:

    CompilerProcess *compiler = nullptr;
    CodeOutputWidget codeOutputWidget;
    CompileErrorWidget compileErrorWidget;

    CodeSyntaxHighlighter *highlighter;
    Ui::SolvingWidget *ui;

private slots:
    void compileCode();
    void handleCompileOutput(const QString &output);
    void handleCompileError(const QString &output);
    void compilationFinished(int exitCode, QProcess::ExitStatus exitStatus, const QString &tempFilePath);

};


#endif // SOLVINGWIDGET_H
