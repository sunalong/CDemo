//
// Created by sunalong on 17/3/7 10:41.
// Email:466210864@qq.com
//
#include <iostream>
#include <stdarg.h>

using namespace std;

int getMax(const int *intArr, int length);//只能求出 int 数组中最大的数

void funcTempleteTest();

/**
 * 函数模板，求出任意类型的数组中最大的数
 */
template<typename T>
T MAX(T *p, const int length) {
    T max(p[0]);
    for (int i = 0; i < length; i++)
        if (max < p[i])
            max = p[i];
    return max;
}

//模板参数，参数至少有一个是模板类型
template<typename T>
T SUM(int count, T data1, ...) {//累加
    va_list arg_ptr;//参数列表的指针
    va_start(arg_ptr, count);//限定从 count 开始，限定多少个参数
    T sumResult(0);
    for (int i = 0; i < count; i++) {
        sumResult += va_arg(arg_ptr, T);
    }
    va_end(arg_ptr);//结束
    return sumResult;
}

/**
 * 函数模板与 auto
 * 自动数据类型，根据实际推导出类型
 */
template<class T1, class T2>
auto get(T1 data, T2 bigData) -> decltype(data * bigData) {
    return data * bigData;
}

int main() {
    cout <<"typeid(get(12.0, 'A')).name():"<< typeid(get(12.0, 'A')).name() << endl;
    cout <<"get(12.0, 'A') :"<< get(12.0, 'A') << endl;
    funcTempleteTest();
    return 0;
}

/**
 * 函数模板的测试
 */
void funcTempleteTest() {
    int intArr[6] = {1, 45, 8, 9, 6, 100};
    cout << "int getMax(const int *intArr, int length)：获取的最大值：" << getMax(intArr, 6) << endl;//数组在函数参数中退化为指针
    cout << "template <typename T> T MAX(T*p,const int length)：获取的最大值：" << MAX(intArr, 6) << endl;//数组在函数参数中退化为指针
    cout << "泛型加可变参数：" << SUM(5, 1, 2, 3, 4, 5) << endl;
    cout << "泛型加可变参数：" << SUM(3, 1.3, 2.3, 3.3) << endl;
}

int getMax(const int *intArr, int length) {
    int max = intArr[0];
    for (int i = 0; i < length; i++) {
        if (max < intArr[i])
            max = intArr[i];
    }
    return max;
}
