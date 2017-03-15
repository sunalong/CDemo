//
// Created by sunalong on 17/3/15 21:06.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

/**
 * 使用函数指针写回调
 * 函数指针作为参数，
 */
namespace TEST {
    typedef void (*FuncCallback)(int cmdType, const char *str);
}

void upload(const TEST::FuncCallback &funcCallback, int cmdType, char *str) {
    cout << "uploading ..."<< endl;
    funcCallback(cmdType, str);
}

void record(const TEST::FuncCallback &funcCallback, int cmdType, char *str) {
    cout << "recording ..." << endl;
    funcCallback(cmdType, str);
}

void selfFunc(int cmdType, const char *str) {
    cout << "callback收到数据： cmdType=" << cmdType << ",str:" << str << endl;
    string strRet;
    switch (cmdType){
        case 0://上传成功
            strRet = "上传的信息：";
            break;
        case 1://录音成功
            strRet = "录音的内容：";
            break;
    }
    strRet += str;
    cout << "final: strRet:" << strRet << endl<<endl;
}

int main() {
    upload(selfFunc, 0, "头像url：http://lala/avatar.jpg");
    record(selfFunc, 1, "你是最棒的～");
    system("rm -rf a.out*");
    return 0;
}

