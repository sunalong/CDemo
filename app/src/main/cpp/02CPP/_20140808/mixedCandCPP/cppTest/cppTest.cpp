//
// Created by sunalong on 17/3/2 16:07.
// Email:466210864@qq.com
//
/**
 * 执行流程：
 * 先执行 libToso 中的 make,将生成的 so 文件复制到本目录下，然后 make,
 * 再执行生成的 cppTest
 */
#include <iostream>
#include "../testlib.h"
using namespace std;
int main(){
    int theLarge = max(32,67);
    cout<<"相对较大的数是："<<theLarge<<endl;
    return 0;
}