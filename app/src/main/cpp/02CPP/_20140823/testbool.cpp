//
// Created by sunalong on 17/3/15 11:30.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

int retInt(int num){
    if(num<0)
        return 0;
    else
        return 1;
}
int main() {
    bool boolRet;
    cout<<"boolRet:"<<boolRet<<endl;
    boolRet = retInt(-1);
    cout<<"boolRet = retInt(-1):"<<boolRet<<endl;
    boolRet = retInt(2);
    cout<<"boolRet = retInt(2):"<<boolRet<<endl;

    system("rm -rf a.out*");
    return 0;
}

