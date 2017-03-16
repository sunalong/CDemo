//
// Created by sunalong on 17/3/16 10:13.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

int main() {
    thread thread1([]() {
        for (int i = 0; i < 5; ++i) {
            cout << "11111thread id:" << this_thread::get_id() << ",i:" << i << endl;
            this_thread::sleep_for(chrono::milliseconds(10));//让本线程等待10ms
            this_thread::yield();//让 cpu 执行其他空闲的线程
        }
    });
    thread thread2([]() {
        for (int i = 0; i < 5; ++i) {
            this_thread::sleep_for(chrono::milliseconds(10));//让本线程等待10ms
            cout << "22222thread id:" << this_thread::get_id() << ",i:" << i << endl;
            this_thread::yield();//让 cpu 执行其他空闲的线程
        }
    });
    thread1.join();
    thread2.join();
    system("rm -rf a.out*");
    return 0;
}

