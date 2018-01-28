#include "tabpage.h"
#include "ui_tabpage.h"
#include "QFileInfo"

TabPage::TabPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabPage)
{
    ui->setupUi(this);
}

TabPage::~TabPage()
{
    delete ui;
}

void TabPage::setFileDir(QString name){
    FileDir=name;
}

QString TabPage::getFileDir(){
    return FileDir;
}
QString TabPage::getFileName(){
    QFileInfo fileInfo(getFileDir());
    return fileInfo.fileName();
}
bool TabPage::isChanged(){
    return Changed;
}
void TabPage::setTitle(QString title){
    Title=title;
}
QString TabPage::getTitle(){
    return Title;
}
void TabPage::setEditor(QString text){
    ui->Editor->setText(text);
}
void TabPage::saveFile(){

}
