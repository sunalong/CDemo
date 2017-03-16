//
// Created by sunalong on 17/3/16 10:10.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>
#include <array>

using namespace std;

void show() {
    cout << "cpp thread join" << endl;
}

int main() {
    array<thread, 3> myThreadArray = {thread(show), thread(show), thread(show)};
    for (int i = 0; i < myThreadArray.size(); i++) {
        cout << "i=" << i << " " << myThreadArray[i].joinable() << endl;//判断线程是否可以 join
        myThreadArray[i].join();//join 的作用：让当前主线程等待子线程执行完成再退出
    }
    cout << "main done" << endl;
    system("rm -rf a.out*");
    return 0;
}

