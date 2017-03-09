//
// Created by sunalong on 17/3/9 10:17.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
struct Lstruct {
    int num;
    int num2=12;
};
struct MyStruct {
    int num;
    double db = 10.8;
    //Cpp 结构体可以设置默认值
//    MyStruct lala;//结构体内部不可定义本结构对象以免死循环
    MyStruct *pNext;
    MyStruct *pHead;
    Lstruct ls;
} sx, *pMyStruct;

int main() {
    MyStruct myStruct;//自动管理
    MyStruct *pNew = new MyStruct;//手动管理内存
    cout << "myStruct.ls.num:" << myStruct.ls.num<< "   myStruct.ls.num2:" << myStruct.ls.num2 << endl;
    cout << "pNew->ls.num:" << pNew->ls.num << "    pNew->ls.num2:" << pNew->ls.num2 << endl;
    cout << "(*pNew).ls.num:" << (*pNew).ls.num<< "    (*pNew).ls.num2:" << (*pNew).ls.num2 << endl;
    MyStruct myStruct2(myStruct);//C++风格初始化方式
    MyStruct *pNew2(new MyStruct);
    system("rm -rf a.out*");
    return 0;
}

