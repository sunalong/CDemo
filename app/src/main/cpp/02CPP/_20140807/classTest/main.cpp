//
// Created by sunalong on 17/2/28 11:51.
// Email:466210864@qq.com
//

#include <iostream>
#include "man.h"
#include "Person.h"
#include "single.h"
using namespace std;
extern int i;

void testStack();

void testNew();

void testCopy();

void testConstObject();

void testCopy2(man &man1);


void testThis();

void testSingle();

int main() {
    testStack();
    testNew();
    testCopy();
    man man1("lalaName");
    testCopy2(man1);
    testConstObject();
    testThis();
    testSingle();
    return 0;
}

void testSingle() {
    cout << "单例调用1：" << single::getInstance()->getNum() << endl;
    cout << "单例调用2：" << single::getInstance()->getNum() << endl;
    cout<<"单例释放："<<endl;
//    single::releaseInstance();//可两次调用
//    single::releaseInstance();
    delete single::getInstance();//为何不可两次调用？pointer being freed was not allocated
    delete single::getInstance();
}

void testThis() {
    Person person;
    cout<<"person addr:"<<&person<<" this addr:"<<person.getThis()<<endl;
}

/**
 * 使用引用而不使用 void testCopy2(man man1) 的原因：
 * 后者内部使用的是拷贝构造函数，消耗资源，推荐使用指针或引用，避免使用拷贝构造函数
 */
void testCopy2(man &man1) {
    cout << "拷贝构造函数：name:" << man1.getName() << " age:" << man1.getAge() <<" man addr:"<<&man1<< endl;
}

/**
 * 常量对象：
 * 1.若要创建常量对象，需要有显示的构造函数
 * 2.若要创建常量对象，需要在被调用的函数后面加上 const修饰符
 * 函数后面加 const 表示此函数内部不会以类的成员变量做任何的修改
 * 否则如果创建常量对象就会报错。
 */
void testConstObject() {
    const Person person;
    cout<<"常量对象 Person name:"<<person.getName()<<" age:"<<person.getAge()<<endl;
}

/**
 * 拷贝构造函数
 */
void testCopy() {
    man m1("jack");
    man m2 = m1;
    cout<<"拷贝构造函数：name:"<<m2.getName()<<" age:"<<m2.getAge()<<endl;
    cout<<"m2 addr:"<<&m2<<" m1 addr:"<<&m1<<endl;
}

/**
 * 在堆中实例化对象，需要手动释放内存，否则会有内存泄漏
 */
void testNew() {
    man *manPoint = new man;//调用没有参数的构造函数，在堆中实例化一个对象
//    cout << "man name:" << manPoint.getName() << " age:" << manPoint.getAge() << endl;
    manPoint->setName("newMan");
    cout << "在堆中实例化对象：man name:" << manPoint->getName() << " age:" << manPoint->getAge() << endl;
    delete manPoint;
    man *manPointParams = new man("paramName");//调用带参数的构造函数，在堆中实例化一个对象
    cout << "在堆中实例化对象：man name:" << manPointParams->getName() << " age:" << manPointParams->getAge()  << endl;
    delete (manPointParams);
}

/**
 * 在栈中实例化对象
 */
void testStack() {
    man man1;//在栈中将 man 这个类实例化为一个对象 man1，此时c++自动调用这个类的构造函数
    man1.setName("fuckName");
//    man1.setAge(22);
    cout << "在 main.cpp 中使用 man.cpp 中的全局变量,i：" << i << endl;
    cout << "在栈中实例化对象：man name:" << man1.getName() << " age:" << man1.getAge()<< endl;

//    man man2("HelloName");
//    cout << "在栈中实例化对象：man name:" << man2.getName() << " age:" << man2.getAge() << endl<<endl;
}