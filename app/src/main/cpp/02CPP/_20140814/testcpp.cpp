//
// Created by sunalong on 17/3/6 23:32.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;

int num;
//int num;//C++全局变量没有声明与定义的差别，但 C语言有，所以 C 语言可以有多行 int num;
int main() {
    int a = 3;
    int b = 4;
    (a = 3) = 4;//C++检测到右值在内存有实体，自动转换为左值;
                //C语言不会把右值转换为左值
    (a > b ? a : b) = 134;
    cout << "a=" << a << "  b=" << b << endl;//a=4  b=134
    (++a)++;
//    ++b++;//error: expression is not assignable
//    (a+1)++;//error: expression is not assignable
    cout << "a=" << a << "  b=" << b << endl;//a=6  b=134

    register int num(20);//只有内存中的变量有地址，cpu 和寄存器中的变量是没有地址的，
    //register C++编译器做了优化，检测到取地址，就不会放到寄存器
    //register 在 C++中可以取地址，但在C语言中 register 修饰的变量不可取地址
    cout<<"num:"<<num<<" &num:"<<&num<<endl;//num:20 &num:0x7fff501ae9f0
    return 0;
}
