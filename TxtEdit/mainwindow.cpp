#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabpage.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    TabPage *pTab = new TabPage;
    Tabs.push_back(pTab);
    ui->tabWidget->removeTab(0);
    isUntitled.push_back(1);
    TabNames.push_back("Untitled 1");
    newTab("Untitled 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::newTab(QString str){
    TabPage *pTab = new TabPage;
    Tabs.push_back(pTab);

    return ui->tabWidget->addTab(pTab, str);
}

void MainWindow::on_actionNew_triggered()
{
    int iToUse;
    bool isitaken=true;
    QString str;
    for(int i=1;isitaken;i++){//i is the number to be added on the end of tab name
        isitaken=false;
        for (int j=0;j<isUntitled.length();j++){
            if(isUntitled[j]==i){
                isitaken=true;
                break;
            }
        }
        if (!isitaken){
            iToUse=i;
        }
    }

    str.setNum(iToUse);
    str="Untitled "+str;
    isUntitled.push_back(iToUse);
    TabNames.push_back(str);
    newTab(str);
}
