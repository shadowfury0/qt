#include "syntaxhighlighter.h"

syntaxhighlighter::syntaxhighlighter(QTextDocument * parent) : QSyntaxHighlighter(parent)
{

}
void syntaxhighlighter::highlightBlock(const QString &text){
    //高亮文本块
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    format.setForeground(Qt::green);
    QString pattern = "\\bchar\\b";
    QRegExp expression(pattern);//创建正则表达式
    int index = text.indexOf(expression);
    while (index>=0) {
        int length = expression.matchedLength();
        setFormat(index,length,format);
        index = text.indexOf(expression,index+length);
    }
}
