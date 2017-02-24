//
// Created by sunalong on 17/2/17 11:04.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;

int main() {
    cout << "使用 gdb 调试 cpp" << endl;
    const char *constChatPoint = "abc";
    char *retCharPoint = new char[strlen(constChatPoint+1)];
    cout << "before *retCharPoint:" << strlen(retCharPoint) << endl;
    strcpy(retCharPoint,constChatPoint);
    cout << "before *retCharPoint2:" << strlen(retCharPoint) << endl;
    for (int i = 0; i < strlen(retCharPoint); i++) {
        *(retCharPoint + i) = *(constChatPoint + i);
        cout << "*(retCharPoint+i):" << *(retCharPoint + i) << endl;
    }
    cout << "Done *retCharPoint:" << *retCharPoint << endl;
    return 0;
}