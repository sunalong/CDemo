//
// Created by sunalong on 17/3/8 22:54.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <assert.h>

using namespace std;
#define DEBUG_ABLE

int main() {
    int num = 100;
//    char num = 'a';
    cout << num << endl;
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __DATE__ << endl;
    cout << __TIME__ << endl;
    cout << __FUNCTION__ << endl;
    string str1 = __FILE__;
    string str2 = "" + __LINE__;
    string str = str1 + str2 + "方法：" + __FUNCTION__ + " 时间：" + __TIME__;
    cout << str << endl;
#ifdef DEBUG_ABLE
    static_assert(sizeof(num) >= 4, str + "长度应该>=4");
#endif
    system("rm -rf a.out*");
    return 0;
}

