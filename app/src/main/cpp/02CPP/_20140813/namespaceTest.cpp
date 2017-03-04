//
// Created by sunalong on 17/3/4 12:57.
// Email:466210864@qq.com
//
#include <iostream>
using  namespace std;
extern char * fuckStr;
namespace lalalalaallalala{
    int a(10);
    char *str("12312");
    char *strw("给命名空间起一个别名");
}
namespace  la = lalalalaallalala;
int main(){
    cout<<"调用命名空间的值：a:"<<la::a<<" str:"<<la::str<<" strw:"<<la::strw<<endl;
    cout<<"调用未引用头文件的其他文件的变量："<<::fuckStr<<endl;
    return 0;
}

