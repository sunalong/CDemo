//
// Created by sunalong on 17/3/13 18:46.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
class Fu{
private:
    int id;
    char name[20];
    static int num;
public:
    Fu(){
        id = 23;
        cout<<"Fu 构造函数"<<endl;
    }
    ~Fu(){
        cout<<"Fu 构造函数"<<endl;
    }
    void showNo(){
        cout<<"Fu没有调用本类的内部成员"<<endl;
    }
    void showStatic(){
        cout<<"Fu调用本类的静态内部成员，num:"<<num<<endl;
    }
    void showMem(){
        cout<<"Fu调用本类的内部成员,id:"<<id<<endl;
    }
};
class Zi:public Fu{
private:
    int id;
    char name[20];
    static int num;
public:
    Zi(){
        id = 101;
        cout<<"Zi 构造函数"<<endl;
    }
    ~Zi(){
        cout<<"Zi 构造函数"<<endl;
    }
    void showNo(){
        cout<<"没有调用本类的内部成员"<<endl;
    }
    void showStatic(){
        cout<<"调用本类的静态内部成员，num:"<<num<<endl;
    }
    void showMem(){
        cout<<"调用本类的内部成员,id:"<<id<<endl;
    }
};
int Zi::num =235;
int main() {
    Zi* zi = nullptr;
    zi->showNo();//没有调用本类的内部成员，不会崩溃
    zi->showStatic();//正常
//    zi->showMem();//出错
    Zi *zi2 = static_cast<Zi*>(new Fu);
    zi2->showMem();//?==0?
    system("rm -rf a.out*");
    return 0;
}

