//
// Created by sunalong on 17/2/16 12:34.
// Email:466210864@qq.com
//
#include <iostream>


using namespace std;

void useString();

void useCharPoint();

void useConstCharPoint();

int main() {
    cout << "使用 String" << endl;
    useString();
    cout << "使用Char指针" << endl;
    useCharPoint();
    cout << "使用ConstCharPoint" << endl;
    useConstCharPoint();
    return 0;
}

void useConstCharPoint() {
    const char *consCharPoint = "aou";
    char *retCharPoint = new char[strlen(consCharPoint) + 1];
    stpcpy(retCharPoint, consCharPoint);
    cout << "Before retCharPoint:" << retCharPoint << endl;
    for (int i = 0; i < strlen(consCharPoint); i++) {
        *(retCharPoint + i) = *(consCharPoint + i) + i;
        cout << "retCharPoint:" << retCharPoint << endl;
    }
    cout << "Done retCharPoint:" << retCharPoint << endl << endl;
}

void useCharPoint() {
    char charArr[] = "aou";
    char *rawStr;
    rawStr = charArr;
    cout << "rawStr:" << rawStr << " *(rawStr + 1):" << *(rawStr + 1) << "  (rawStr + 1):" << (rawStr + 1) << endl;
    for (int i = 0; i < strlen(rawStr); i++) {
        *(rawStr + i) = *(rawStr + i) + i;
        cout << "rawStr:" << rawStr << endl;
    }
    cout << "Done rawStr:" << rawStr << endl << endl;
}

void useString() {
    char charArr[] = "aou";
    char *rawStr;
    rawStr = charArr;
    string str = "";
    cout << "charArr:" << charArr << "  rawStr:" << rawStr << " *(rawStr + 1):" << *(rawStr + 1) << "  (rawStr + 1):" << (rawStr + 1) << endl;
    for (int i = 0; i < strlen(rawStr); i++) {
        str += *(rawStr + i) + i;//cqw
        cout << "str:" << str << " rawStr:" << rawStr << endl;
    }
    cout << "Done str:" << str << " rawStr:" << rawStr << endl << endl;
}
