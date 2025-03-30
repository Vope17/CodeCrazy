#include "solvingwidget.h"
#include "ui_solvingwidget.h"

SolvingWidget::SolvingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SolvingWidget)
{
    ui->setupUi(this);

    //compileErrorWidget.hide();
    //codeOutputWidget.hide();

    connect(ui->Compile_Buttion, &QPushButton::clicked, this, &SolvingWidget::compileCode);

    // Init Compiler process
    compiler = new CompilerProcess(this);
    connect(compiler, &CompilerProcess::outputReceived,
            this, &SolvingWidget::handleCompileOutput);

    connect(compiler, &CompilerProcess::outputReceived,
            this, &SolvingWidget::handleCompileError);

    connect(compiler, &CompilerProcess::compileFinished,
            this, &SolvingWidget::compilationFinished);

    // Code Syntax Highlight
    CodeSyntaxHighlighter *highlighter = new CodeSyntaxHighlighter(ui->CodeEditor_TextEdit->document());
}

SolvingWidget::~SolvingWidget()
{
    delete ui;
}

void SolvingWidget::compileCode()
{
    ui->Compile_Buttion->setEnabled(false);

    QString sourceCode = ui->CodeEditor_TextEdit->toPlainText();
    if (sourceCode.trimmed().isEmpty())
    {
    //    ui->Output_Display_TextBrowser->append("Error: No Input");
        ui->Compile_Buttion->setEnabled(true);
        return;
    }

    // Start
    compiler->compile(sourceCode);
}

void SolvingWidget::handleCompileOutput(const QString &output)
{
    //ui->Output_Display_TextBrowser->append(output);
}

void SolvingWidget::handleCompileError(const QString &output)
{
    compileErrorWidget.setErrorMessage(output);
}

void SolvingWidget::compilationFinished(int exitCode, QProcess::ExitStatus exitStatus, const QString &tempFilePath)
{
    ui->Compile_Buttion->setEnabled(true);

    while (ui->Code_Output_VerticalLayout->count() > 0)
    {
        QWidget *widget = ui->Code_Output_VerticalLayout->itemAt(0)->widget();
        if (widget)
        {
            ui->Code_Output_VerticalLayout->removeWidget(widget);
            widget->hide();
        }
    }

    if (exitStatus == QProcess::NormalExit && exitCode == 0)
    {
        // If compilation success, execute it
        //ui->Output_Display_TextBrowser->append("<span style='color: green'>編譯成功！</span>");
        qDebug() << "編譯成功";
        QString outputPath = QFileInfo(tempFilePath).path() + "/output.exe";

        QProcess *process = new QProcess(this);
        // Merge stdout and stderr
        process->setProcessChannelMode(QProcess::MergedChannels);

        // TODO: 連接 readyRead 信號，持續讀取執行的輸出並將之加入到 TextBrowser
        connect(process, &QProcess::readyRead, [=]() {
            QByteArray output = process->readAll();
            //ui->Output_Display_TextBrowser->append(QString::fromLocal8Bit(output));
        });

        // Delete this process after execution
        connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                [=](int exitCode, QProcess::ExitStatus exitStatus) {
                    //ui->Output_Display_TextBrowser->append(QString("<span style='color: blue'>執行結束，退出碼：%1</span>").arg(exitCode));
                    process->deleteLater();
                });

        // Start
        process->start(outputPath);
        ui->Code_Output_VerticalLayout->addWidget(&codeOutputWidget);
        codeOutputWidget.show();
    }
    else
    {
        ui->Code_Output_VerticalLayout->addWidget(&compileErrorWidget);
        qDebug() << "編譯失敗";
        compileErrorWidget.show();
    }
    // Remove temporary file
    QFile::remove(tempFilePath);
}
