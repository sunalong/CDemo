//
// Created by sunalong on 17/3/14 10:53.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class Person {
public:
    Person() {
        cout << "Person 构造函数" << endl;
    }

    virtual ~Person() {
        cout << "~Person 构造函数" << endl;
    }
};

class Student : public Person {
public:
    Student() {
        cout << "Student 构造函数" << endl;
    }

    ~Student() {
        cout << "~Student 构造函数" << endl;
    }
};

int main() {
    Person *person1 = new Person;
    delete person1;
    Person *person = new Student;
    delete person;//内存泄漏，只删除了 Student 中的父类Person
    cout << endl;
    Student *student = static_cast<Student *>(new Person);
    delete student;
    system("rm -rf a.out*");
    return 0;
}

