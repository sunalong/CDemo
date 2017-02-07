//
// Created by sunalong on 17/2/7 14:11.
// Email:466210864@qq.com
//
#include <iostream>
#include <cstdlib>

using namespace std;
const int MAX = 3;
static int r[MAX];
int *getRandom() {
    for (int i = 0; i < MAX; i++) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
}

int main() {
    int *p;
    p = getRandom();
    for (int i = 0; i < MAX; i++) {
        cout << "*(p+" << i << ")" << *(p + i) << endl;
    }
    return 0;
}
