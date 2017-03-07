//
// Created by sunalong on 17/3/7 17:33.
// Email:466210864@qq.com
//
/**
 * 四种方式的类型转换
 */
#include<iostream>
#include <stdio.h>

void defaultCast();

void staticCastTest();

void constCastTest();

void reinterpretCastTest();

using namespace std;

struct CameraDesc {
    char name[64];
    char unique_id[64];
};

int main() {
    long jp = 89;
    CameraDesc *cameraDesc = reinterpret_cast<CameraDesc *>(jp);
    cout << " cameraDesc:" << cameraDesc << " &cameraDesc:" << &cameraDesc << endl;
    cout << " &jp:" << &jp << endl;
//    cout<<cameraDesc->name<<" "<<cameraDesc->unique_id<<endl;
    defaultCast();
    staticCastTest();
    constCastTest();
    reinterpretCastTest();
    return 0;
}

/**
 * reinterpret_cast 专业转换指针，最安全
 * 使用率：%1
 * 指针是强类型，其类型决定了数据的解析方式、内存占多大
 */
void reinterpretCastTest() {
    int num = 3;
    char *p = reinterpret_cast<char *>(&num);
    cout << "p:" << p << " &p:" << &p << endl;
    cout << "num:" << &p << endl;
    for (int i = 0; i < 4; i++) {
        printf("%c,%d,%p,%d\n", *(p + i), *(p + i),*(p + i),(p + i));
    }
    /**
     * 让 char类型的指针变量 p 强行指向 int 类型的变量 num 所在的内存块
     */
}

/**
 * const 修饰的变量，可以被修改，但无法生效，因为编译的时候不读内存
 * const_cast 去掉常量指针属性
 * 使用率：%5
 */
void constCastTest() {
    int num[3] = {1, 4, 7};
    const int *p = num;
    cout << "*p:" << *p << "  *(p+1):" << *(p + 1) << "     *(p+2):" << *(p + 2) << "     p:" << p << "   &p:" << &p << endl;
    int *pNew = const_cast<int *>(p);
    *pNew = 10;
    cout << "*pNew:" << *pNew << "    *(pNew+1):" << *(pNew + 1) << "   *(pNew+2):" << *(pNew + 2) << "   pNew:" << pNew << "     &pNew:" << &pNew <<
    endl;
}

/**
 * 格式：static_cast<想要转换成的数据类型>(被转换的数据)
 * 使用率：80%
 */
void staticCastTest() {
    printf("98.87以整形打印：%d\n", 98.87);
    printf("static_cast<int>(98.87)以整形打印：%d\n", static_cast<int>(98.87));
    printf("98以 float 打印：%f\n", 98);
    printf("static_cast<float>(98)以 flaot 打印：%f\n", static_cast<float>(98));
    int *p = static_cast<int *>(malloc(100));
}

void defaultCast() {
    double db = 10.9;
    float fl = db;//默认数据类型转换
    cout << "fl:" << fl << endl;
    void *p = new int[10];
    int *pInt = (int *) p;//C 语言风格
}

