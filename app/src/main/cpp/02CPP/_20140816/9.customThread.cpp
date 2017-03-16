//
// Created by sunalong on 17/3/16 10:13.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>

using namespace std;

class MyThread : public thread {//继承 thread
public:
    MyThread() : thread() {
        cout << "MyThread 不使用函数的构造函数" << endl;
    }

    template<typename T, typename ...Args>
    MyThread(T &&func, Args &&...args) : thread(forward<T>(func), forward<Args>(args)...) {
        cout << "MyThread 使用函数的构造函数" << endl;
    }

    void showcmd(const char *str) {
        system(str);
    }
};

int main() {
    MyThread myThread1;
    myThread1.showcmd("man -version");
    MyThread myThread2([]() {
        cout << "使用无参的函数来构造线程" << endl;
    });
    myThread2.showcmd("adb devices");
    myThread2.join();
    MyThread myThread3([](const char *str) {
        cout << "使用有参的函数来构造线程：" << str << endl;
    }, "This is MyThread");
    myThread3.showcmd("java -version");
    myThread3.join();
    system("rm -rf a.out*");
    return 0;
}

