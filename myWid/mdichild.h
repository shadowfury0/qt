#ifndef MDICHILD_H
#define MDICHILD_H
#include <QTextEdit>
class QTextEdit;
class MdiChild:public QTextEdit
{
    Q_OBJECT
public:
    MdiChild(QWidget * parent = 0);
    void newFile();
    bool loadFile(const QString &fileName);
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    QString userFriendCurrentFile();
    QString currentFile(){return curFile;}
protected:
    void closeEvent(QCloseEvent * event);
private slots:
    void documentWasModified();
    void contextMenuEvent(QContextMenuEvent *e) override;
private:
    bool maybeSave();
    void setCurrentFile(const QString &fileName);
    QString curFile;
    bool isUntitied;
};

#endif // MDICHILD_H
