#include "solvingwidget.h"
#include "ui_solvingwidget.h"

SolvingWidget::SolvingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SolvingWidget)
{
    ui->setupUi(this);
    connect(ui->Compile_Buttion, &QPushButton::clicked, this, &SolvingWidget::compileCode);

    // Init Compiler process
    compiler = new QProcess(this);
    connect(compiler, &QProcess::readyReadStandardOutput,
            this, &SolvingWidget::handleCompileOutput);
    connect(compiler, &QProcess::readyReadStandardError,
            this, &SolvingWidget::handleCompileError);
    connect(compiler, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>
            (&QProcess::finished),
            this, &SolvingWidget::compilationFinished);

    // Code Syntax Highlight
    CodeSyntaxHighlighter *highlighter = new CodeSyntaxHighlighter(ui->CodeEditor_TextEdit->document());
}

SolvingWidget::~SolvingWidget()
{
    delete ui;
    if (compiler->state() == QProcess::Running)
    {
        compiler->kill();
    }

    if (!tempFilePath.isEmpty() && QFile::exists(tempFilePath))
    {
        QFile::remove(tempFilePath);
    }
}

void SolvingWidget::compileCode()
{
    ui->Compile_Buttion->setEnabled(false);
    ui->Output_Display_TextBrowser->clear();
    QString sourceCode = ui->CodeEditor_TextEdit->toPlainText();
    if (sourceCode.trimmed().isEmpty())
    {
        ui->Output_Display_TextBrowser->append("Error: No Input");
        ui->Compile_Buttion->setEnabled(true);
        return;
    }

    QTemporaryFile sourceFile;
    sourceFile.setFileTemplate(QDir::tempPath() + "/XXXXXX.cpp");
    sourceFile.setAutoRemove(false);  // 不要自動刪除

    if (!sourceFile.open()) {
        ui->Output_Display_TextBrowser->append("錯誤：無法創建臨時文件！");
        ui->Compile_Buttion->setEnabled(true);
        return;
    }

    // Write the code into temporary file
    QTextStream stream(&sourceFile);
    stream << sourceCode;
    sourceFile.close();

    tempFilePath = sourceFile.fileName();
    QString outputPath = QFileInfo(tempFilePath).path() + "/output.exe";

    // Setting argumetns
    QStringList arguments;
    arguments << tempFilePath
              << "-o" << outputPath
              << "-Wall"
              << "-Wextra"
              << "-std=c++17";

    qDebug() << arguments;
    ui->Output_Display_TextBrowser->append("正在編譯...\n");

    // Start
    compiler->start("g++", arguments);
}

void SolvingWidget::handleCompileOutput()
{
    QString output = QString::fromLocal8Bit(compiler->readAllStandardOutput());
    ui->Output_Display_TextBrowser->append(output);
}

void SolvingWidget::handleCompileError()
{
    QString error = QString::fromLocal8Bit(compiler->readAllStandardError());
    ui->Output_Display_TextBrowser->append("<span style='color: red'>" + error + "</span>");
}

void SolvingWidget::compilationFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    ui->Compile_Buttion->setEnabled(true);

    if (exitStatus == QProcess::NormalExit && exitCode == 0) {
        ui->Output_Display_TextBrowser->append("<span style='color: green'>編譯成功！</span>");
        QString outputPath = QFileInfo(tempFilePath).path() + "/output.exe";
        ui->Output_Display_TextBrowser->append("可執行文件位置：" + outputPath);
    } else {
        ui->Output_Display_TextBrowser->append("<span style='color: red'>編譯失敗！</span>");
    }

    // 清理臨時源代碼文件
    QFile::remove(tempFilePath);
}
