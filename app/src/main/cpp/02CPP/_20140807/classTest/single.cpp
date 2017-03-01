//
// Created by sunalong on 17/2/28 21:23.
// Email:466210864@qq.com
//

#include "single.h"
#include <iostream>

using namespace std;
//single single::*p = NULL;
//single *single::p = NULL;
single *(single::p) = NULL;

single *single::getInstance() {
    if (p == NULL)
        p = new single;
    return p;
}

single::single() {
    cout << "single 的私有构造函数被调用" << endl;
    this->num = 2;
}

void single::setNum(int num) {
    this->num = num;
}

int single::getNum() const {
    return this->num;
}

void single::releaseInstance() {
    cout << "single 的releaseInstance函数被调用" << endl;
    if (p != NULL) {
        delete p;//此时c++会自动调用本类的析构函数
        p = NULL;
    }
}

single::~single() {
    cout << "single 的析构函数被调用" << endl;
//    releaseInstance();
}














