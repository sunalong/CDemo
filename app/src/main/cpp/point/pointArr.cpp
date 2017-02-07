//
// Created by sunalong on 17/2/7 12:09.
// Email:466210864@qq.com
//

#include <iostream>
using namespace std;
const int MAX = 3;

int main() {
    int var[MAX] = {10, 100, 200};
    int *ptr[MAX];
    char *nameChar[MAX] = {"Zara charPoint", "Hina charPoint", "Sara charPoint"};
    string nameStr[MAX] = {"Zara string", "Hina string", "Sara string"};
    for (int i = 0; i < MAX; i++) {
        ptr[i] = &var[i];//赋值为整数的地址
        cout << "Value of var[" << i << "]=" << var[i] << "<-->" << *ptr[i] << endl;
        cout << "Value of nameChar[" << i << "]=" << nameChar[i] << endl;
        cout << "Value of nameStr[" << i << "]=" << nameStr[i] << endl;
    }
    return 0;
}