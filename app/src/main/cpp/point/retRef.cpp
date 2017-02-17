//
// Created by sunalong on 17/2/7 15:43.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;

int &func() {
    int q;
    cout<<"【in func q = "<<q<<"】"<<endl;
    return q;//不发生错误
}

int main() {
    func() = 10;
    func() = 8;
    int x = func();
    cout<<"func():"<<func()<<"   x:"<<x<<"    &x:"<<&x<<endl;
    return 0;
}
