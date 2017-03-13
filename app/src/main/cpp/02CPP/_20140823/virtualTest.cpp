//
// Created by sunalong on 17/3/13 22:32.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
class Fu{
public:
    int x;
    Fu(int a):x(a){
        cout<<"Fu 构造函数"<<endl;
    }
    virtual void show(){
        cout<<"Fu show，x:"<<x<<endl;
    }
    ~Fu(){
        cout<<"~Fu 析构函数"<<endl;
    }
};
class Zi:public Fu{
public:
    int x,y;
    Zi(int a,int b):Fu(a),y(b){
        cout<<"Zi 构造函数"<<endl;
    }
    void show(){
        cout<<"Zi show，x:"<<x<<",y:"<<y<<endl;
    }
    ~Zi(){
        cout<<"~Zi 析构函数"<<endl;
    }
};

class Sun:public Zi{
public:
    int x,y,z;
    Sun(int a,int b,int c):Zi(a,b),z(c){
        cout<<"Sun 构造函数"<<endl;
    }
    void show(){
        cout<<"Sun show，x:"<<x<<",y:"<<y<<",z:"<<z<<endl;
    }
    ~Sun(){
        cout<<"~Sun 析构函数"<<endl;
    }
};
int main() {
    cout<<"sizeof(Fu):"<<sizeof(Fu)<<endl;
    cout<<"sizeof(int):"<<sizeof(int)<<endl;
    Fu* pFu;
    Fu fu(1);
    Zi zi(2,3);
    Sun sun(4,5,6);
    pFu = &fu;
    pFu->show();
    pFu= &zi;
    pFu->show();
    pFu = &sun;
    pFu->show();
    system("rm -rf a.out*");
    return 0;
}

