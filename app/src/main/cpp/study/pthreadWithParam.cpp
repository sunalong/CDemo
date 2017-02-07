//
// Created by sunalong on 16/12/26 15:46.
// Email:466210864@qq.com
//
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
#define NUM_THREADS 5

void *printHello(void *threadId) {
    int tid = *((int *) threadId);
    cout << "Hello 线程 ID:" << tid <<" 地址："<<threadId<<endl<<endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int indexs[NUM_THREADS];
    int rc;
    for (int i = 0; i < NUM_THREADS; i++) {
        indexs[i] = i;
        //传入的时候必须强制转换为 void* 类型，即无类型指针
        cout << "main()创建线程：" << i << " &threads[i]:" << &threads[i] << " &(indexs[i]:" << &(indexs[i]) << endl;
        rc = pthread_create(&threads[i], NULL, printHello, (void *) &(indexs[i]));
        sleep(1);
        if (rc) {
            cout << "Error rc:" << rc << endl;
            exit(-1);
        }
    }
    if (0) {
        cout << "if (0)" << endl;
    }
    if (1) {
        cout << "if(1)" << endl;
    }
    if (2) {
        cout << "if(2)" << endl;
    }
    pthread_exit(NULL);
    return 0;
}
