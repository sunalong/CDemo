//
// Created by sunalong on 17/3/13 14:12.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class Father {

public:
    static int num;

    Father() {
        num++;
        cout << "Father(),num:" << num << endl;
    }

    ~Father() {
        num--;
        cout << "~Father(),num:" << num << endl;
    }
};

int Father::num = 0;

class PubSon : public Father {
public:
    PubSon() {
        num++;
        cout << "PubSon(),num:" << num << endl;
    }

    ~PubSon() {
        num--;
        cout << "~PubSon(),num:" << num << endl;
    }
};

class GradSon : public PubSon {
public:
    GradSon() {
        num++;
        cout << "GradSon(),num:" << num << endl;
    }

    ~GradSon() {
        num--;
        cout << "~GradSon(),num:" << num << endl;
    }

};

int main() {
    Father father;
    cout << "" << endl;
    PubSon pubSon;
    cout << "" << endl;

    GradSon gradSon;
    cout << "gradSon:"<<GradSon::num <<endl<<endl;

    system("rm -rf a.out*");
    return 0;
}