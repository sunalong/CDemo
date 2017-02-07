//
// Created by sunalong on 17/2/7 12:43.
// Email:466210864@qq.com
//
#include <iostream>
#include <ctime>
using namespace std;
void getSeconds(unsigned long *par);
int main(){
    unsigned long sec;
    getSeconds(&sec);//long *par = &sec
    //把 long sec 的地址传给函数，函数内部为这个地址指向的内存赋值，所以 sec 数值变化
    cout<<"Number of seconds:"<<sec<<endl;
    return 0;
}
void getSeconds(unsigned long *par){
    //获取当前秒数
    *par = time(NULL);
    return;
}