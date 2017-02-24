//
// Created by sunalong on 17/1/6 15:05.
// Email:466210864@qq.com
//

#include <iostream>
#include <exception>

using namespace std;

class ExceptionClass {
    int nameL;
public:
    ExceptionClass(int name) {
        cout << "Construct " << name << endl;
        nameL = name;
    }
    ~ExceptionClass() {
        cout << "Destruct " << nameL << endl;
    }
    void mythrow(int throMY) {
        throw ExceptionClass(throMY);
    }
};

int main() {
    try {
        float i = 1;
        float x = i/0;
        cout << "my xxxxx*********" << x<<endl;

        ExceptionClass e(i);
        cout << "my 111111*********" << endl;
//        if (!(i / 0)) {
            cout << "my error*********" << endl;
            e.mythrow(1/0);
//        }
        cout << "my 2222222*********" << i << endl;
    }
    catch (...) {
        cout << "my *********" << endl;
//        return -1;
    }

    cout << "my other*********" << endl;
    return 0;
}
//    ExceptionClass e("Test");
//    try {
//        e.mythrow();
//    }
//    catch (...) {
//        cout << "*********" << endl;
//        return -1;
//    }


//
//struct MyException : public exception
//{
//    const char * what () const throw ()
//    {
//        return "C++ Exception";
//    }
//};
//
//int main()
//{
//    try
//    {
//        throw MyException();
//    }
//    catch(MyException& e)
//    {
//        std::cout << "MyException caught" << std::endl;
//        std::cout << e.what() << std::endl;
//    }
//    catch(std::exception& e)
//    {
//        //其他的错误
//    }
//}