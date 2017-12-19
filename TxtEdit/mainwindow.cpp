#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabpage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    TabPage *pTab = new TabPage;
    Tabs.push_back(pTab);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(pTab, tr("Untitled"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
