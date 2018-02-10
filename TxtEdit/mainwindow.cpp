#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabpage.h"
#include "QTabWidget"
#include "QFileInfo"
#include "QMessageBox"

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
    if (QFileInfo::exists(str)){
        pTab->setFileDir(str);
        pTab->setTitle(pTab->getFileName());
    }else{
        pTab->setTitle(str);
    }

    int tabindex = ui->tabWidget->addTab(pTab, pTab->getTitle());
    ui->tabWidget->setCurrentIndex(tabindex);
    return tabindex;
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
        //prompt the user if they want to save changes.
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret){
        case QMessageBox::Save:
            //Save was clicked
            closingTab->saveFile();
            break;
        case QMessageBox::Discard:
            //Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            //Cancel was clicked
            return;
        default:
            //should never be reached
            break;
        }

    }
    //remove tab
    ui->tabWidget->removeTab(index);
    Tabs.removeAt(index);
    delete closingTab;
}

int MainWindow::currentTab(){
    int tabindex=ui->tabWidget->currentIndex();
    return tabindex;
}

void MainWindow::on_actionOpen_triggered()
{
    int tabindex=newTab("");
    if(Tabs[tabindex]->openFile()){
        TabPage *newTab=Tabs[tabindex];
        ui->tabWidget->setTabText(tabindex,newTab->getTitle());
    }else{
        this->on_tabWidget_tabCloseRequested(tabindex);
    }
}

void MainWindow::on_actionSave_triggered()
{
    int tabindex=currentTab();
    Tabs[tabindex]->saveFile();
    ui->tabWidget->setTabText(tabindex,Tabs[tabindex]->getTitle());
}

void MainWindow::on_actionSave_As_triggered()
{
    int tabindex=currentTab();
    Tabs[tabindex]->saveFileAs();
    ui->tabWidget->setTabText(tabindex,Tabs[tabindex]->getTitle());
}

void MainWindow::on_actionPrint_triggered()
{
    Tabs[currentTab()]->print();
}

void MainWindow::on_actionClose_triggered()
{
    on_tabWidget_tabCloseRequested(currentTab());
}

void MainWindow::on_actionUndo_triggered()
{
    Tabs[currentTab()]->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    Tabs[currentTab()]->redo();
}

void MainWindow::on_actionCopy_triggered()
{
    Tabs[currentTab()]->copy();
}

void MainWindow::on_actionCut_triggered()
{
    Tabs[currentTab()]->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    Tabs[currentTab()]->paste();
}
