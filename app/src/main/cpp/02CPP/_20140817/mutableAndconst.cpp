//
// Created by sunalong on 17/3/9 16:14.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class MutableTest {
private:
    int a;
    int const b = 9;//const修饰的变量必须在声明时初始化
    mutable int c;//不受被 const 修饰的函数影响，值可被修改
public:
    void showABC() const {
//        this->a = 30;//被 const 修饰的函数内部不可改变
//        this->b = 20;//b 被 const 修饰了，在此不可修改 b的值
        this->c = 20;
        cout << "a:" << a << " b:" << b << " c:" << c << endl;
    }

    void setA(int a) {
        this->a = a;
    }

    void setB(int b) {
//        this->b = b;//b 在声明的时候被 const 修饰了，不可修改
        cout << "b 在声明的时候被 const 修饰了，不可修改" << endl;
    }
};

int main() {
    MutableTest mutableTest;
    mutableTest.setB(2);
    mutableTest.showABC();
    system("rm -rf a.out*");
    return 0;
}

