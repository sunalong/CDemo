//
// Created by sunalong on 17/3/16 10:14.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

int main() {
    thread thread1([](){
        this_thread::sleep_for(chrono::milliseconds(20));
        this_thread::yield();
        cout<<"thread1 使用无参的lambda函数来构造线程"<<endl;
    });
    thread thread2([](){
        cout<<"thread2 使用无参的lambda函数来构造线程"<<endl;
        this_thread::sleep_for(chrono::milliseconds(20));
        this_thread::yield();
    });
    cout<<"before swap:"<<endl;
    cout<<"thread1 id:"<<thread1.get_id()<<endl;
    cout<<"thread2 id:"<<thread2.get_id()<<endl;

    this_thread::sleep_for(chrono::milliseconds(50));
    this_thread::yield();
    swap(thread1,thread2);//线程交换
    cout<<"after swap:"<<endl;
    cout<<"thread1 id:"<<thread1.get_id()<<endl;
    cout<<"thread2 id:"<<thread2.get_id()<<endl;
    thread1.join();
    thread2.join();
//    thread1.detach();
//    thread2.detach();
    system("rm -rf a.out*");
    return 0;
}

