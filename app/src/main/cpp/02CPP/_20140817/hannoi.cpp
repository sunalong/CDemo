//
// Created by sunalong on 17/3/8 23:31.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

void han(int n,char first,char second,char third){
    static int num = 1;
    if(n<1)
        return;
    han(n-1,first,third,second);//把 n-1 这个整体由 first 依靠 third 移动到 second
    cout<<"第"<<num++<<"次的移动：编号为"<<n<<"的盘子由"<<first<<"-->"<<third<<endl;//把 n 由 first 直接移动到 third
    han(n-1,second,first,third);//把n-1 这个整体由 second 依靠 first 移动到 third
}
int main() {
    int n;
    cout<<"请输入汉诺塔盘子个数：";
    cin>>n;
    cout<<"n="<<n<<endl;
    han(n,'A','B','C');
    system("rm -rf a.out*");
    return 0;
}

