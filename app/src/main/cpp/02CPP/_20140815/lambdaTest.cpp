//
// Created by sunalong on 17/3/7 23:11.
// Email:466210864@qq.com
//
/**
 * lambda 表达式，不仅仅适用于 array,也适用于 vector
 */
#include<iostream>
#include <vector>
#include<algorithm>//算法
#include <tuple>

void lambdaTest();

void vectorList();

void vectorCRUD();

void tupleTest();

using namespace std;

int main() {

//    lambdaTest();
//    vectorList();
//    vectorCRUD();
    tupleTest();
    system("rm -rf a.out*");
    return 0;
}
/**
 * tuple 多元数组
 */
void tupleTest() {
    int i = 2;
    double db = 2.3;
    char ch = 'B';
    char *str = "HelloWorld";
    tuple<int, double, char, const char *> myTuple(i, db, ch, str);
    auto data0 = get<0>(myTuple);
    auto data1 = get<1>(myTuple);
    auto data2 = get<2>(myTuple);
    auto data3 = get<3>(myTuple);
    cout<< typeid(data3).name()<<endl;
    cout<<data0<<" "<<data1<<" "<<data2<<" "<<data3<<endl;
}

/**
 * 对 vector 的增删改查
 */
void vectorCRUD() {
    vector<int> myVector(2);//分配2 个空间，默认初始化为0
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    for (int i = 0; i < myVector.size(); ++i) {
        cout << "初始化并 push_back 后：" << myVector.at(i) << endl;
    }
//    myVector.pop_back();//删除最后一个元素
    myVector.at(3) = 333;
    for (int i = 0; i < myVector.size(); ++i) {
        cout << "myVector.at(3) = 333修改后:" << myVector.at(i) << endl;
    }
    myVector.erase(myVector.begin() + 2);//删除迭代器指定的位置（3）
    for (int i = 0; i < myVector.size(); ++i) {
        cout << "myVector.erase(myVector.begin() + 2)erase 后:" << myVector.at(i) << endl;
    }
    myVector.insert(myVector.begin() + 3, 999);//在迭代器指定的位置插入元素
    for (int i = 0; i < myVector.size(); ++i) {
        cout << "myVector.insert(myVector.begin()+3,999)insert 后:" << myVector.at(i) << endl;
    }
}

/**
 * vector 嵌套
 */
void vectorList() {
    vector<int> myVector1;
    myVector1.push_back(12);
    myVector1.push_back(13);
    myVector1.push_back(14);
    vector<int> myVecotr2;
    myVecotr2.push_back(22);
    vector<int> myVector3;
    myVector3.push_back(31);
    myVector3.push_back(32);
    vector<vector<int>> allVector;
    allVector.push_back(myVector1);
    allVector.push_back(myVecotr2);
    allVector.push_back(myVector3);
    for (int i = 0; i < allVector.size(); ++i) {
        for (int j = 0; j < allVector[i].size(); ++j) {
            cout << allVector[i][j] << " ";
        }
        cout << endl;
    }
}

void lambdaTest() {
    vector<int> myVector;
    myVector.push_back(11);
    myVector.push_back(22);
    myVector.push_back(33);
    int res = 0;//结果
    for_each(myVector.begin(), myVector.end(), [&res](int x) { res += x; });
    cout << "经过 lambda 表达式计算后，res=" << res << endl;
}
