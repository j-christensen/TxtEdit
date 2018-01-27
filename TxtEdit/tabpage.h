#ifndef TABPAGE_H
#define TABPAGE_H

#include <QWidget>

namespace Ui {
class TabPage;
}

class TabPage : public QWidget
{
    Q_OBJECT

public:
    explicit TabPage(QWidget *parent = 0);
    ~TabPage();
    void setFileDir(QString name);
    QString getFileDir();
    bool isChanged();
    void saveFile();
    QString getTitle();
    void setTitle(QString title);
private:
    Ui::TabPage *ui;
    QString FileDir;
    bool Changed;
    QString Title;
};

#endif // TABPAGE_H
