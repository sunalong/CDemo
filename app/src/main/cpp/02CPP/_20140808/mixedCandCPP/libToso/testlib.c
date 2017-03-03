//
// Created by sunalong on 17/3/2 16:01.
// Email:466210864@qq.com
//
/**
 * 把此 C 文件打包成 so 文件，供外部来调用，
 * 外部调用有两种形式，C 和 CPP
 */
#include <stdio.h>

int max(int a, int b) {
    printf("比较大小：a:%d 与 b:%d 的大小", a, b);
    return a > b ? a : b;
}