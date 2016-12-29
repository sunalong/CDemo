//
// Created by sunalong on 16/12/26 11:58.
// Email:466210864@qq.com
//
#include <iostream>
#include <csignal>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
void signalHandler(int signalNum){
    cout<<"Interrupt signal:"<<signalNum<<" received.\n";
    //清理并关闭程序
    exit(signalNum);
}
int main(){
    int i=0;
    //注册信号 SIGINT 和信号处理程序
    signal(SIGINT,signalHandler);
    while(++i){
        cout<<"Going to sleep ..."<<endl;
        if(i==3)
            raise(SIGINT);
        sleep(1);
    }
    return 0;
}