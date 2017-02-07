//
// Created by sunalong on 16/12/29 14:19.
// Email:466210864@qq.com
//

#include <iostream>

void charLength(const char *greeting1);

using namespace std;

int main() {
    char greeting1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char greeting2[] = {'F', 'e', 'l', 'l', 'o'};
    char greeting3[] = {"hello\0"};
    char greeting4[] = "hello\0";
    char greeting5[] = "hello";
    charLength(greeting1);
    charLength(greeting2);
    charLength(greeting3);
    charLength(greeting4);
    charLength(greeting5);
    return 0;
}

void charLength(const char *charArr) {
    cout << "字符串数组为:" << charArr << "   sizeof(greeting):" << sizeof(charArr)
    << "  strlen(greeting):" << strlen(charArr) << endl << endl;
}
