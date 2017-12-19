#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabpage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    TabPage *myNewTab = new TabPage;
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(myNewTab, tr("File 1"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
