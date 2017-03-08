//
// Created by sunalong on 17/3/8 14:25.
// Email:466210864@qq.add
//
#include<iostream>
#include<stdlib.h>

using namespace std;

//template <class T>//与 typename 有什么不同？
template<typename T>
void add(T &arg) {
    arg++;
    cout << "add: arg:" << arg << "   &arg:" << &arg << endl;
}

template<typename T>
void add2(T arg) {
    arg += 2;
    cout << "add2: arg:" << arg << "  &arg:" << &arg << endl;
}

int main() {
    int count = 10;
    int rcount = count;
    add(count);
    cout << "main count:" << count << "   &count:" << &count << endl;
    add(rcount);
    cout << "main rcount:" << rcount << "     &rcount:" << &rcount << endl << endl;

    add2(count);
    cout << "main count:" << count << "   &count:" << &count << endl;
    add2(rcount);
    cout << "main rcount:" << rcount << "     &rcount:" << &rcount << endl;
    add2(std::ref(count));//c++11 的语法 ，g++ -g -Wall -std=c++11 refWrapper.cpp
    cout << "main count:" << count << "   &count:" << &count << endl;

    system("rm -rf a.out*");
    return 0;
}

