//
// Created by sunalong on 17/2/28 18:19.
// Email:466210864@qq.com
//
#include <iostream>
#include "Person.h"

using namespace std;
int Person::count = 181;//类静态成员变量初始化的方式,调用与 Java 相同
void Person::setName(char *name2) {
    memset(Person::name, 0, sizeof(name));
    strcpy(Person::name, name);
}

const char *Person::getName() const {
//    return Person::name;
    return name;
}

int Person::getAge() const {
    return Person::age;
}

void Person::setAge(int age) {
//    Person::age = age;
   this->age = age;//同上
}

Person::Person() : age(11), name("") {
    cout << "Person 的构造函数被调用,静态成员变量：" << this->count<<endl;
}

int Person::getSex() {
    return 0;
}

void Person::setSex(int sex) {
    Person::sex = sex;
}

Person *Person::getThis() {
    return this;
}













