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
    newTab("");
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
    int i;
    bool isitaken=true;
    QString str;
    for(i=1;isitaken;i++){//i is the number to be added on the end of tab name
        isitaken=false;
        for (int j=0;j<=isUntitled.length();j++){
            if(isUntitled[j]==i){
                isitaken=true;
                break;
            }
        }
    }

    isUntitled.push_back(true);
    int numUntitled=0;
    for(int i=0;i<isUntitled.length();i++){
            if (isUntitled[i]){
                numUntitled+=1;
            }
        }
        str.setNum(numUntitled);
        str="Untitled "+str;
    int tab = newTab("");
}
