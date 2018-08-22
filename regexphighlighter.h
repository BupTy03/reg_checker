#ifndef REGEXPHIGHLIGHTER_H
#define REGEXPHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

class RegExpHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

private:
    QString pattern;

public:
    explicit RegExpHighlighter(QObject* parent = nullptr);
    void highlightBlock(const QString& text);
    void setPattern(QString str);
};

#endif // REGEXPHIGHLIGHTER_H
