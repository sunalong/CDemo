//
// Created by sunalong on 17/3/10 09:46.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

char *go(int num) {
    return "void go(int num)";
}

char *go(void *p) {
    return "void go(void *p)";
}

char *goNum(int num) {
    return "void goNum(int num)";
}

char *goChar(void *p) {
    return "void goChar(void *p)";
}

int main() {
    void *pNULL = NULL;//NULL与nullptr的相互转换
    void *pNullptr = nullptr;
    cout << "go(pNULL):" << go(pNULL) << endl;
    cout << "go(pNullptr):" << go(pNullptr) << endl;
    cout << "NULL:" << NULL << endl;
    cout << "go(nullptr):" << go(nullptr) << endl;
    cout << "goNum(NULL):" << goNum(NULL) << endl;
    cout << "goChar(NULL):" << goChar(NULL) << endl;
    //下句语义不明，编译通不过，两个函数【 go(int num) 和go(void *p) 】都可被调用
//    cout << "go(NULL):" << go(NULL) << endl;
    system("rm -rf a.out*");
    return 0;
}

