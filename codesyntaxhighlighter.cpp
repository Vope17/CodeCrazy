#include "codesyntaxhighlighter.h"

CodeSyntaxHighlighter::CodeSyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter{parent}
{
    // Gruvbox theme
    // keyword: blue
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(QColor("#83a598"));
    keywordFormat.setFontWeight(QFont::Bold);

    QStringList keywordPatterns;
    keywordPatterns << "\\bif\\b"
                    << "\\belse\\b"
                    << "\\bfor\\b"
                    << "\\bwhile\\b"
                    << "\\bdo\\b"
                    << "\\bswitch\\b"
                    << "\\bcase\\b"
                    << "\\bbreak\\b"
                    << "\\bcontinue\\b"
                    << "\\breturn\\b"
                    << "\\bclass\\b"
                    << "\\bstruct\\b"
                    << "\\benum\\b"
                    << "\\bpublic\\b"
                    << "\\bprivate\\b"
                    << "\\bprotected\\b"
                    << "\\btemplate\\b"
                    << "\\btypename\\b"
                    << "\\btry\\b"
                    << "\\bcatch\\b"
                    << "\\bnamespace\\b";

    for (const QString &pattern : keywordPatterns)
    {
        HighlightingRule rule;
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    // String: green
    QTextCharFormat stringFormat;
    stringFormat.setForeground(QColor("#b8bb26"));
    HighlightingRule stringRule;
    stringRule.pattern = QRegularExpression("\".*?\"");
    stringRule.format = stringFormat;
    highlightingRules.append(stringRule);

    // Comment: gray
    QTextCharFormat commentFormat;
    commentFormat.setForeground(QColor("#928374"));
    HighlightingRule commentRule;
    commentRule.pattern = QRegularExpression("#[^\n]*");
    commentRule.format = commentFormat;
    highlightingRules.append(commentRule);

    // Number: purple
    QTextCharFormat numberFormat;
    numberFormat.setForeground(QColor("#d3869b"));
    HighlightingRule numberRule;
    numberRule.pattern = QRegularExpression("\\b[0-9]+(\\.[0-9]+)?\\b");
    numberRule.format = numberFormat;
    highlightingRules.append(numberRule);

}

CodeSyntaxHighlighter::~CodeSyntaxHighlighter()
{
}

void CodeSyntaxHighlighter::highlightBlock(const QString &text){
    // Trying to match all of rules
    for (const HighlightingRule &rule : std::as_const(highlightingRules))
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}


