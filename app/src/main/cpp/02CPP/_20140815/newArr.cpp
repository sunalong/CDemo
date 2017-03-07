//
// Created by sunalong on 17/3/7 20:29.
// Email:466210864@qq.com
//
#include<iostream>
#include <array>
#include <stdlib.h>
#include <vector>//C++标准库中的迭代器

void newArrTest1();

void cppStringTest();

void vectorAndarray();

void twoDiamenArray();

void vectorTest();

void vectorIteratorTest();

void arrayIterator();

using namespace std;

int main() {
    newArrTest1();
    cppStringTest();
    twoDiamenArray();
    vectorAndarray();
    vectorTest();
    vectorIteratorTest();
    arrayIterator();
    return 0;
}

void arrayIterator() {
    array<string, 4> stringArr = {"calculator", "ll", "ls", "write"};
    array<string, 4>::iterator arrayBegin, arrayEnd;//正向迭代器
    arrayBegin = stringArr.begin();
    arrayEnd = stringArr.end();
    while (arrayBegin != arrayEnd) {
        cout << "array 使用迭代器正向输出：" << *arrayBegin << endl;
        arrayBegin++;
    }
    array<string, 4>::reverse_iterator arrayReverseBegin, arrayReverseEnd;//反向迭代器
    arrayReverseBegin = stringArr.rbegin();//反向迭代器的开始
    arrayReverseEnd = stringArr.rend();
    while (arrayReverseBegin != arrayReverseEnd) {
        cout << "array 使用迭代器反向输出：" << *arrayReverseBegin << endl;
        arrayReverseBegin++;
    }
}

/**
 * vector 使用迭代器输出
 */
void vectorIteratorTest() {
    vector<string> stringVector;//动态字符串数组，可以使用 clear()后反复利用这一块内存
    stringVector.push_back("firstStr");
    stringVector.push_back("secondStr");
    stringVector.push_back("thirdStr");
    vector<string>::iterator vectorBegin, vectorEnd;//迭代器
    vectorBegin = stringVector.begin();//数据起始点
    vectorEnd = stringVector.end();//数据结束点
    for (; vectorBegin != vectorEnd; vectorBegin++) {
        string tempStr = *vectorBegin;//获取指针指向的数据
        cout << "vector使用迭代器输出：" << tempStr << endl;
    }
}

void vectorTest() {
    vector<string> stringVector;//动态字符串数组，可以使用 clear()后反复利用这一块内存
    stringVector.push_back("firstStr");
    stringVector.push_back("secondStr");
    stringVector.push_back("thirdStr");
    for (int i = 0; i < stringVector.size(); ++i) {
        cout << stringVector[i] << " ";
    }
    cout << endl << "pop_back() 之前的 size:" << stringVector.size() << endl;
    stringVector.pop_back();//删除一个
    cout << "pop_back() 之后的 size:" << stringVector.size() << " &stringVecotor" << &stringVector << endl;
//    stringVector.clear();//清空整个 vector
    cout << "clear() 之后的 size:" << stringVector.size() << " &stringVecotor" << &stringVector << endl;
}

/**
 * 二维数组
 */
void twoDiamenArray() {
    array<int, 5> myArray1 = {11, 12, 13, 14, 15};
    array<int, 5> myArray2 = {21, 22, 23, 24, 25};
    array<int, 5> myArray3 = {31, 32, 33, 34, 35};
//    array<array<int,5>,3>twoDimArray={11,12,13,14,15,21,22,23,24,25,31,32,33,34,35};
    array<array<int, 5>, 3> twoDimArray = {myArray1, myArray2, myArray3};//同上
    for (int i = 0; i < twoDimArray.size(); i++) {
        for (int j = 0; j < twoDimArray[i].size(); ++j) {
            cout << twoDimArray[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * array 是静态数组，在栈上，要注意栈溢出，适用于任何类型
 * vector 是动态数组，在堆上，不需要管理内存
 */
void vectorAndarray() {//    array<double,1024*1024>myArray;//会栈溢出
    vector<double> myVector;//动态数组
    double db = 10.2;
    for (int i = 0; i < 1024 * 1024; i++) {//不会栈溢出
        myVector.push_back(db);
    }
}

void cppStringTest() {
//    array<string,5> stringArr = {"calculator", "ll", "open .", "ls", "write"};
    array<string, 4> stringArr = {"calculator", "ll", "ls", "write"};
    for (int i = 0; i < stringArr.size(); i++) {
        cout << stringArr[i] << endl;
        system(stringArr[i].c_str());
    }
    string string1 = "task";
    string string2 = "list";
    string string3 = string1 + string2;
    cout << "string string3 = string1+string2:" << string3 << endl;
    system("rm -rf a.out*");
}

void newArrTest1() {
    double db[4] = {1.1, 2.2, 3.5, 6.7};
//    double db2[4](db);//老版本的数组不可整体赋值
//    double db2[4] = db[4];
    array<double, 4> dbNew1 = {1.3, 2.2, 5.8, 9.6};
    array<double, 4> dbNew2 = dbNew1;//可以实现数组之间的整体操作
    for (int i = 0; i < dbNew1.size(); i++) {
        cout << "db[" << i << "]:" << db[i] << "  dbNew1[" << i << "]:" << dbNew1[i] << "   dbNew2[" << i << "]:" << dbNew2[i] << endl;
    }
}

