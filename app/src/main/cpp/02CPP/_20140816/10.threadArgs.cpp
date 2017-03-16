//
// Created by sunalong on 17/3/16 10:14.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

int show(const char*fun,...){
    va_list ap;//指针
    va_start(ap,fun);//开始
    vprintf(fun,ap);//调用
    va_end(ap);
    return 0;
}
int main() {
    thread thread1(show,"%s %d  %c  %f","HelloWorld!",100,'A',3.1415926);
    thread1.join();
    system("rm -rf a.out*");
    return 0;
}

