//
// Created by sunalong on 17/3/8 16:04.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
#include <string>
using namespace std;

int main() {
    //mac和 Linux 下目录使用的是：/  不需要转义
    //window 下目录分隔符使用的是：\  需要转义
    string rawStr = "/Users/along/Library/Android/sdk/platform-tools/adb devices";
    system(rawStr.c_str());
    string escPath = R"("/Users/along/Library/Android/sdk/platform-tools/adb devices")";
    cout<<"escPath:"<<escPath<<endl;
    cout<<"escPathc_str:"<<escPath.c_str()<<endl;
    system(escPath.c_str());

//    string rawStrWin = "C:\Android\sdk\platform-tools\adb devices";//不加转义字符编译不过
//    system(rawStrWin.c_str());
    string escPathWin = R"("C:\Android\sdk\platform-tools\adb devices")";
    cout<<"escPathWin:"<<escPathWin<<endl;
    system(escPathWin.c_str());
    system("rm -rf a.out*");
    return 0;
}

