//
// Created by sunalong on 17/1/6 15:11.
// Email:466210864@qq.com
//

#include <iostream>

using namespace std;

int main() {
    cout << "try catch ----1----lll" << endl;
    try {
        int a = 3;
        int b = 5;
        cout << "try catch ---2-----lll" << endl;
        int i = a / b;
        cout << "try catch ---3-----lll" << endl;
    } catch (...) {
        cerr << "try catch ---4-1-cerr---lll" << endl;
        cout << "try catch ---4-2----lll" << endl;
        cerr << "try catch ---4-3-cerr---lll" << endl;
        return 1;
    }
    cout << "try catch --5------lll" << endl;
    return 0;
}
