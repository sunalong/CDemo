//
// Created by sunalong on 17/3/4 23:08.
// Email:466210864@qq.com
//
#include <iostream>

void pointerAndReference();

void referenceRightValue();
int &get();

void stackReference();
int* &getData();

void heapReference();

void reference();

using namespace std;

int main() {

    heapReference();
//    stackReference();
//    referenceRightValue();
//    pointerAndReference();
//    reference();
    return 0;
}

void reference() {
    int num1 = 10;
    int &rnumLeft = num1;//左值引用
    int * &&rnumRight = &num1;//右值引用

}

/**
 * 对堆内存的引用
 */
void heapReference() {
    int *& rp = getData();
    int *p = rp;//创建一个指针，指向引用变量rpM所指向的内存地址，这个内存地址是堆内存地址
    cout<<*rp<<endl;//此后rp是 getData 函数返回的引用变量rpM的别名，getData调用完后，函数内的引用变量rpM被回收，但rpM指向的内存是堆内存，不会被回收，依然存在
    cout<<"指针的引用：*p:"<<*p<<endl;
    cout<<*rp<<endl;
    cout<<"after delete指针的引用：*p:"<<*p<<" &p:"<<&p<<endl;
    delete(p);
    cout<<"after delete指针的引用：*p:"<<*p<<" &p:"<<&p<<endl;

    int * pp = getData();
    cout<<"before delete指针的引用：*pp:"<<*pp<<" &pp:"<<&pp<<endl;
    cout<<"before delete指针的引用：*pp:"<<*pp<<" &pp:"<<&pp<<endl;
    delete(pp);//此时需要手动调用 delete 函数来将getData 中分配的堆内存回收
    cout<<"after delete 指针的引用：*pp:"<<*pp<<" &pp:"<<&pp<<endl;
    cout<<"after delete 指针的引用：*pp:"<<*pp<<" &pp:"<<&pp<<endl;

    //即：不能使用返回值为指针的引用为指针的引用赋值，
    //   应该使用返回值为指针的引用为指针变量赋值。
    //   否则会出现意外
//mac 与 unbuntu 的delete不同，mac delete 后 pp 的值不变，这是不对的，ubuntu 中会变
//    可考虑卸载 mac 的 gcc 使用源码安装官方版的，免得 mac 改的面目全非
// mac的输出：
//    $ referenceTest
//    10
//    指针的引用：*p:10
//    1988511704
//    after delete指针的引用：*p:10 &p:0x7fff51925958
//    after delete指针的引用：*p:10 &p:0x7fff51925958
//    before delete指针的引用：*pp:10 &pp:0x7fff51925950
//    before delete指针的引用：*pp:10 &pp:0x7fff51925950
//    after delete 指针的引用：*pp:10 &pp:0x7fff51925950
//    after delete 指针的引用：*pp:10 &pp:0x7fff51925950
// ubuntu 的输出：
//    $ ./referencePointer
//    10
//    指针的引用：*p:10
//             -1064971727
//    before指针的引用：*p:10 &p:0x7fff8d9d26c0
//    after delete指针的引用：*p:0 &p:0x7fff8d9d26c0
//    before delete指针的引用：*pp:10 &pp:0x7fff8d9d26c8
//    before delete指针的引用：*pp:10 &pp:0x7fff8d9d26c8
//    after delete指针的引用：*pp:0 &pp:0x7fff8d9d26c8
//    after delete指针的引用：*pp:0 &pp:0x7fff8d9d26c8

}

int* &getData(){//返回一个指针的引用
    int *p ;//p 在栈上，
    p= new int;//p 指向的值是堆上的内存
    *p = 10;
    int *&rpM = p;//引用指针
    return rpM;//返回引用的指针,p 指向的内存在堆上，但它的引用在栈上，return 后，栈上的p被回收，但它之前指向的内存还在堆上，没被回收
//    return p;
}
/**
 * 对栈内存中的引用
 */
void stackReference() {
    int &ra = get();
    cout<<ra<<endl;//10，执行完这句后，栈内存被回收，但还没被再次分配利用
    cout<<ra<<endl;//32767，此时栈内存被分配利用,内存发生变化

}

int &get(){
    int a = 10;//a 在栈上，函数启动分配内存，执行完后回收内存
    int &ra = a;
    return ra;
}
/**
 * 引用右值
 */
void referenceRightValue() {
    int num1 = 5;
    int *pnum;//左值的引用就是右值
    pnum = &num1;//&num1 在寄存器中
    cout << "1. *pnum:" << *pnum << " pnum:" << pnum << " &pnum:" << &pnum << endl;
//    int *& rpnum = &num1;//non-const lvalue reference to type 'int *' ,cannot bind to a temporary of type 'int *'
    int &rnum = num1;//左值引用 对 num1 的引用，ok
    int *&&rpnum1 = &num1;//右值引用，*与&可看成相抵消，ok
    cout << "1. *rpnum1:" << *rpnum1 << " rpnum1:" << rpnum1 << " &rpnum1:" << &rpnum1 << endl;
    int *&rpnum2 = pnum;//可以
    cout << "1. *rpnum2:" << *rpnum2 << " rpnum2:" << rpnum2 << " &rpnum2:" << &rpnum2 << endl;
}

/**
 * 指针与引用
 */
void pointerAndReference() {
    int num1 = 5;
    int num2 = 10;
    int *pnum = &num1;
    cout << "1. *pnum:" << *pnum << " pnum:" << pnum << " &pnum:" << &pnum << endl;
    int *&rpnum = pnum;//指针的引用
    rpnum = &num2;//引用改变了指针的地址指向
    cout << "2. *pnum:" << *pnum << " pnum:" << pnum << " &pnum:" << &pnum << endl;

    *rpnum = 100;//引用改变了指针指向的值
    cout << "3. *pnum:" << *pnum << " pnum:" << pnum << " &pnum:" << &pnum << endl;
    cout << "3. num1:" << num1 << " &num1:" << &num1 << endl;
    cout << "3. num2:" << num2 << " &num2:" << &num2 << endl;
}
