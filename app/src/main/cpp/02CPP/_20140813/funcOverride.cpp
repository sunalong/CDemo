//
// Created by sunalong on 17/3/4 15:17.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
void go(int a){
    cout<<"go(int a):a:"<<a<<endl;
}
void go(double a){
    cout<<"go(double a):a:"<<a<<endl;
}
void go(double a,int b){
    cout<<"go(double a,int b):a:"<<a<<" b:"<<b<<endl;
}
void go(int a, double b){
    cout<<"go(int a, double b):a:"<<a<<" b:"<<b<<endl;
}
int main(){
    void(*pgo1)(int a) = go;
    void (*pgo2)(double a) = go;
    void (*pgo3)(double a,int b) = go;
    void (*pgo4)(int a, double b) = go;
    printf("%p\n",pgo1);
    cout<<"pgo1:"<<&pgo1<<endl;
    cout<<"pgo1:"<<*pgo1<<endl;

    printf("%p\n",pgo2);
    cout<<"pgo2:"<<&pgo2<<endl;

    printf("%p\n",pgo3);
    cout<<"pgo3:"<<&pgo3<<endl;

    printf("%p\n",pgo4);
    cout<<"pgo4:"<<&pgo4<<endl;
    return 0;
}