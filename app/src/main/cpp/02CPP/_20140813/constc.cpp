//
// Created by sunalong on 17/3/5 15:19.
// Email:466210864@qq.com
//

#include <iostream>

void constTest1();

using namespace std;
int main(){
    int a=10;
    const int b = 20;
    int const  *p1 = &a;
    const int *p2(&b);//p1 p2 指向常量的指针变量，指向的数据不可以被赋值，但 p1 p2 可以改变指向
    cout<<"change before指向常量的指针变量，指向的数据不可以被赋值，但可以改变指向:*p2:"<<*p2<<endl;
    p1 = &b;//但 p1 p2 可以改变指向
    p2 = &a;//但 p1 p2 可以改变指向
//    *p1 = 3;//p1 p2 指向常量的指针变量，指向的数据不可以被赋值，
//    *p2 = 6;//p1 p2 指向常量的指针变量，指向的数据不可以被赋值，
    cout<<"change after 指向常量的指针变量，指向的数据不可以被赋值，但可以改变指向:*p2:"<<*p2<<endl;

    int *const p3(&a);//指向变量的常量指针，指向不可改变，但值可以改变
    int *const p4((int *const) &b);
    cout<<"change before指向变量的常量指针，指向不可改变，但值可以改变:*p3:"<<*p3<<" a:"<<a<<endl;
    cout<<"change before指向变量的常量指针，指向不可改变，但值可以改变:*p4:"<<*p4<<" a:"<<a<<endl;
//    p3 = &b;//指向变量的常量指针，指向不可改变
    *p3 = 213;//指向变量的常量指针，指向不可改变，但值可以改变
    *p4 = 233;//指向变量的常量指针，指向不可改变，但值可以改变
    cout<<"change after 指向变量的常量指针，指向不可改变，但值可以改变:*p3:"<<*p3<<" a:"<<a<<endl;
    cout<<"change after 指向变量的常量指针，指向不可改变，但值可以改变:*p4:"<<*p4<<" a:"<<a<<endl;

    const int *const p5(&a);//指向常量的常量指针
    const int *const p6(&b);
//    constTest1();
    return 0;
}

void constTest1() {
    const int num = 5;
    int a[num];//C++ 中的 const 内部可以用初始化数组
    int i = 0;
    for(auto data:a){
        data=i++;
        cout<<"a["<<i<<"]="<<data<<endl;
    }
//    int *p = &num;//与 c不同，在c++中不可将一个指针指向一个 const 变量
    //cannot initialize a variable of type 'int *' with an rvalue of type 'const int *'
    int *p = (int *) &num;
    *p = 7;
    cout<<"1.经由指针改变后，const num 的值："<<*p<<endl;
}