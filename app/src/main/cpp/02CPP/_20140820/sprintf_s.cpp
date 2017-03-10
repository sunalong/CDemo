//
// Created by sunalong on 17/3/10 15:15.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

int main() {
    char *str1 = "123";
    char *str2 = "345";
    char *str3;
    sprintf(str3, "%s%s", str1, str2);
    cout << "str1:" << str1 << " str2:" << str2 << " str3:" << str3 << endl;
    cout << "*str1:" << *str1 << " *str2:" << *str2 << " *str3:" << *str3 << endl;
    system("rm -rf a.out*");
    return 0;
}

//~/GitHub/CDemo/app/src/main/cpp/02CPP/_20140820 on  master! ⌚ 15:18:54
//$ a.out
//str1:123 str2:345 str3:123345
//*str1:1 *str2:3 *str3:1