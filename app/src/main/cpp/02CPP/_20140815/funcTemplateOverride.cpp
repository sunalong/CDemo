//
// Created by sunalong on 17/3/7 16:48.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;
struct Info {
    char name[40];
    double db;
    int data;
};

void funcTemplateTest();

template<typename T>
void myswap(T &a, T &b) {
    cout << "通用函数模板" << endl;
    T temp = a;
    a = b;
    b = temp;
}

//模板为空，明确参数类型，覆盖函数模板的类型
void myswap(Info &info1, Info &info2) {
    cout << "特有函数模板" << endl;
    Info temp = info1;
    info1 = info2;
    info2 = temp;
}

int main() {
    Info info1 = {"fuck",20.9,10};
    Info info2 = {"kcuf",9.2,4};
    cout<<"before swap info1:"<<info1.name<<" "<<info1.db<<" "<<info1.data<<endl;
    cout<<"before swap info2:"<<info2.name<<" "<<info2.db<<" "<<info2.data<<endl;
    myswap(info1,info2);
    cout<<"after  swap info1:"<<info1.name<<" "<<info1.db<<" "<<info1.data<<endl;
    cout<<"after  swap info2:"<<info2.name<<" "<<info2.db<<" "<<info2.data<<endl;
    return 0;
}

void funcTemplateTest() {
    int num1 = 100;
    int num2 = 10;
    cout << "before myswap num1:" << num1 << " num2:" << num2 << endl;
    myswap(num1, num2);//实现交换
    cout << "after  myswap num1:" << num1 << " num2:" << num2 << endl;
    char ch1 = 'Z';
    char ch2 = 'A';
    cout << "before myswap ch1:" << ch1 << " ch2:" << ch2 << endl;
    myswap<char>(ch1, ch2);
//    myswap(ch1, ch2);
    cout << "after  myswap ch1:" << ch1 << " ch2:" << ch2 << endl;
}