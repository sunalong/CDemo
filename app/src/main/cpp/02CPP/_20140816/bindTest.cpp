//
// Created by sunalong on 17/3/8 15:25.
// Email:466210864@qq.com
//
#include<iostream>
#include <functional>//处理函数
#include<stdlib.h>

using namespace std;

struct MyStruct {
    void add(int a) {
        cout << "add, a:" << a << endl;
    }

    void add2(int a, int b, int c) {
        cout << "add2, a:" << a << " b:" << b << " c:" << c << endl;
    }
};

void bindAndplaceholders();

int main() {
    bindAndplaceholders();
    MyStruct myStruct;
    void(MyStruct::*p)(int a) = &MyStruct::add;
    void(MyStruct::*p2)(int a,int b,int c)=&MyStruct::add2;
//    p(10);//怎么调用这个函数指针？
//    myStruct.p(10);
//    MyStruct::p(10);
//    p2(10,20,30);
    system("rm -rf a.out*");
    return 0;
}
/**
 *仿函数，创建一个函数指针，引用结构体/类内部的公有函数
 */
void bindAndplaceholders() {
    MyStruct myStruct;
    //auto 自动变量，地址，函数指针，bind 绑定
    //第一个参数引用内部函数，绑定一个实体对象
    auto func1 = bind(&MyStruct::add, &myStruct, placeholders::_1);
    auto func2 = bind(&MyStruct::add2, &myStruct, placeholders::_2, placeholders::_3, placeholders::_1);
    func1(10);
    func2(10, 20, 30);
//    ~/GitHub/CDemo/app/src/main/cpp/02CPP/_20140816 on  master! ⌚ 15:31:34
//    $ g++ -g -Wall -std=c++11 bindTest.cpp
//
//    ~/GitHub/CDemo/app/src/main/cpp/02CPP/_20140816 on  master! ⌚ 15:32:39
//    $ a.out
//    add, a:10
//    add2, a:20 b:30 c:10
}

