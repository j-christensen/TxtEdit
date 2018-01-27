#include "tabpage.h"
#include "ui_tabpage.h"

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
bool TabPage::isChanged(){
    return Changed;
}
void TabPage::setTitle(QString title){
    Title=title;
}
QString TabPage::getTitle(){
    return Title;
}
void TabPage::saveFile(){

}
