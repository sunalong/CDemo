//
// Created by sunalong on 17/3/8 21:27.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <vector>
#include <thread>

void threadTest1();

void threadVectorTest();

using namespace std;
//using namespace std::this_thread;

//void msg(){
//    MessageBoxA(0,"内容","标题",0);
//}
void msgA(int num) {
    cout << "get_id():" << this_thread::get_id() << " num:" << num << endl;
}

void msg() {
    cout << "get_id():" << this_thread::get_id() << " no num" << endl;
}

int main() {
    auto n = thread::hardware_concurrency();
    cout << "the num of Thread:" << n << endl;//8
    cout << "thread id:" << this_thread::get_id() << endl;
//    threadTest1();
//    threadVectorTest();

    vector<thread *> threadVector;
    for (int i = 0; i < 10; ++i) {
        threadVector.push_back(new thread(msgA,i));//创建线程 c++11语法
        // $ g++ -g -Wall -std=c++11 threadTest.cpp
    }
    for (auto th:threadVector){
        th->join();
    }

    system("rm -rf a.out*");
    return 0;
}

void threadVectorTest() {
    vector<thread *> threadVector;
    for (int i = 0; i < 10; ++i) {
        threadVector.push_back(new thread(msg));//创建线程
    }
    for (auto th:threadVector){
        th->join();
    }
}

void threadTest1() {
    thread thread1(msg);
    thread thread2(msg);
    thread1.join();//开始执行
    thread2.join();
}

