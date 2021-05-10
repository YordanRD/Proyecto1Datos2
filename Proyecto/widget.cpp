#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Mlocalserver = new LocalServer(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Iniciar_clicked()
{
    if (!Mlocalserver->listen("MyLocalServer")){
        QMessageBox::critical(this, "ERROR", Mlocalserver->errorString());
    } else {
        QMessageBox::information(this,"Server", "Starting...");
    }
}

void Widget::on_Compile_clicked()
{
    QString code = ui->Code->text();
    QString action;
    if (code.contains("int")){
        action = "int";
    }else if (code.contains("long")){
        action = "long";
    }else if (code.contains("char")){
        action = "char";
    }else if (code.contains("float")){
        action = "float";
    }else if (code.contains("double")){
        action = "double";
    }else if (code.contains("struct")){
        action = "struct";
    }else if (code.contains("reference")){
        action = "reference";
    }
    ui->Compiled->addItem(code);
    Mlocalserver->send(action);
}

void Widget::on_Run_clicked()
{

}

void Widget::on_Close_clicked()
{
    close();
}

