//
// Created by sunalong on 17/3/16 10:09.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;
void show(const char* str,const int id){
    cout<<"id:"<<id+1<<" : "<<str<<endl;
}
int main() {
    thread thread1(show,"AAAA",0);
    this_thread::sleep_for(chrono::milliseconds(20));
    thread thread2(show,"BBB",12);
    this_thread::sleep_for(chrono::milliseconds(20));
    thread thread3(show,"CCCC",28);
//    thread1.join();
//    thread2.join();
//    thread3.join();
//    thread1.detach();
//    thread2.detach();
//    thread3.detach();
    system("rm -rf a.out*");
    return 0;
}

//    ~/GitHub/CDemo/app/src/main/cpp/02CPP/_20140816 on  master! ⌚ 12:19:22
//    $ g++ -g -Wall -std=c++11 3.multThread.cpp
//
//    ~/GitHub/CDemo/app/src/main/cpp/02CPP/_20140816 on  master! ⌚ 12:19:40
//    $ a.out
//     id:1 : AAAA
//     id:13 : BBB
//     id:29 : CCCC
//     libc++abi.dylib: terminating
//     [1]    4781 abort      a.out
//将子线程调用 join 即可无异常 join 是让当前主线程等待所有的子线程执行完，才能退出。
//将子线程调用 detach也可无异常，detach 让子线程脱离主线程的绑定，主线程挂了，子线程不报错，子线程执行完自动退出
