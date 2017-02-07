//
// Created by sunalong on 16/12/26 13:53.
// Email:466210864@qq.com
//
#include <iostream>
#include<android/log.h>
#define LOG_TAG "System.out.c"

#define LOGD(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
using namespace std;
int main() {
    char *str = NULL;
    LOGD("android log null str:%s",str);
    cout << "C++ null str:" << str << endl;
    cout << "after null"<<endl;
    return 0;
}
