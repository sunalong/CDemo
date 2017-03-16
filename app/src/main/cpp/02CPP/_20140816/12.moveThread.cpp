//
// Created by sunalong on 17/3/16 10:15.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

int main() {
    thread thread1([]() {
        cout << "thread1 无参的 lambda函数来构造对象" << endl;
    });
    cout << "thread1 id:" << thread1.get_id() << endl;
    thread thread2 = move(thread1);
    cout << "thread2 id:" << thread2.get_id() << endl;
//    线程2 可通过 move 来移动线程1 来获取线程1 的全部属性，此时线程1 被销毁
//    thread1.join();// terminating with uncaught exception of type std::__1::system_error: thread::join failed: No such process
    thread2.join();
    system("rm -rf a.out*");
    return 0;
}

