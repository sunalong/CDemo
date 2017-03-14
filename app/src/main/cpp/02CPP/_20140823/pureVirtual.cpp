//
// Created by sunalong on 17/3/14 11:16.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
class Base{
public:
    int num;
    Base(){
        num=1100;
        cout<<"Base 构造函数"<<num<<endl;
    }
    ~Base(){
        num=1101;
        cout<<"~Base 析构函数"<<num<<endl;
    }
    virtual void show()=0;
};
class Cat:public Base{
public:
    Cat(){
        num=1200;
        cout<<"Cat 构造函数"<<num<<endl;
    }
    ~Cat(){
        num=1201;
        cout<<"~Cat 析构函数"<<num<<endl;
    }
    void show(){
        cout<<"子类 Cat 实现抽象类的纯虚函数，num:"<<num<<endl;
    }
};
class Dog:public Base{
public:
    Dog(){
        num=1300;
        cout<<"Dog 构造函数"<<num<<endl;
    }
    ~Dog(){
        num=1301;
        cout<<"~Dog 析构函数"<<num<<endl;
    }
    void show(){
        cout<<"子类 Dog 实现抽象类的纯虚函数，num:"<<num<<endl;
    }
};
void test(Base* base){
    base->show();
    cout<<"base.show()"<<endl;
}
int main() {
    Cat cat;
    cat.show();
    cout<<endl;
    Dog dog;
    dog.show();
    cout<<endl;
    test(&cat);
    system("rm -rf a.out*");
    return 0;
}

