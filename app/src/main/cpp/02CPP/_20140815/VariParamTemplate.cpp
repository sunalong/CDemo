//
// Created by sunalong on 17/3/7 20:10.
// Email:466210864@qq.com
//
#include<iostream>

using namespace std;

void showAll() {//最后结束递归
    cout << endl << "void showAll() done" << endl << endl;
};

template<typename T, typename ... Args>
void showAll(const T &valve, const Args &...args) {
    cout << valve << "  ";
    showAll(args...);//继续传递
};

int main() {
    int num = 5;
    float fl = 4.5;
    double db = 10.8;
    char ch = 'R';
    char *str = "fuckChar*str";
    cout << "showAll(num):" << endl;
    showAll(num);
    cout << "showAll(num,fl,db,ch,str):" << endl;
    showAll(num, fl, db, ch, str);
    return 0;
}

