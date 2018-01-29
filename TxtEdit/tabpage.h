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
    bool openFile();
    void saveFile();
    void saveFileAs();
    void print();
    void setFileDir(QString name);
    QString getFileDir();
    void setTitle(QString title);
    QString getTitle();
    QString getFileName();
    bool isChanged();
private slots:
    void on_Editor_textChanged();

private:
    Ui::TabPage *ui;
    QString FileDir;
    bool Changed;
    QString Title;
};

#endif // TABPAGE_H
