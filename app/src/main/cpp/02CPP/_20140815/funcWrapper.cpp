//
// Created by sunalong on 17/3/7 15:59.
// Email:466210864@qq.com
//
#include <iostream>
#include <functional>

using namespace std;

//函数包装器，T：数据类型 F:函数
template<typename T, typename F>
T run(T t, F f) {
    static int count = 0;
    count++;//计数器
    cout << "T run(T t,F f)一个参数的包装器执行" << count << "次" << endl;
    if (count > 1) {
        T vx(0);
        return vx;
    }
    return f(t);//函数传入参数
};

template<typename T, typename F>
T run(T t1, T t2, F f) {
    return f(t1, t2);//函数传入参数
};

int cheng(int a, int b) {
    return a * b;
}

int main() {
    double db = 12.9;
    int num1 = 3;
    int num2 = 9;

    function<double(double)> fun1 = [](double u) {
        return u * 2;
    };
    function<double(double)> fun2 = [](double u) {
        return u * u;
    };
    function<int(int, int)> fun3 = [](int u1, int u2) {
        return u1 + u2;
    };
    function<int(int, int)> fun4 = cheng;//fun4 函数指针

    cout << "1.double*2:" << run(db, fun1) << endl;
    cout << "2.double^2" << run(db, fun2) << endl;
    cout << "3.int+int" << run(num1, num2, fun3) << endl;
    cout << "4.int*int" << run(num1, num2, fun4) << endl;
    return 0;
}