//
// Created by sunalong on 16/12/23 15:14.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
int main(){
    int i=5;
    int& iRe = i;
    int* iPtr;
    iPtr = &i;
    cout<<"int变量 i 指向堆内存中的地址：&i="<<&i<<endl;
    cout<<"int变量 i 指向堆内存中的地址所指向的值：i="<<i<<endl;

    cout<<"引用变量 iRe 存储的堆内存地址：&iRe="<<&iRe<<endl;
    cout<<"引用变量 iRe 存储的堆内存地址指向的值：iRe="<<iRe<<endl;

    cout<<"指针变量 iPtr 指向堆内存中的地址：&iRe="<<&iPtr<<endl;
    cout<<"指针变量 iPtr 存储的堆内存地址：iRe="<<iPtr<<endl;
    cout<<"指针变量 iPtr 存储的堆内存地址指向的值：*iRe="<<*iPtr<<endl;

    cout<<"指向的值：:*iPtr==i:"<<(*iPtr==i)<<endl;
    cout<<"存储的内存地址：iPtr==&iRe:"<<(iPtr==&iRe)<<endl;
    return 0;
}
//int变量 i 指向堆内存中的地址：&i=0x7fff5b9a7a38
//int变量 i 指向堆内存中的地址所指向的值：i=5
//引用变量 iRe 存储的堆内存地址：&iRe=0x7fff5b9a7a38
//引用变量 iRe 存储的堆内存地址指向的值：iRe=5
//指针变量 iPtr 指向堆内存中的地址：&iRe=0x7fff5b9a7a28
//指针变量 iPtr 存储的堆内存地址：iRe=0x7fff5b9a7a38
//指针变量 iPtr 存储的堆内存地址指向的值：*iRe=5
//指向的值：:*iPtr==i:1
//存储的内存地址：iPtr==&iRe:1

