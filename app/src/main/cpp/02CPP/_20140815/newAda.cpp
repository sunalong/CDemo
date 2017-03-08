//
// Created by sunalong on 17/3/8 12:02.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <new>
const int buf(512);//限定一个常量整数512
int N(5);//数组的长度
char buffer[buf] = {0};//静态区

using namespace std;
/**
 * p1,p3,p5 作为指针变量在栈区，存储的地址指向堆区
 * 需要手动释放内存
 *
 * p2,p4,p6 作为指针变量在栈区，存储的地址在静态区，缓冲区
 * 自动释放内存，用于分配用完了就不会再用的数据
 * 避免内存泄漏，自动释放内存，牺牲了内存访问独立性
 */
int main() {
    double *p1 ,*p2;
    cout<<endl;
    p1 = new double[N];//分配内存，N 个元素的大小
    p2 = new (buffer)double[N];//指定区域分配内存
    for(int i=0;i<N;i++){
        p1[i] = p2[i] = i+10.8;//对数组初始化
        cout<<"p1=="<<&p1[i]<<" "<<p1[i];
        cout<<"  p2=="<<&p2[i]<<" "<<p2[i]<<endl;
    }
    double *p3,*p4;
    cout<<endl;
    p3  = new double[N];
    p4 = new (buffer)double[N];//指定区域分配内存
    for(int i=0;i<N;i++){
//        p3[i] = p4[i] = i+10.8;//对数组初始化
        p3[i] = i+10.8;//对数组初始化
        cout<<"p3=="<<&p3[i]<<" "<<p3[i];
        cout<<"  p4=="<<&p4[i]<<" "<<p4[i]<<endl;
    }

    double *p5,*p6;
    cout<<endl;
    p5  = new double[N];
    p6 = new (buffer)double[N];//指定区域分配内存
    for(int i=0;i<N;i++){
//        p5[i] = p6[i] = i+10.8;//对数组初始化
        p5[i] = i+10.8;//对数组初始化
        cout<<"p5=="<<&p5[i]<<" "<<p5[i];
        cout<<"  p6=="<<&p6[i]<<" "<<p6[i]<<endl;
    }
    system("rm -rf a.out*");
    return 0;
}

