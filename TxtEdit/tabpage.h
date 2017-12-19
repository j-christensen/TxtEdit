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

private:
    Ui::TabPage *ui;
};

#endif // TABPAGE_H
