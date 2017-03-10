//
// Created by sunalong on 17/3/10 15:21.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class MyComplex {
public:
    //友元，需要操作类的内部
    friend MyComplex operator+(MyComplex myComplex, int x);

    friend MyComplex operator+(MyComplex addData1, MyComplex addData2);

    friend istream &operator>>(istream &in, MyComplex &myComplex);

    friend ostream &operator<<(ostream &out, MyComplex &myComplex);

private:
    int x, y;
public:
    MyComplex() {
        x = 0;
        y = 0;
    }

    MyComplex(int x, int b) : x(x), y(b) {

    }

    ~MyComplex() {
        cout << " ~MyComplex()" << endl;
    }

    void show() {
        cout << "void show:" << x << "+" << y << "i" << endl;
    }

    void operator++() {
        this->x++;
        this->y++;
    }

    void operator--() {
        x--;
        y--;
    }

    int operator()(int num) {
        cout << "int operator(): num:" << num << endl;
        return num * 2;
    }
};

ostream &operator<<(ostream &out, MyComplex &myComplex) {
    out << "ostream &operator<<: " << myComplex.x << "+" << myComplex.y << "i" << endl;
    return out;
}

istream &operator>>(istream &in, MyComplex &myComplex) {
    cout << "请输入x,y 的值：" << endl;
    in >> myComplex.x >> myComplex.y;
    return in;
}

MyComplex operator+(MyComplex addData1, MyComplex addData2) {
    MyComplex temp;
    temp.x = addData1.x + addData2.x;
    temp.y = addData1.y + addData2.y;
    return temp;
}

MyComplex operator+(MyComplex myComplex, int x) {
    MyComplex temp;
    temp.x = myComplex.x + x;
    temp.y = myComplex.y + x;
    return temp;
}

int main() {
    MyComplex myComplex(7, 9), myComplex1(2, 8);
//    cout << "myComplex+myComplex1:" << myComplex + myComplex1 << endl;
    std::cout << myComplex + myComplex1 << std::endl;
    cout << myComplex + 3 << endl;
//    cout << "myComplex+3:" << myComplex + 3 << endl;

    MyComplex myComplex2;
    cin >> myComplex2;
    cout << myComplex2;
//    ++myComplex2;
    myComplex2++;
    cout << myComplex2;
    myComplex2--;
    cout << myComplex2;
    cout << "myComplex2(1) :" << myComplex2(1) << endl;
    cout << "myComplex2(2) :" << myComplex2(2) << endl;

    MyComplex myComplex3(6, 9);
    int num;
    cin >> num;
    system("rm -rf a.out*");
    return 0;
}