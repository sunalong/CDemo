//
// Created by sunalong on 17/3/13 17:07.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class Fu{
public:
    void go(){
        cout<<"Fu  void go()"<<endl;
    }
    void go(int num){
        cout<<"Fu  void go(int num):"<<num<<endl;
    }
    void go(char *str){
        if(str)
        cout<<"Fu  void go(char *str):"<<str<<endl;
        else
        cout<<"Fu  void go(char *str):"<<"str为空"<<endl;

    }
};
class Zi:public Fu{
public:
    void go(){
        cout<<"Zi  void go()"<<endl;
    }
    void go() const{
        cout<<"Zi  void go() const"<<endl;
    }
};
int main() {
    Fu fu;
//    fu.go(NULL);//call to member function 'go' is ambiguous
    fu.go(123);
    fu.go("abc");
    fu.go(nullptr);
    cout<<endl<<endl;
    Zi zi;
    zi.go();
//    zi.go(123);//no matching member function for call to 'go'
    //即子类中的 go 被重载了
//    zi.go("abc");//同上
//    const Zi ziConst;//要求有显示的构造函数
    const Zi* ziConst = new Zi;
    const int i=5;
    ziConst->go();
    system("rm -rf a.out*");
    return 0;
}

