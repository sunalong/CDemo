//
// Created by sunalong on 17/2/27 18:21.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;

/**
 * 缺省函数：缺省值必须在后面，不可以oid func(int a=10 ,int b)
 */
void func(int a, int b = 10) {
    cout << "a：" << a << " b:" << b << endl;
}

/**
 * 函数重载：函数名相同，参数不同
 */
void funcOverLoad(int a) {
    cout << "a=" << a << endl;
}

void funcOverLoad(const char *a) {
    cout << "a=" << a << endl;
}

/**
 * 函数模板
 */
template <class T>
T myAdd(T a,T b){
    return a+b;
}

/**
 * 引用作为函数参数，没有入栈出栈操作，效率高，但有可能会改变变量的值
 */
void funcReferences(int &a,int &b){
    a=20;
    b=10;
    cout<<"引用函数参数改变变量的值：a:"<<a<<" b:"<<b<<endl;
}
/**
 * 指针作为函数参数，没有入栈出栈操作，效率高，但有可能会改变变量的值
 */
void funcPoint(int *a,int *b){
    *a=200;
    *b=100;
    cout<<"指针函数参数改变变量的值：*a:"<<*a<<" *b:"<<*b<<endl;
}
/**
 * 使用常量引用，可避免变量的值被改变
 */
void funcReferenceConst(const int &a,const int &b){
//    a=20;//无法改变值，编译通不过
//    b=10;
    cout<<"引用函数参数改变变量的值：a:"<<a<<" b:"<<b<<endl;
}
/**
 * 使用常量指针，可避免变量的值被改变
 */
void funcPointConst(const int *a,const int *b){
//    *a=200;//无法改变值，编译通不过
//    *b=100;
    cout<<"指针函数参数改变变量的值：*a:"<<*a<<" *b:"<<*b<<endl;
}
int main() {

    func(6);
    func(2, 5);
    funcOverLoad(3);
    funcOverLoad("函数重载");
    cout<<"模板函数："<<myAdd(10,2)<<endl;
    cout<<"模板函数："<<myAdd(13.2,(double)2)<<endl;
    cout<<"模板函数："<<myAdd(13.2,2.9)<<endl<<endl;
    int i1=2;
    int i2=6;
    funcReferences(i1,i2);
    cout<<"使用引入函数后，变量的值：*i1:"<<i1<<" i2:"<<i2<<endl<<endl;
    funcPoint(&i1,&i2);
    cout<<"使用指针函数后，变量的值：*i1:"<<i1<<" i2:"<<i2<<endl<<endl;
    return 0;
}