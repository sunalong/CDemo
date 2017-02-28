//
// Created by sunalong on 17/2/28 18:19.
// Email:466210864@qq.com
//

#ifndef CDEMO_PERSON_H
#define CDEMO_PERSON_H

#include <string.h>

class Person {
private:
    char name[10];
    int age;
    int sex;
    static int count;//定义一个类的静态成员变量，此处不可赋值，与 Java 不同
public:
    Person();

    void setName(char *name);

/**
 * 函数后面加 const 表示此函数内部不会以类的成员变量做任何的修改
 * 否则如果创建常量对象再调用此方法就会报错，如果不调用不加 const 的方法就不会报错
 */
    const char *getName() const;

    int getAge() const;

    void setAge(int age);

    int getSex();

    void setSex(int sex);
    Person * getThis();
};

#endif //CDEMO_PERSON_H
