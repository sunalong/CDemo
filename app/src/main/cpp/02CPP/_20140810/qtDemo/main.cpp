//
// Created by sunalong on 17/3/4 10:09.
// Email:466210864@qq.com
//

#include <QApplication>
#include "MyWidget.h"
int main(int argc,char*argv[]){
    QApplication qApplication(argc,argv);
    MyWidget myWidget;
    myWidget.show();
    return qApplication.exec();
}


