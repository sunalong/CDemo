//
// Created by sunalong on 17/3/7 11:58.
// Email:466210864@qq.com
//
#include <iostream>
#include <locale>
using namespace std;
int main(){
    setlocale(LC_ALL,"chs");
//    wchar_t *p1 = "12345";
    // cannot initialize a variable of type 'wchar_t *' with
    // an lvalue of type 'const char [6]'
   const wchar_t *p2 = L"12345";
//    wchar_t *p3 = "宽字符12345";
    //error: cannot initialize a variable of type 'wchar_t *' with
    // an lvalue of type 'const char [15]'
    const wchar_t *p4 = L"宽字符12345";
    wcout<<"*p2:"<<*p2<<" *p4:"<<*p4<<endl;
//    cout<<"*p1:"<<*p1<<" *p2:"<<*p2<<" *p3:"<<*p3<<" *p4:"<<*p4<<endl;
    return 0;
}
