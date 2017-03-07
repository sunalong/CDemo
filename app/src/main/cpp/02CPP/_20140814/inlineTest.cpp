//
// Created by sunalong on 17/3/7 12:23.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
#define GETX3(N) N*N*N
//函数
inline int getX3(int x){
    return x*x*x;
}
/**
 * inline在模板中使用
 */
template <class T>
inline T getX2(T x){
    return x*x;
}
int main(){
    cout<<"getX3(1+2):"<<getX3(1+2)<<endl;//7
    cout<<"getX3((1+2)):"<<getX3((1+2))<<endl;//27
    cout<<"getX3((1.0+2)):"<<getX3((1.0+2))<<endl;//27
    //define 虽然可以实现泛型，但最大的缺点是没办法保证类型安全
    cout<<"GETX3(1+2):"<<GETX3(1+2)<<endl;//7
    cout<<"GETX3((1+2)):"<<GETX3((1+2))<<endl;//27
    cout<<"GETX3((1.0+2)):"<<GETX3((1.0+2))<<endl;//27
    return 0;
}
