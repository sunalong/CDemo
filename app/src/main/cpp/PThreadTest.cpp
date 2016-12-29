//
// Created by sunalong on 16/12/26 15:29.
// Email:466210864@qq.com
//
#include<iostream>
using namespace std;
#define NUM_THREADS 5
void* say_hello(void* args){
    cout<<"Hello Runoob!"<<endl;
}

int main(){
    pthread_t tids[NUM_THREADS];
    for(int i=0;i<NUM_THREADS;i++){
        //创建的线程 id,线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i],NULL,say_hello,NULL);
        cout<<i<<" pthread_create code:"<<ret<<endl;
    }
    //等所有线程退出后，进程结束
    pthread_exit(NULL);
    return 0;
}