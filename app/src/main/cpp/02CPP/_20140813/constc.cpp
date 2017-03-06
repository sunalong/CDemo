//
// Created by sunalong on 17/3/5 15:19.
// Email:466210864@qq.com
//

#include <iostream>

void constTest1();

void referenceAndPoint();

void referencePointerExplain();

using namespace std;

int main() {
    referencePointerExplain();
    //    referenceAndPoint();
    //    constTest1();
    return 0;
}

void referencePointerExplain() {
    const int num = 12;//C++保证常量不被修改
    int *p;
//    p = (int *) &num;
    p = const_cast<int *>(&num);//与上一句相同
    *p = 57;//内存中的值被修改成功
    /**
     * 虽然真实的内存中的值已经被修改了，
     * 但引用这个常量是直接从寄存器中的常量表中读取的，
     * 没有从内存读取，所以输出不变
     */
    cout << "const int num:" << num << "  num addr:" << &num << endl;//输出为12

    /**
     * 真实内存中的值被修改了，
     * 引用指针时，需要指针的值需要读取指针指向的内存地址，
     * 所以输出变化
     */
    cout << "       int *p:" << *p << "         p:" << p << " &p:" << &p << endl;// 输出为57
}

void referenceAndPoint() {
    int a = 10;
    const int b = 20;
    int const *p1 = &a;
    const int *p2(&b);//p1 p2 指向常量的指针变量，指向的数据不可以被赋值，但 p1 p2 可以改变指向
    cout << "change before指向常量的指针变量，指向的数据不可以被赋值，但可以改变指向:*p2:" << *p2 << endl;
    p1 = &b;//但 p1 p2 可以改变指向
    p2 = &a;//但 p1 p2 可以改变指向
//    *p1 = 3;//p1 p2 指向常量的指针变量，指向的数据不可以被赋值，
//    *p2 = 6;//p1 p2 指向常量的指针变量，指向的数据不可以被赋值，
    cout << "change after 指向常量的指针变量，指向的数据不可以被赋值，但可以改变指向:*p2:" << *p2 << endl;

    int *const p3(&a);//指向变量的常量指针，指向不可改变，但值可以改变
    int *const p4((int *const) &b);
    cout << "change before指向变量的常量指针，指向不可改变，但值可以改变:*p3:" << *p3 << " a:" << a << endl;
    cout << "change before指向变量的常量指针，指向不可改变，但值可以改变:*p4:" << *p4 << " a:" << a << endl;
//    p3 = &b;//指向变量的常量指针，指向不可改变
    *p3 = 213;//指向变量的常量指针，指向不可改变，但值可以改变
    *p4 = 233;//指向变量的常量指针，指向不可改变，但值可以改变
    cout << "change after 指向变量的常量指针，指向不可改变，但值可以改变:*p3:" << *p3 << " a:" << a << endl;
    cout << "change after 指向变量的常量指针，指向不可改变，但值可以改变:*p4:" << *p4 << " a:" << a << endl;

    const int *const p5(&a);//指向常量的常量指针
    const int *const p6(&b);
}

void constTest1() {
    const int num = 5;
    int a[num];//C++ 中的 const 内部可以用初始化数组
    int i = 0;
    for (auto data:a) {
        data = i++;
        cout << "a[" << i << "]=" << data << endl;
    }
//    int *p = &num;//与 c不同，在c++中不可将一个指针指向一个 const 变量
    //cannot initialize a variable of type 'int *' with an rvalue of type 'const int *'
    int *p = (int *) &num;
    *p = 7;
    cout << "1.经由指针改变后，const num 的值：" << *p << endl;
}