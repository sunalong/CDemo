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

