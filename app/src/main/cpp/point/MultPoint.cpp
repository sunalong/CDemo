//
// Created by sunalong on 17/2/7 12:33.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
int main(){
    int var;
    int *ptr;
    int **pptr;
    var = 3000;
    ptr = &var;//获取 var 的地址
    pptr = &ptr;//获取 ptr 的地址
    cout<<"var  &var:"<<&var<<"  var:"<<var<<endl;
    cout<<"ptr  &ptr:"<<&ptr<<"  ptr:"<<ptr<<"   *ptr:"<<*ptr<<endl;
    cout<<"pptr &pptr:"<<&pptr<<"    pptr:"<<pptr<<"    *pptr:"<<*pptr<<"   **pptr:"<<**pptr<<endl;
}
