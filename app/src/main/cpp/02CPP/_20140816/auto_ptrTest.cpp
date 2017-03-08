//
// Created by sunalong on 17/3/8 20:44.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <memory>

void auto_ptrTest();

void uniquePtrTest();

using namespace std;

int main() {
//    auto_ptrTest();
    uniquePtrTest();
    system("rm -rf a.out*");
    return 0;
}
/**
 * C++新型指针
 */
void uniquePtrTest() {
    for (int i = 0; i < 10 * 1000 * 1000 * 1000; i++) {
        //新型指针，新型的数组
        unique_ptr<double> pdb(new double);//可直接使用 new为其初始化
    }
}
/**
 * c++89 的智能指针
 */
void auto_ptrTest() {
    for (int i = 0; i < 10 * 1000 * 1000 * 1000; ++i) {
        double *p = new double;//为指针分配内存
        //创建智能指针管理指针指向内存
        auto_ptr<double> autop(p);//不加这行智能指针，程序会不断的分配内存，由于没有 delete,会造成内存泄漏
//        auto_ptr<double> autop = new double;//c++89的智能指针是寄存器指针，必须依赖原来的指针
    }
}

