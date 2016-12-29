//
// Created by sunalong on 16/12/26 16:31.
// Email:466210864@qq.com
//
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
#define NUM_THREADS 5
struct thread_data{
    int thread_id;
    char* message;
};

void* printHello(void *threadArg){
    struct thread_data *my_data;
    my_data = (thread_data *) threadArg;
    cout<<"Thread ID:"<<my_data->thread_id<<"  Thread Message:"<<my_data->message<<endl<<endl;
}
int main(){
    pthread_t threads[NUM_THREADS];
    struct  thread_data td[NUM_THREADS];
    int rc;
    for(int i=0;i<NUM_THREADS;i++){
        cout<<"main() create thread:"<<i<<endl;
        sleep(1);
        td[i].thread_id = i;
//        td[i].message = (char *) ("This is message" + i);
        td[i].message = "This is message";
        rc = pthread_create(&threads[i],NULL,printHello,&td[i]);
        if(rc){
            cout<<"error: unable to create thread,rc:"<<rc<<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}