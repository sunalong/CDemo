//
// Created by sunalong on 17/3/9 17:56.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class MyClass {
public:
    int num;
public:
    explicit MyClass(int data){
//    MyClass(int data) {
        this->num = data;
        (*this).num = data;
        cout << "构造函数MyClass(int data),num:" << num << endl;
    }
    ~MyClass() {
        cout << "析构函数" << endl;
    }
};

int main() {
    MyClass myClass0(2);//
//    MyClass myClass1 = 4;//赋值号，类型转换，在构造函数加上 explict 后不可使用
    MyClass *pMyClass = new MyClass(5);
//    MyClass *pMyClassArr[5] = (new MyClass(5))[5]{};
    MyClass *pMyClassArr[3];
    pMyClassArr[0] = new MyClass(0);
    pMyClassArr[1] = new MyClass(1);
    pMyClassArr[2] = new MyClass(2);
    system("rm -rf a.out*");
    return 0;
}

