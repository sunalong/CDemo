//
// Created by sunalong on 17/3/4 09:46.
// Email:466210864@qq.com
//

#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    qhBoxLayout1 = new QHBoxLayout;
    qhBoxLayout2 = new QHBoxLayout;
    qGridLayout = new QGridLayout(this);
    qPushButton = new QPushButton;
    qLineEdit1 = new QLineEdit;
    qLineEdit2 = new QLineEdit;
    qLineEdit3 = new QLineEdit;
    qLabel1 = new QLabel;
    qLabel2 = new QLabel;

    qGridLayout->addWidget(qPushButton,0,0);
    qGridLayout->addWidget(qLineEdit1,0,1);
    qGridLayout->addWidget(qLineEdit2,0,2);
    qGridLayout->addWidget(qLineEdit3,1,0);
    qGridLayout->addWidget(qLabel1,1,1);
    qPushButton->setText("确定");
//    当点击 qPushButton 的时候就调用 on_clicked（）这个函数
//    实现控件与具体的槽函数关联
    connect(qPushButton,SIGINT(clicked()),this,SLOT(on_clicked()));
}

MyWidget::~MyWidget() {
    //在 QT 内部，不需要单独 delete 一个控件的指针
    //QT 的窗口在退出的时候会自动 delete 与其相关的的子控件
    delete qLabel2;
}

void MyWidget::on_clicked() {
    int a = qLineEdit1->text().toInt();
    int b = qLineEdit3->text().toInt();
    if(qLineEdit2->text() == "+")
        qLabel1->setText(QString::number(a+b));
    if(qLineEdit2->text() == "-")
        qLabel1->setText(QString::number(a-b));
}

