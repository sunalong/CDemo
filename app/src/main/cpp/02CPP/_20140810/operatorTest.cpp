//
// Created by sunalong on 17/3/3 11:18.
// Email:466210864@qq.com
//
/**
 * 操作符重载
 */
#include <iostream>
/**
 * MacOS 与 Linux 不同，Linux 下少了下面三个头文件编译通不过
 * mac无所谓
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class mystring {
private:
    int id;
public:
    char *str;

    mystring() {
        this->str = new char[1024];
        cout << "mystring 无参构造函数 this:" << this << endl;
    }

    mystring(const mystring &itself) {
        this->str = new char[1024];
        memset(this->str, 0, 1024);
        strcpy(this->str, itself.str);
        cout << "mystring 拷贝构造函数 this:" << this << endl;
    }

    mystring operator=(const mystring &itself) {
        cout << "mystring 重载=操作符，类型const mystring &itself" << endl;
        memset(this->str, 0, 1024);
        strcpy(this->str, itself.str);
        return *this;
    }

    mystring operator=(const char *str) {
        cout << "mystring 重载=操作符，operator = (const char *str)" << endl;
        memset(this->str, 0, 1024);
        strcpy(this->str, str);
//        mystring s;
//        s = *this;
//        return s;
        return *this;
    }

    mystring operator=(int i) {
        cout << "mystring 重载=操作符，operator=(int i)" << endl;
        memset(this->str, 0, 1024);
        sprintf(this->str, "%d", i);
        return *this;
    }

    mystring operator+(const mystring &itself) {
        cout << "mystring 重载+操作符，operator+(const mystring &itself)" << endl;
        strcat(this->str, itself.str);
        return *this;
    }

    void operator+=(const char *str) {
        cout << "mystring 重载+=操作符，operator+=(const char* str)" << endl;
        strcat(this->str, str);
    }

    void operator++(int i) {//++的重载参数必须这样写（带个 int 类型的参数）
        this->str[0]++;//即将 str[0]对应的 ASCII 加1
        cout << "mystring 重载++操作符，operator++(int i):" << this->str[0] << i << endl;
    }

    void *operator new(size_t size) {
        mystring *p = (mystring *) malloc(size);
        //这里的 size就是 sizeof(mystring)的大小
        cout << "mystring 重载new操作符，operator new (size_t size):,size:" << size << " sizeof(mystring):" << sizeof(mystring) << endl;
        return p;
    }

    void operator delete(void *obj) {//重载 delete 操作符的固定写法
//        free((mystring*)obj);//不能直接 free 一个 void*
        cout << "1mystring 重载new操作符，operator delete(void *obj)" << endl;
        free(obj);//可以啊，已在 mac 和 unbutu 上验证
        obj = NULL;//防止野指针
        cout << "3mystring 重载new操作符，operator delete(void *obj)" << endl;
    }

    ~mystring() {
        delete[]this->str;
        cout << "mystring 析构函数 this:" << this << endl;
    }

    friend mystring operator*(const char *str, const mystring &it);
};

mystring operator+(const char *str, const mystring &it) {
    mystring str1;
    int len = strlen(str) + strlen(it.str);
//    char buf[len] = {0};//这一句为何编译不过？//error: variable-sized object may not be initialized
    char buf[2028] = {0};
//    char *buf = new char[len];//与上一句的区别？//动态分配内存？
    cout << "strlen(str):" << strlen(str) << " strlen(it.str)" << strlen(it.str) << " strlen(buf):" << strlen(buf) << endl;
    sprintf(buf, "%s%s", str, it.str);
    strcpy(str1.str, buf);
    return str1;
}

mystring operator*(const char *str, const mystring &it) {
    mystring str1;
    char buf[1024] = {0};
    sprintf(buf, "%s%d", str, it.id);
    strcpy(str1.str, buf);
    return str1;
}

void operatorEqualTest();

int main() {
    mystring str1;
    str1 = "firstStr";
    cout << "1.+号重载：" << str1.str << endl << endl;
    mystring str2;
    str2 = "secondStr";
    cout << "2.+号重载：" << str2.str << endl << endl;
    str1 = str1 + str2;
    cout << "3.+号重载：" << str1.str << endl << endl;

    mystring str3;
    str3 = "AAA" + str1;
    cout << "4.+号重载：" << str3.str << endl << endl;

    mystring str4;
    str4 = "aaa12" * str1;
    cout << "5.+号重载：" << str4.str << endl << endl;

    mystring str5;
//    str5 = "abc";
    str5 += "1234";
    cout << "6.+=号重载：" << str5.str << endl << endl;
    str5++;
    cout << "7.++号重载：" << str5.str << endl << endl;

    mystring *str6 = new mystring;
//    mystring *str6 =str5.new(5);
    cout << "8.new重载：" << str6->str << endl << endl;
    delete str6;
    cout << "9.delete 重载：" << str6->str << endl << endl;
//    operatorEqualTest();
    return 0;
}

/**
 * 对等号重载的测试
 */
void operatorEqualTest() {
    mystring str1;
    strcpy(str1.str, "helloWorld");
    cout << "1.str1.getStr:" << str1.str << endl << endl;
    mystring str2;
//    str2 = str1;//这个过程不是拷贝构造的过程，只是=号操作
    str2.operator=(str1);//与上行是一样的
    cout << "2.str2.getStr:" << str2.str << endl << endl;
    str2 = "test";
    cout << "3.str2.getStr:" << str2.str << endl << endl;

    str2 = 102;
    cout << "4.str2.getStr:" << str2.str << endl << endl;

    mystring str3;
//    str3 = str2 = 102;
    str3 = str2.operator=(102);//等效于上一条语句
    cout << "4.str2.getStr:" << str2.str << endl << endl;
}
