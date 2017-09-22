//
// Created by sunalong on 17/5/18 17:13.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

void loginNormal(int id);
void login(int &id);

using namespace std;

int main() {
    system("rm -rf a.out*");
    int personId=123;//要确保不被改变
    cout<<"调用login前："<<personId<<"  personId地址："<<&personId<<endl;
    loginNormal(personId);
    cout<<"调用后login："<<personId<<"  personId地址："<<&personId<<endl<<endl;

    cout<<"调用login前："<<personId<<"  personId地址："<<&personId<<endl;
    login(personId);
    cout<<"调用后login："<<personId<<"  personId地址："<<&personId<<endl<<endl;

    return 0;
}
void loginNormal(int id) {
    cout<<"before 传进来的值："<<id<<"  id地址："<<&id<<endl;
    id++;
    cout<<"after 传进来的值："<<id<<endl;
    //非法改变id的值：
    // 获取personId的地址
    // 如同login(int &id)那样根据地址改变变量的值
}
void login(int &id) {
    cout<<"before 传进来的值："<<id<<"  id地址："<<&id<<endl;
    id++;
    cout<<"after 传进来的值："<<id<<endl;
    //非法改变id的值
    int * changeId = &id;
    (*changeId)=(*changeId)+5;
    cout<<"改变传进来的值："<<*changeId<<" "<<changeId<<" "<<&changeId<<endl;

}

