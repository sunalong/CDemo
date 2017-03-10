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

int main() {
    void *pNULL = NULL;
    void *pNullptr = nullptr;
    cout << "go(pNULL):" << go(pNULL) << endl;
    cout << "go(pNullptr):" << go(pNullptr) << endl;
//    go (NULL);//语义不明，两个函数都可被调用
    cout << "NULL:" << NULL << endl;
    cout << "go(nullptr):" << go(nullptr) << endl;
    system("rm -rf a.out*");
    return 0;
}

