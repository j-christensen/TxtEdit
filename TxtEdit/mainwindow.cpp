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
    if (str.isEmpty()){
        isUntitled.push_back(true);
        int numUntitled=0;
        for(int i=0;i<isUntitled.length();i++){
            if (isUntitled[i]){
                numUntitled+=1;
            }
        }
        str.setNum(numUntitled);
        str="Untitled "+str;
    }else{
        isUntitled.push_back(false);
    }
    return ui->tabWidget->addTab(pTab, str);
    //return pTab;
}

void MainWindow::on_actionNew_triggered()
{
    int tab = newTab("");
    QMessageBox msgBox;
    QString str;
    str.setNum(tab);
    str="The created tab has index "+str+".";
    msgBox.setText(str);
    msgBox.exec();
}
