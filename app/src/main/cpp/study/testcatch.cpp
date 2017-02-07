//
// Created by sunalong on 17/2/4 18:30.
// Email:466210864@qq.com
//

#include <iostream>
#include <exception>
using namespace std;
class ExceptionClass
{
    char* name;
public:
    ExceptionClass(const char* name="default name")
    {
        cout<<"Construct "<<name<<endl;
        this->name=name;
    }
    ~ExceptionClass()
    {
        cout<<"Destruct "<<name<<endl;
    }
    void mythrow()
    {
        throw ExceptionClass("my throw");
    }
}
void main()
{
    ExceptionClass e("Test");
    try
    {
        e.mythrow();
    }
    catch(...)
    {
        cout<<”*********”<<endl;
    }
}
