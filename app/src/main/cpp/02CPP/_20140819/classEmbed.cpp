//
// Created by sunalong on 17/3/9 17:56.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
class Employee{
private:
    int id = 0;
public:
    Employee(){
        cout<<"构造函数Employee()"<<endl;
    }
    Employee(int id){
        cout<<"构造函数Employee(int id),id:"<<id<<endl;
    }
    void show(){
        cout<<"Employee show()"<<id<<endl;
    }
    ~Employee(){
        cout<<"析构函数~Employee()"<<endl;
    }
};
class Company{
private:
    Employee employee;//表示调用 Employee 的无参构造函数
    Employee *pEmployee;
public:
    Company(){
        employee.show();
        cout<<"构造函数Company()"<<endl;
        pEmployee = new Employee(2);//显示调用 Employee 的有参构造函数
    }
    ~Company(){
        cout<<"析构函数Company()"<<endl;
        delete pEmployee;
    }
};
int main() {
    Company company;
    system("rm -rf a.out*");
    return 0;
}

