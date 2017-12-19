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
    void setFileName(QString name);
    QString getFileName();

private:
    Ui::TabPage *ui;
    QString FileName;
};

#endif // TABPAGE_H
