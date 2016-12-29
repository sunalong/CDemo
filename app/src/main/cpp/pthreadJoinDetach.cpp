//
// Created by sunalong on 16/12/26 17:02.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;
#define NUM_THREADS 5

void *wait(void *t) {
    int i;
    long tid;
    tid = (long) t;
    cout << "sleep in thread,id:" << tid << " ...exiting" << endl << endl;
    pthread_exit(NULL);
}

int main() {
    int rc;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;
    //初始化并设置线程为可连接的(joinable)
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], &attr, wait, (void *) i);
        cout << "i=" << i << " create thread retCode:" << rc << endl;
    }

    //删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);
        cout << i << " join retCode:" << rc << " status:" << status << endl;
    }
    cout << "Main program exiting." << endl;
    pthread_exit(NULL);
}
