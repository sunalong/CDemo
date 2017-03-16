//
// Created by sunalong on 17/3/16 10:12.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;
int num = 0;

void lambdaThread();

void testBinFa();

void runFun(const char *str) {
    for (int i = 0; i < 100; i++) {
//        cout << "thread id:" << this_thread::get_id() <<",i="<<i<< " num:" <<(num++) <<" "<<str<< endl;
        cout << str << endl;
    }
    cout << "thread id:" << this_thread::get_id() << str << endl;
}

int main() {
//    lambdaThread();
    testBinFa();
    return 0;
}

/**
    线程1 先 调用方法join 后再构造线程2的作用：
        当 thread1 执行完毕后才执行 thread2,并不是两线程同时在运行，
    若两线程依次构造，然后再依次调用方法join的作用：
        两线程并发执行，
 */
void testBinFa() {
    thread thread1(runFun, "------");
    thread thread2(runFun, "***********");
    cout << "main-----" << endl;
    thread1.join();
    thread2.join();
}

void lambdaThread() {
    auto fun = [](const char *str) {
        for (int i = 0; i < 1000; i++)
            cout << "thread id:" << this_thread::get_id() << ",i=" << i << " str:" << str << endl;
    };
    thread thread1(fun, "lambda 与线程");
    thread1.join();
    thread thread2(fun, "hello lambda");
    thread2.join();
    system("rm -rf a.out*");
}

