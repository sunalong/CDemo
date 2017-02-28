//
// Created by sunalong on 17/2/27 21:05.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;

/**
 *
 * C++类成员的保护：
 * 如果类函数返回的是成员变量的指针，为了避免在类外部成员变量被修改，所以函数就要返回常量指针
 * 但在外面使用强转依然可以在类外部改变成员变量的值
 */
int age = 0;
class person {
private:
    char name[20];
    int age;
public:
    void setName(const char *name) {//加 const 是为了防止外部变量的值被setName内部改变
        memset(person::name, 0, sizeof(name));
        if (strcmp(name, "fuckName") == 0) {
            cout << "名字不能为 fuckName" << endl;
            return;
        }
        strcpy(person::name, name);
    }

    const char *getName() {//加 const 是为了防止外部获取此返回值的指针时改变name 的值
        return name;
    }

    void setAge(int age) {
        person::age = age;
        ::age = age*2;//在类的内部访问全局变量使用::
    }

    const int getAge() {
        return age;
    }
};

int main() {
    person person1;
    person1.setName("lalaName");
    person1.setAge(20);
    cout << "name:" << person1.getName() << " age:" << person1.getAge() << endl;
    char *p = (char *) person1.getName();//使用强转依然可以改变内部变量
    strcpy(p,"fuckName");
    cout << "2name:" << person1.getName() << " age:" << person1.getAge() <<" 全局变量：age:"<<age<< endl;
    return 0;
}