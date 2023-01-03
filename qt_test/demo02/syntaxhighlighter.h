#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
class syntaxhighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit syntaxhighlighter(QTextDocument * parent=nullptr);
    void highlightBlock(const QString &text);
};

#endif // SYNTAXHIGHLIGHTER_H
