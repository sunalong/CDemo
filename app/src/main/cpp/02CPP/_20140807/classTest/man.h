//
// Created by sunalong on 17/2/28 11:45.
// Email:466210864@qq.com
//

#ifndef CDEMO_MAN_H
#define CDEMO_MAN_H

class man{
private:
    char name[10];
    int age;
public:
    man();
    man(const char*name);
    man(const man &it);//拷贝构造函数
    ~man();
    void setName(const char *name);
    const char * getName();
    int getAge();
    void setAge(int age);
//    const char *getName() const {
//        return name;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//    void setAge(int age) {
//        man::age = age;
//    }
};
#endif //CDEMO_MAN_H
