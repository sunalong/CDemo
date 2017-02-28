//
// Created by sunalong on 17/2/27 20:36.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;
/**
 * 命名空间可理解为 java 中的 package，
 * 使用某个命名空间就相当于 Java 中引入某个包
 */
namespace self {
    void func(int a) {
        cout << "使用命名空间是 self 的函数 a:" << a << endl;
    }
}
namespace other {
    void func(int a) {
        cout << "使用命名空间是 other 的函数 a:" << a << endl;
    }
}
using namespace other;
int main() {
    func(10);
    self::func(4);
    other::func(2);
    return 0;
}