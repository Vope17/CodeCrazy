#include "codesyntaxhighlighter.h"

CodeSyntaxHighlighter::CodeSyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter{parent}
{
    // Simple "if" keyword
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(Qt::blue);
    QRegularExpression keywordRegex("\\bif\\b");
    HighlightingRule rule;
    rule.pattern = keywordRegex;
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    // more...
}

CodeSyntaxHighlighter::~CodeSyntaxHighlighter()
{
}

void CodeSyntaxHighlighter::highlightBlock(const QString &text){
    // Trying to match all of rules
    for (const HighlightingRule &rule : std::as_const(highlightingRules))
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}


