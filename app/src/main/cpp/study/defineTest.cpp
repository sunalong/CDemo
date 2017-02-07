//
// Created by sunalong on 16/12/23 18:31.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;
#define PI 3.1415926
#define TEST
#define MIN(a, b) ((a<b)?a:b)

int main() {
    cout << "value of PI:" << PI << endl;

#ifdef TEST
    cerr << "Trace: run into ifdef TEST" << endl;
#endif

#if 0
    cout<<" #if 0:被注释掉了，不执行这一块"<<endl;
#endif

#if 1
    cout<<" #if 1:没被注释掉了，执行这一块"<<endl;
#endif
    cout << "The minimum is " << MIN(4, 10) << endl;

#ifdef TEST
    cerr << "Trace: run into ifdef TEST,coming out main……" << endl;
#endif
    return 0;
}