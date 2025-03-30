#ifndef COMPILER_PROCESS_H
#define COMPILER_PROCESS_H
#include <QObject>
#include <QProcess>
#include <QTemporaryFile>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QString>

class CompilerProcess : public QObject
{
    Q_OBJECT
public:
    explicit CompilerProcess(QObject *parent = nullptr);

    ~CompilerProcess();

    void compile(const QString &sourceCode);

signals:
    void compileStarted();
    void compileFinished(int exitCode, QProcess::ExitStatus exitStatus, const QString &tempFilePath);  // 結束編譯信號
    void outputReceived(const QString &output);
    void error(const QString &errorMsg);

private slots:
    void handleCompileOutput();
    void handleCompileError();
    void compilationFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QProcess *compiler;
    QString tempFilePath;
};

#endif // COMPILER_PROCESS_H
