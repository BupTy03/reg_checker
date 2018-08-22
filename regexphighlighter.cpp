#include "regexphighlighter.h"

RegExpHighlighter::RegExpHighlighter(QObject *parent) : QSyntaxHighlighter(parent)
{

}

void RegExpHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat format;

    QRegExp rx(pattern);

    if(!rx.isValid() || rx.isEmpty() || rx.exactMatch(""))
    {
        setFormat(0, text.length(), format);
        return;
    }

    format.setBackground(QBrush(qRgb(105, 184, 245)));

    int index = rx.indexIn(text);
    while (index >= 0)
    {
        int length = rx.matchedLength();
        setFormat(index, length, format);
        index = rx.indexIn(text, index + length);
    }
}

void RegExpHighlighter::setPattern(QString str)
{
    pattern = std::move(str);
}
