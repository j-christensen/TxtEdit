#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabpage.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QTextStream"
#include "QTabWidget"
#include "QTextEdit"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->tabWidget->removeTab(0);
    newTab("Untitled 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::newTab(QString str){
    TabPage *pTab = new TabPage;
    Tabs.push_back(pTab);
    pTab->setTitle(str);
    return ui->tabWidget->addTab(pTab, str);
}

void MainWindow::on_actionNew_triggered()
{
    QString str;
    bool isigood=false;
    //code to get tab number for Untitled tabs.
    for(int i=1 ; !isigood ; i++){
        str.setNum(i);
        str="Untitled "+str;
        isigood=true;
        for(int j=0; j<Tabs.length();j++){
            if(str==Tabs[j]->getTitle()){
                isigood=false;
                break;
            }
        }
    }
    newTab(str);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    TabPage *closingTab=Tabs[index];
    //check to see if file needs to be saved.
    if(closingTab->isChanged()){//save contents
        closingTab->saveFile();
    }
    //remove tab
    ui->tabWidget->removeTab(index);
    Tabs.removeAt(index);
    delete closingTab;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not opened.");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();

    int tabindex = newTab(fileName);
    ui->tabWidget->setCurrentIndex(tabindex);
    TabPage *pTabPage=Tabs[tabindex];
    QList<QTextEdit *> allTextEdits = pTabPage->findChildren<QTextEdit *>();
    QTextEdit *pTextEdit=allTextEdits[0];
    pTextEdit->setText(text);
    file.close();

}
