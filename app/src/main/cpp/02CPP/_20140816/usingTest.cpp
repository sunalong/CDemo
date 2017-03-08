//
// Created by sunalong on 17/3/8 16:36.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
template<class T> using ptr = T *;//模板的简写

int add(int a, int b) {
    return a + b;
}

typedef int(*ADD)(int a, int b);

using FUNC = int (*)(int a, int b);//别名
using co = std::ios_base::fmtflags;//using 只可以用于简写数据类型

int main() {
    ADD p = add;
    cout << "ADD p:" << p(1, 2) << endl;
    int (*raw)(int a, int b) = add;
    cout << "raw:" << raw(6, 2) << endl;
    FUNC func = add;
    cout << "func:" << func(1, 2) << endl;
    ptr<int> pInt(new int(4));
    ptr<double> pDB(new double(4.8));

    ptr<char> pStr (new char('A'));
    ptr<char> pStr1= new char('B');
    char* cA2 =new char('C');
    ptr<char> pStr2= cA2;
    string str = "aaaaa";
    char ** chP;
    ptr<char*> ptrChar = chP;
    ptr<string> pSt3=new string("alalaa");
    cout << "myspace::ptr pInt *pInt:" << *pInt << " pInt:" << pInt << endl;
    cout << "myspace::ptr pInt *pDB:" << *pDB << " pDB:" << pDB << endl;
    cout << "myspace::ptr pInt *pInt:" << *pStr << " pInt:" << pStr << endl;
    cout << "myspace::ptr pStr1 *pStr1:" << *pStr1 << " pStr1:" << pStr1 << endl;
    cout << "myspace::ptr pStr2 *pStr2:" << *pStr2 << " pStr2:" << pStr2 << endl;
    cout << "myspace::ptr pStr2 *pSt3:" << *pSt3 << " pStr2:" << pSt3 << endl;
    system("rm -rf a.out*");
    return 0;
}

