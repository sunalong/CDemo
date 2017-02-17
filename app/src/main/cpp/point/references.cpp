//
// Created by sunalong on 17/2/7 14:51.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;

int main() {
    int i = 5;//声明简单的变量
    int &iRe = i;//&读作引用，rRe 是一个初始化为 i 的整型引用
    int *ptr;
    ptr = &i;//这两句等同于 int *ptr = &i;
//类比指针赋值可知,引用的赋值相当于：
//int &iRe;
//iRe = i;
//所以求 i 的引用的值就是 iRe
//求 i 的地址就是&iRe;
//但引用必须在创建时赋值，所以只能为 int &iRe = i;
    cout << "i:" << i << "   &i:" << &i << endl;
    cout << "iRe:" << iRe << "    &iRe:" << &iRe << endl;
    cout << "*ptr:" << *ptr << "    ptr:" << ptr << "    &ptr:" << &ptr << endl;
    return 0;
}
