//
// Created by sunalong on 16/12/27 16:54.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
int main(){
    double* pValue = NULL;//初始化为 null 的指针
    pValue = new double;//为变量请求内存
    *pValue = 29494.85;//在分配的地址存储值
    cout<<"Valueof pValue: *pValue="<<*pValue<<" 指向的内存地址:pValue:"<<pValue<<" 指针位于内存的位置：&pValue:"<<&pValue<<endl;
    delete pValue;//释放内存,不是立即释放
    cout<<"Valueof pValue: *pValue="<<*pValue<<" 指向的内存地址:pValue:"<<pValue<<" 指针位于内存的位置：&pValue:"<<&pValue<<endl;
    return 0;
}

