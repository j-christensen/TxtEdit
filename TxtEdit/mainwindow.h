#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tabpage.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<TabPage *> Tabs;

protected:
    int newTab(QString str);
private slots:
    void on_actionNew_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionOpen_triggered();
};

#endif // MAINWINDOW_H
