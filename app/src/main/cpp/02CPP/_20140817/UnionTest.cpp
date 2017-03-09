//
// Created by sunalong on 17/3/9 11:54.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;
union MyUnion{
    int num;
    double db;
    void print(int i){
        cout<<"i:"<<i<<" num:"<<num<<" db:"<<db<<endl;
    }
};
union MyUnion2{
    double db;
    void print(int i){
        cout<<" db:"<<db<<endl;
    }
};
int main() {
cout<<"sizeof:"<< sizeof(MyUnion2)<<endl;//8
cout<<"sizeof:"<< sizeof(MyUnion)<<endl;//8
    MyUnion myUnion;
    myUnion.num = 2;
    cout<<"myUnion.num:"<<myUnion.num<<" db:"<<myUnion.db<<endl;
    myUnion.print(101);
    myUnion.db = 20.8;
    cout<<"myUnion.num:"<<myUnion.num<<" db:"<<myUnion.db<<endl;
    myUnion.print(102);
    system("rm -rf a.out*");
    return 0;
}

//sizeof:8
//myUnion.num:2 db:6.95314e-310
//i:101 num:2 db:6.95314e-310
//myUnion.num:-858993459 db:20.8
//i:102 num:-858993459 db:20.8