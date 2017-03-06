//
// Created by sunalong on 17/3/6 11:52.
// Email:466210864@qq.com
//
#include <iostream>

void twoDimensionalArray();

using namespace std;

int main() {
    twoDimensionalArray();
    return 0;
}

/**
 * 使用指针创建二维数组
 */
void twoDimensionalArray() {
    int *p = new int[80];
    int (*px)[10] = (int(*)[10]) p;
//    int (*px)[10] = new int[80];//new 这里只能分配线性的内存，不符合
    cout<<" p:"<<p<<"  &p:"<<&p<<endl;
    cout<<"px:"<<px<<" &px:"<<&px<<endl;
    int data = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            px[i][j] = data++;
            cout << "  " << px[i][j];
        }
        cout << endl;
    }
}
09.11 2017年3月06日 引用高级【52.56】
10.11 2017年3月06日 bool【6.07】
10.14 2017年3月06日 引用高级增加【18.10】
10.33 2017年3月06日 auto自动变量自动根据类型创建数据【11.13】
10.45 2017年3月06日 enum【14.53】
11.18 2017年3月06日 newdelete全局【63.44】
14.12 2017年3月06日 大数据乘法与结构体【60.17】
14.37 2017年3月06日 CCPP不同【44.35】
15.28 2017年3月06日 函数模板与auto自动变量【40.21】
16.16 2017年3月06日 宽字符本地化【4.19】
16.21 2017年3月06日 inline 内联函数【11.44】
17.50 2017年3月06日 绘图【57.31】
