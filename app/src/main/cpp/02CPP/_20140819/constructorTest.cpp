//
// Created by sunalong on 17/3/9 17:47.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
class MyClass{
public:
    int num;
public:
    MyClass():num(4){
        cout<<"MyClass:num(4),num:"<<num<<endl;
    }
    MyClass(int data){
        num = data;
        cout<<"MyClass(int data),num:"<<num<<endl;
    }
    ~MyClass(){
        cout<<"~MyClass"<<endl;
    }
};
int main() {
    MyClass myClass0;
    MyClass myClass1(10);
    MyClass myClass2 = 20;// 自动调用带参数的构造函数
    MyClass *p = new MyClass(30);
    system("rm -rf a.out*");
    return 0;
}

