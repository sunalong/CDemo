//
// Created by sunalong on 16/12/29 17:12.
// Email:466210864@qq.com
//
#include <iostream>

void getSeconds(unsigned long *par);

using namespace std;
int main(){
    unsigned long sec;
    getSeconds(&sec);
    cout<<"Num of seconds:"<<sec<<endl;
    return 0;
}
void getSeconds(unsigned long *par){
    //获取当前的秒数
    *par = time(NULL);
    return;
}

