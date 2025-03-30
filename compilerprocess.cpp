#include "compilerprocess.h"

CompilerProcess::CompilerProcess(QObject *parent)
    : QObject{parent}
{

    compiler = new QProcess(this);
    connect(compiler, &QProcess::readyReadStandardOutput,
            this, &CompilerProcess::handleCompileOutput);
    connect(compiler, &QProcess::readyReadStandardError,
            this, &CompilerProcess::handleCompileError);
    connect(compiler, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &CompilerProcess::compilationFinished);
}

CompilerProcess::~CompilerProcess()
{
    if (compiler->state() == QProcess::Running)
    {
        compiler->kill();
    }
}

void CompilerProcess::compile(const QString &sourceCode)
{
    if (sourceCode.trimmed().isEmpty())
    {
        emit error("Error: No Input");
        return;
    }

    QTemporaryFile sourceFile;
    sourceFile.setFileTemplate(QDir::tempPath() + "/XXXXXX.cpp");
    sourceFile.setAutoRemove(false);

    if (!sourceFile.open())
    {
        emit error("錯誤：無法創建臨時文件！");
        return;
    }

    QTextStream stream(&sourceFile);
    stream << sourceCode;
    sourceFile.close();

    tempFilePath = sourceFile.fileName();
    QString outputPath = QFileInfo(tempFilePath).path() + "/output.exe";

    QStringList arguments;
    arguments << tempFilePath
              << "-o" << outputPath
              << "-Wall"
              << "-Wextra"
              << "-std=c++17";

    emit compileStarted();
    qDebug() << "Start compile";
    compiler->start("g++", arguments);
}

void CompilerProcess::handleCompileOutput()
{
    QString output = QString::fromLocal8Bit(compiler->readAllStandardOutput());
    emit outputReceived(output);
}
void CompilerProcess::handleCompileError()
{
    QString errorMsg = QString::fromLocal8Bit(compiler->readAllStandardError());
    emit outputReceived("<span style='color: red'>" + errorMsg + "</span>");
}
void CompilerProcess::compilationFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    //if (exitStatus == QProcess::NormalExit && exitCode == 0)
    //{
    //}
    //else
    //{
    //}

    emit compileFinished(exitCode, exitStatus, tempFilePath);
}
