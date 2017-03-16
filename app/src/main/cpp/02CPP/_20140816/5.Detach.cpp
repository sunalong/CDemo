//
// Created by sunalong on 17/3/16 10:10.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

void show() {
    cout << "The show Method" << endl;
}

int main() {
    thread thread1(show);
    cout << "detach before:" << thread1.joinable() << endl;
    thread1.detach();//脱离主线程的绑定，主线程挂了，子线程不报错，子线程执行完自动退出
    //detech 后，子线程会成为孤儿线程，线程之间将无法通信
    cout << "detach after:" << thread1.joinable() << endl;
    system("rm -rf a.out*");
    return 0;
}

