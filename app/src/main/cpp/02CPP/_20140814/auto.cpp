//
// Created by sunalong on 17/3/6 17:01.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;

int main() {
    int i = 10;
    double db = 10.9;
    double *pdb = &db;
    int *pi = &i;
    auto num = pdb;
    auto num2 = db;
    cout << "int  i 的类型：" << typeid(i).name() << endl;
    cout << "double db 的类型：" << typeid(num).name() << endl;
    cout << "double *pdb 的类型：" << typeid(*pdb).name() << endl;
    cout << "double pdb 的类型：" << typeid(pdb).name() << endl;
    cout << "double &pdb 的类型：" << typeid(&pdb).name() << " &pdb addr:" << &pdb << " sizeof(&pdb):" << sizeof(&pdb) << endl;
    cout << "double *pi 的类型：" << typeid(*pi).name() << endl;
    cout << "double pi 的类型：" << typeid(pi).name() << endl;
    cout << "double &pi 的类型：" << typeid(&pi).name() << "  &pi addr:" << &pi << " sizeof(&pi):" << sizeof(&pi) << endl;
    cout << "auto num 的类型：" << typeid(num).name() << endl;
    cout << "typeid(typeid(*pi)).name():" << typeid(typeid(*pi)).name() << endl;
    cout << "typeid(typeid(*pi).name()).name():" << typeid(typeid(*pi).name()).name() << endl;
    decltype(db) numA(10.9);
    cout << "typeid(decltype(db)).name():" << typeid(decltype(db)).name() << endl;
    cout << "decltype(db) numA(10.9),sizeof(numA):" << sizeof(numA) << endl;
//    int  i 的类型：i
//    double db 的类型：Pd
//    double *pdb 的类型：d
//    double pdb 的类型：Pd
//    double &pdb 的类型：PPd
//    double *pi 的类型：i
//    double pi 的类型：Pi
//    double &pi 的类型：PPi
//    auto num 的类型：Pd
    return 0;
}
