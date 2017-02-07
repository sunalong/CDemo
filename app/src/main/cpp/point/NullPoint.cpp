//
// Created by sunalong on 17/2/7 10:42.
// Email:466210864@qq.com
//

#include <iostream>
using namespace std;
int main() {
    int *ptr = NULL;
    cout << "ptr 的值是：" << ptr;
    if (ptr)
        cout << "int类型的指针变量ptr不是空指针" << endl;
    if (!ptr)
        cout << "int类型的指针变量ptr是空指针" << endl;
    return 0;
}
