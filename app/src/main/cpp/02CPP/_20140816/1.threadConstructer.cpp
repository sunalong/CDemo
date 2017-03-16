//
// Created by sunalong on 17/3/16 10:07.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>
#include <chrono>

using namespace std;
void fun1(int n){
    cout<<"Thread "<<n<<",id="<<this_thread::get_id()<<" executing"<<endl;
    n+=10;
    this_thread::sleep_for(chrono::milliseconds(10));
}
void fun2(int &n){
    cout<<"Thread "<<n<<",id="<<this_thread::get_id()<<" executing\n";
    n+=20;
    this_thread::sleep_for(chrono::milliseconds(10));
}
int main() {
    int n=0;
    cout<<"main thread id:"<<this_thread::get_id()<<endl;
    thread thread1;
    cout<<"thread1,id:"<<thread1.get_id()<<endl;
    thread thread2(fun1,n+1);//按值传递
    cout<<"thread2,id:"<<thread2.get_id()<<endl;
    thread2.join();
    cout<<"main n="<<n<<endl;
    n=10;
    thread thread3(fun2,ref(n));//引用
    cout<<"thread3,id:"<<thread3.get_id()<<endl;
    thread thread4(move(thread3));//thread4 执行 thread3,thread3不是 thread
    cout<<"thread4,id:"<<thread4.get_id()<<endl;
    thread4.join();
    cout<<"main4 n="<<n<<endl;
    system("rm -rf a.out*");
    return 0;
}

