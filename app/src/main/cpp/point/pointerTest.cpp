//
// Created by sunalong on 16/12/22 17:15.
// Email:466210864@qq.com
//

#include <iostream>
using namespace std;

int main() {
    int lvar = 20;
    double dbVar = 20;
    cout << "整型变量 lvar 变量的地址：" << &lvar << endl;
    cout << "整形变量 lvar 变量的值：" << lvar << endl;
    int *ip = &lvar;//定义int 类型的指针变量 ip 并为其赋值
    double *dp;//定义double 类型的指针变量 dp，
    dp = &dbVar;//为指针变量 dp 赋值
    *dp = 20;
    *dp = dbVar;
    cout << "int类型的指针变量 ip变量中存储的地址：" << ip << endl;
    cout << "int类型的指针变量 ip变量中存储的地址指向的值：" << *ip << endl;

    int *ipNull;
    ipNull = NULL;
    if (ipNull)
        cout << "int类型的指针变量 ipNull不是空指针" << endl;
    if (!ipNull)
        cout << "int类型的指针变量 ipNull是空指针" << endl;
    cout << "int类型的指针变量 ipNull变量中存储的地址：" << ipNull << endl;
    cout << "int类型的指针变量 ipNull变量中存储的地址指向的值：" << *ipNull << endl;
    return 0;
}

