//
// Created by sunalong on 17/3/6 14:16.
// Email:466210864@qq.com
//
#include <iostream>

void refTwoDiaArr();

using namespace std;

int add(int a, int b);

int minusMy(int a, int b);

void change(int (*&rp)(int, int));

void funcPointer();

void testReturnFuncRefer();

void referArr();

void sizeofMyClass();

/**
 * 返回值为函数指针的引用的函数
 * 返回值为：int (*&changep(int (*&rp)(int, int)))
 * 参数为两个 int类型
 * int (*p)(int a, int b) = add;//初始化一个函数指针p
 * int (*p)(int a, int b)(add);//初始化一个函数指针p，与上一步相同
 */
int (*&changep(int (*&rp)(int, int)))(int, int) {
    rp = add;
    return rp;
}

struct mystr {
    int a;
    char c;
    double b;//此行位置不同，sizeof(mystr)大小不同

    void go() {//代码区的函数不计入结构体的 sizeof
        cout << "struct mystr void go():" << "sizeof(a):" << sizeof(a) << " sizeof(b):" << sizeof(b) << " sizeof(c):" << sizeof(c) << endl;
    }
};

class MyClass1 {
    //sizeof(MyClass1)=24;
    int a;
    double b;
    int c;

    void go() {//代码区的函数不计入结构体的 sizeof
        cout << "struct mystr void go():" << "sizeof(a):" << sizeof(a) << " sizeof(b):" << sizeof(b) << " sizeof(c):" << sizeof(c) << endl;
    }
};

class MyClass2 {
    //sizeof(MyClass)=3;
    char a;
    char b;
    char c;//引用的本质是指针，指针用 int 类型来存储，直接 sizeof 引用，就是求引用的数据大小
};

class MyClass {
//x64位的指针是8 个字节，sizeof(MyClass)=24;
//x32位的指针是4 个字节，sizeof(MyClass)=12;
    char &a;
    char &b;
    char &c;//引用的本质是指针，指针用 int 类型来存储，直接 sizeof 引用，就是求引用的数据大小
};
int getData(int &&num);
int main() {
    int a=3,b=4;
//    cout<<getData(a)<<endl;//参数必须是右值
    //std::move():将左值转化为右值，c++11 的语法
    cout<<"使用 std::move 将左值转化为右值："<<getData(std::move(a))<<endl;//把左值转化为右值
    cout<<getData(a+1)<<endl;//
//    cout<<getData()<<endl;//
//    sizeofMyClass();
//    referArr();
    //    testReturnFuncRefer();
//    funcPointer();
    //    refTwoDiaArr();
    return 0;
}
int getData(int &&num){//右值引用，节约内存拷贝，内存优化所必须
    cout<<"getData num:"<<num<<endl;
    num+=10;
    return num;
}
/**
 * 测试 myclass 类的大小
 */
void sizeofMyClass() {
    int a;
    char c;
    double b;
    cout << "sizeof(a):" << sizeof(a) << " sizeof(b):" << sizeof(b) << " sizeof(c):" << sizeof(c) << endl;
    cout << "struct sizeof:" << sizeof(mystr) << endl;
    mystr mystr1;
    mystr1.go();
    cout << "MyClass1的 sizeof:" << sizeof(MyClass1) << endl;
    cout << "MyClass2的 sizeof:" << sizeof(MyClass2) << endl;
    cout << "MyClass的 sizeof:" << sizeof(MyClass) << endl;
}

void referArr() {
    int a = 1, b = 3, c = 7;
    int *px[3] = {&a, &b, &c};
//    int &p[3] = {a, b, c};//引用数组是非法的
    // error: 'p' declared as array of references of type 'int &'

    for (int i = 0; i < 3; i++) {
        cout << "*px[i]:" << *px[i] << "  px[i]:" << px[i] << endl;
    }
}

/**
 * 测试返回值为函数指针的引用的函数
 */
void testReturnFuncRefer() {
    int (*p)(int a, int b)(minusMy);
    cout << "调用函数指针：" << p(2, 5) << endl;
    p = changep(p);
    cout << "调用函数指针：" << p(2, 5) << endl;
}

/**
 * 函数指针的测试
 */
void funcPointer() {
//    int (*p)(int a, int b) = add;//初始化一个函数指针p
    int (*p)(int a, int b)(add);//初始化一个函数指针p，与上一步相同
    int sum = p(3, 9);//调用函数指针
    cout << "调用函数指针：p(3,9):" << sum << endl;
    int (*&rp)(int a, int b)(p);//引用函数指针 p
    cout << "调用函数指针的引用：" << rp(2, 6) << endl;
//    rp(minusMy);//（）只能用于初始化时的赋值
    rp = minusMy;
    cout << "调用函数指针的引用：" << rp(2, 6) << endl;
    change(p);//通过函数来改变函数指针
    cout << "通过函数来改变函数指针：" << rp(2, 6) << endl;
}

/**
 * 通过函数来改变函数指针
 */
void change(int (*&rp)(int, int)) {//函数指针的引用作为参数
    rp = add;
}

int add(int a, int b) {
    return a + b;
}

int minusMy(int a, int b) {
    return a - b;
}

/**
 * 引用二维数组
 */
void refTwoDiaArr() {
    int a[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (&ra)[2][5](a);//引用就是给原来的变量加一个别名，与原来的变量同一个地址
    int i = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            cout << " " << ra[i][j];
        }
        cout << endl;
    }
    cout << "  a:" << a << "  &a:" << &a << endl;
    cout << " ra:" << ra << " &ra:" << &ra << endl;
    /**
     *   a:0x7fff52d7da30  &a:0x7fff52d7da30
     *  ra:0x7fff52d7da30 &ra:0x7fff52d7da30
     */
}
