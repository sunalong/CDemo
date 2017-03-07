//
// Created by sunalong on 17/3/7 17:05.
// Email:466210864@qq.com
//
/**
 * 私有类的模板覆盖
 */
#include <iostream>
#include <string>
using namespace std;

class Info{
public:
    char name[40];
    char *p;
    int data;
private:
    int num;
public:
    int getNum() const {
        return num;//返回值，副本机制
    }

    void setNum(int num) {
        Info::num = num;
    }
};
template <typename T> void myswap(T &a,T &b){
    cout<<"通用函数模板"<<endl;
    T temp = a;
    a = b;
    b = temp;//交换两个变量
}
template <>void myswap(Info &info1,Info &info2){
    cout<<"特有函数模板"<<endl;
    //通用模板可以实现通用，针对自己的数据类型做出优化
    Info temp = info1;
    info1 = info2;
    info2 = temp;
}
int main(){
    Info info1;
    Info info2;
    strcpy(info1.name,"name1");
    info1.data = 102;
    info1.p = new char[10];
    strcpy(info1.p,"plala");

    info2.data = 201;
    info2.p = new char[20];
    strcpy(info2.p,"lalap");
    strcpy(info2.name,"name2");
    cout<<"before swap info1:"<<info1.name<<" "<<info1.data<<" "<<info1.getNum()<<" "<<info1.p<<endl;
    cout<<"before swap info2:"<<info2.name<<" "<<info2.data<<" "<<info2.getNum()<<" "<<info2.p<<endl;
    myswap(info1,info2);
    cout<<"after  swap info1:"<<info1.name<<" "<<info1.data<<" "<<info1.getNum()<<" "<<info1.p<<endl;
    cout<<"after  swap info2:"<<info2.name<<" "<<info2.data<<" "<<info2.getNum()<<" "<<info2.p<<endl;
    return 0;
}
