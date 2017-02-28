//
// Created by sunalong on 17/2/27 17:15.
// Email:466210864@qq.com
//
/**
 * cpp 中的 class 对应于 c 中的 struct
 */
#include <iostream>

using namespace std;
struct man {
    char name[10];
    int age;
};

class person {
public:
    char name[10];
    int age;
private:
    int sex;//外部无法访问
};

int main() {
    man m_struct;
    strcpy(m_struct.name, "structName");
    m_struct.age = 21;
    cout << "结构体 name:" << m_struct.name << " age:" << m_struct.age << endl;

    person pClass;
    strcpy(pClass.name, "className");
    pClass.age = 22;
    cout << "class name:" << pClass.name << " age:" << pClass.age << endl;

    return 0;
}