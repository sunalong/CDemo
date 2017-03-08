//
// Created by sunalong on 17/3/8 20:09.
// Email:466210864@qq.com
//
// steady_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main() {
    using namespace std::chrono;

    steady_clock::time_point t1 = steady_clock::now();
//    std::cout << "1,t1:" << t1.count() << std::endl;
    std::cout << "printing out 1000 stars...\n";
    for (int i = 0; i < 1000; ++i) std::cout << "*";
    std::cout << std::endl;

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
//    g++ -g -Wall -std=c++11 chronoTest.cpp
//    It took me 0.000151389 seconds.
    return 0;
}

