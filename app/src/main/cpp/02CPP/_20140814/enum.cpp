//
// Created by sunalong on 17/3/6 17:26.
// Email:466210864@qq.com
//

#include <iostream>

using namespace std;
enum Color1 : char {//C++11 语法：g++ -g -Wall -std=c++11 enum.cpp
    red='B', yellow=3, green, white
};
enum Color2  {//C++11 语法：g++ -g -Wall -std=c++11 enum.cpp
    red2='B', yellow2=3, green2, white2
};

int main() {
    Color1 mycolor = red;
//    mycolor = 'A';//确保在枚举的范围内不出错
//    mycolor = 2;//确保在枚举的范围内不出错
    mycolor = Color1::white;
    cout << "mycolor:" << mycolor << " typeid:" << typeid(mycolor).name() << endl;
    printf("%d,%c\n",red,red);
    printf("%d,%c\n",green,green);
}
