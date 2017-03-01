//
// Created by sunalong on 17/3/1 11:13.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;

class Demo {
public:
    Demo() {
        cout << "Demo 构造函数" << endl;
    }

    Demo(int i) {
        cout << "Demo 构造函数,int i=" << i << endl;
    }

    ~Demo() {
        cout << "Demo 析构函数" << endl;
    }
};

void testChar();

int main() {
    Demo d[3];
    Demo dArr[3] = {Demo(1), Demo(5), Demo(10)};//定义数组对象，同时调用带参数的构造函数
    testChar();
    cout << "------" << endl;
    return 0;
}

void testChar() {
//    char a[3]="123";//initializer-string for char array is too long
    char a[3] = "12";//最后一位为\0,但为何 Demo d[3]不是这样？
    for (int i = 0; i < 4; i++) {
        cout << "i=" << i << " char=" << *(a + i) << endl;
    }
//    以上输出为：
//    i=0 char=1
//    i=1 char=2
//    i=2 char=
//    i=3 char=

//    for(int i=0;i<strlen(a);i++){
//        cout<<"i="<<i<<" char="<<a[i]<<endl;
//    }
//    以上输出为：
//    i=0 char=1
//    i=1 char=2
}
