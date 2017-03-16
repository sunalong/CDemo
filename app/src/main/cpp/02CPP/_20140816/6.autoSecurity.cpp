//
// Created by sunalong on 17/3/16 10:12.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;
//const int N=100*1000*1000;
const int N = 100 * 1000;
int num1 = 0;
int num2 = 0;
atomic_int atomicIntNum{0};//不会发生线程冲突，线程安全
int num4 = 0;

void test1();

void test2();

void test3();

void test4();

void run1() {
    for (int i = 0; i < N; i++) {
        num1++;
    }
}

mutex m;

void run2() {
    for (int i = 0; i < N; ++i) {
        m.lock();
        num2++;
        m.unlock();
    }
}

void run3(){
    for (int i = 0; i < N; ++i) {
        atomicIntNum++;
    }
}

void run4() {
    for (int i = 0; i < N; i++) {
        num4++;
    }
}
int main() {

//    test1();
//    test2();
//    test3();
    test4();

    system("rm -rf a.out*");
    return 0;
}
/**
 * 两线程在构造之前分别 join 后速度快，运行结果正确：
       num3=200000,用时：562ms
 */
void test4() {
    clock_t start = clock();
    thread thread1(run4);
    thread1.join();
    thread thread2(run4);
    thread2.join();
    clock_t end = clock();
    cout << "num3=" << num4 << ",用时：" << end - start << "ms" << endl;
}

/**
 * 通过原子变量后运算结果正确，计算速度一般
        num3=200000,用时：8316ms
 */
void test3() {
    clock_t start = clock();
    thread thread1(run3);
    thread thread2(run3);
    thread1.join();
    thread2.join();
    clock_t end = clock();
    cout << "num3=" << atomicIntNum << ",用时：" << end - start << "ms" << endl;
}

/**
 * 通过互斥量后运算结果正确，但是计算速度很慢，原因主要是互斥量加解锁需要时间
        num2=200000,用时：619187ms
 */
void test2() {
    clock_t start = clock();
    thread thread1(run2);
    thread thread2(run2);
    thread1.join();
    thread2.join();
    clock_t end = clock();
    cout << "num2=" << num2 << ",用时：" << end - start << "ms" << endl;
}

/**
 * 此时的结果不正确，因为多线程没有互斥
        num1=100416,用时：2084ms
 */
void test1() {
    clock_t start = clock();
    thread thread1(run1);
    thread thread2(run1);
    thread1.join();
    thread2.join();
    clock_t end = clock();
    cout << "num1=" << num1 << ",用时：" << end - start << "ms" << endl;
}

