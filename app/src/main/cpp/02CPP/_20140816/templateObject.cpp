//
// Created by sunalong on 17/3/8 17:27.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <time.h>

using namespace std;
template<int N>
struct data {
    enum fbnq {
        res = data<N - 1>::fbnq::res + data<N - 2>::fbnq::res
    };
};
template<>
struct data<1> {
    enum fbnq {
        res = 1
    };
};
template<>
struct data<2> {
    enum fbnq {
        res = 1
    };
};

int getFbnq(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return getFbnq(n - 1) + getFbnq(n - 2);
    }
}

int main() {
    cout << setiosflags(ios::fixed);  //只有在这项设置后，setprecision才是设置小数的位数。
//  cout << setprecision(4) << f << endl;    //输出4位小数，3.1416
    clock_t start, finish;
    start = clock();
    const int NUM = 45;
    clock_t begin = clock();
    int res1 = data<NUM>::res;
    clock_t end = clock();
    double usetime = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << "使用模板元输出为:" << res1 << " 用时：" << setprecision(10) << usetime << "s, begin:" << begin << " " << end << " " << CLOCKS_PER_SEC << endl;

    begin = clock();
    res1 = getFbnq(NUM);
    end = clock();
    usetime = (double) (end - begin) / CLOCKS_PER_SEC;

    cout << "使用普通递归输出:" << res1 << " 用时：" << setprecision(10) << usetime << "s, begin:" << begin << " " << end << " " << CLOCKS_PER_SEC << endl;
    finish = clock();
    double duration = (double) (finish - start) / CLOCKS_PER_SEC;
    cout << "整个程序运行完毕：" << setprecision(10) << duration << "s  start:" << start << " finish:" << finish << endl;
    system("rm -rf a.out*");
    return 0;
}

