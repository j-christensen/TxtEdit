#include "tabpage.h"
#include "ui_tabpage.h"
#include "QFileInfo"
#include "QMessageBox"
#include "QTextStream"
#include "QFileDialog"

TabPage::TabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPage)
{
    ui->setupUi(this);
    Changed=false;
}

TabPage::~TabPage()
{
    delete ui;
}

void TabPage::saveFile(){
    if(QFileInfo::exists(FileDir)){
        QFile file(FileDir);
        if(!file.open(QIODevice::WriteOnly | QFile::Text)){
            QMessageBox::warning(this,"..","No file opened. Use Save As");
            return;
        }
        QTextStream out(&file);
        QString text = ui->Editor->toPlainText();
        out << text;
        file.flush();
        file.close();
    }else{
        //add stuff to Save As
        saveFileAs();
    }
    Changed=false;
}
void TabPage::saveFileAs(){
    QString newFileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(newFileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"..","File not opened.");
        return;
    }
    FileDir=newFileName;
    Title=getFileName();
    QTextStream out(&file);
    QString text = ui->Editor->toPlainText();
    out << text;
    file.flush();
    file.close();
    Changed=false;
}

bool TabPage::openFile(){
    QString filepath = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","File not opened.");
        return false;
    }
    FileDir=filepath;
    Title=this->getFileName();
    QTextStream in(&file);
    QString text = in.readAll();

    ui->Editor->setText(text);
    Changed=false;
    file.close();
    return true;
}

void TabPage::setFileDir(QString name){
    FileDir=name;
}

QString TabPage::getFileDir(){
    return FileDir;
}

void TabPage::setTitle(QString title){
    Title=title;
}

QString TabPage::getTitle(){
    return Title;
}

QString TabPage::getFileName(){
    QFileInfo fileInfo(getFileDir());
    return fileInfo.fileName();
}

bool TabPage::isChanged(){
    return Changed;
}

void TabPage::on_Editor_textChanged()
{
    Changed=true;
}
