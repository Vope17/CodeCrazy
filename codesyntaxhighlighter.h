#ifndef CODESYNTAXHIGHLIGHTER_H
#define CODESYNTAXHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QVector>
#include <QString>
#include <QTextDocument>

struct HighlightingRule {
    QRegularExpression pattern;
    QTextCharFormat format;
};

class CodeSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit CodeSyntaxHighlighter(QTextDocument *parent = nullptr);
    ~CodeSyntaxHighlighter();

protected:
    void highlightBlock(const QString &text) override;

private:
    QVector<HighlightingRule> highlightingRules;
};

#endif // CODESYNTAXHIGHLIGHTER_H
