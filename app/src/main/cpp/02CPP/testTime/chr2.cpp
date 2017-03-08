//
// Created by sunalong on 17/3/8 20:00.
// Email:466210864@qq.com
//

//duration还有一个成员函数count()返回Rep类型的Period数量，看代码：

// duration::count
#include <iostream>     // std::cout
#include <chrono>       // std::chrono::seconds, std::chrono::milliseconds
//#include "../../../../../../../../Library/Android/sdk/ndk-bundle/sources/cxx-stl/gnu-libstdc++/4.9/include/chrono"
// std::chrono::duration_cast

int main ()
{
    using namespace std::chrono;
    // std::chrono::milliseconds is an instatiation of std::chrono::duration:
    milliseconds foo (1000); // 1 second
    foo*=60;

    std::cout << "duration (in periods): ";
    std::cout << foo.count() << " milliseconds.\n";

    std::cout << "duration (in seconds): ";
    std::cout << foo.count() * milliseconds::period::num / milliseconds::period::den;
    std::cout << " seconds.\n";

    nanoseconds foo2(100000000000);
    foo2*=60000000;
    std::cout << "2.duration (in periods): ";
    std::cout << foo.count() << " milliseconds.\n";
    return 0;
}
