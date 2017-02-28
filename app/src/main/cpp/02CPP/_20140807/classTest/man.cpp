//
// Created by sunalong on 17/2/28 11:45.
// Email:466210864@qq.com
//
#include <iostream>
#include <string.h>
#include "man.h"
using namespace std;
int i=12;//Cpp 中定义的一个变量
void man::setName(const char *name) {
    memset(man::name,0, sizeof(name));
    strcpy(man::name,name);
}

const char * man::getName(){
    return man::name;
}

int man::getAge() {
    return man::age;
}

void man::setAge(int age) {
    man::age = age;
}

man::man():age(12) {//初始化成员列表
    cout<<"man 的构造函数被调用"<<endl;
    man::age = 5;//在构造函数中初始化成员变量，如果初始化成员列表和此处同时出现，则以此处为准
    cout<<"sizeof(name):"<<sizeof(name)<<endl;//10
    memset(name,0, sizeof(name));
}

man::~man() {
    cout<<"man 的析构函数被调用"<<endl<<endl;
}

man::man(const char *name) {
    cout<<"man 的重载构造函数被调用:"<< name<<endl;
    man::age = 0;
    strcpy(man::name,name);
}

man::man(const man &it) {
    cout<<"man 的拷贝构造函数被调用"<<endl;
    strcpy(name,it.name);
    age = it.age;
}















