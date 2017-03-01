//
// Created by sunalong on 17/3/1 11:56.
// Email:466210864@qq.com
//

#include "mystring.h"
#include <iostream>

using namespace std;
MyString *MyString::instance = NULL;

char *MyString::getStr() const {
    return this->str;
}

MyString *MyString::makeString(const char *s) {
    if (instance == NULL) {
        if (s == NULL)
            instance = new MyString;
        else
            instance = new MyString(s);
    }
    return instance;
}

MyString::MyString(const char *str) {
    cout << "调用 MyString 有参构造函数，str:" <<str<< endl;
    initStr(str);
}

void MyString::initStr(const char *str) {
    int len = strlen(str);
        this->str = new char[len + 1];
        strcpy(this->str, str);
        this->str[len]=0;
}

MyString::MyString() {
    cout << "调用 MyString 无参构造函数" << endl;
}

MyString::~MyString() {
    cout << "调用 MyString 析构函数" << endl;
    delete[]str;//将构造函数分配的内在释放
}

void MyString::setStr(const char *str) {
    if(str == NULL)
        return;
    if(this->str == NULL){
        initStr(str);
    }else{
        int lenSelf = strlen(this->str);
        int lenOut = strlen(str);
        if(lenOut>lenSelf){
            delete this->str;
            initStr(str);
        }else{
            strcpy(this->str,str);
//            this->str[lenOut]='\0';
            this->str[lenOut]=0;//新空间最后一个字节为字符串结束标示符0
        }
    }
}











