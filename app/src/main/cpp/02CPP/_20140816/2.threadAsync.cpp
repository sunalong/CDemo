//
// Created by sunalong on 17/3/16 10:08.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;
void show(){
    cout<<"Hello cpp,id:"<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::milliseconds(200));
}
int main() {
    //栈上的线程
    thread thread1(show);//根据函数初始化执行
    thread1.join();
    thread thread2(show);
    thread2.join();
    thread thread3(show);
    thread3.join();
//    //线程数组
    thread threadArry[3]{thread(show),thread(show),thread(show)};
//    //堆上线程
    thread *pThread1(new thread(show));
    thread *pThread2(new thread(show));
    thread *pThread3(new thread(show));
//    //线程指针数组
    thread *pThreadArray(new thread[3]{thread(show),thread(show),thread(show)});
    system("rm -rf a.out*");
    return 0;
}

