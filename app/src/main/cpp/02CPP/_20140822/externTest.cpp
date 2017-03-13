//
// Created by sunalong on 17/3/13 14:12.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>

using namespace std;

class Father {
private:
    char *priChar;
protected:
    char *protChar;
    void proMethod() {
        cout << "父类的 protected 方法" << endl;
    }
public:
    char *pubChar;

    Father() {
        priChar = new char;
        priChar = "F priChar";
        protChar = new char;
        protChar = "F proChar";
        pubChar = new char;
        pubChar = "F pubChar";
        cout << "Father()" << endl;
    }

    ~Father() {
        cout << "~Father()" << endl;
    }

    void callInClass() {
        cout << "父类的公有方法"<<endl;
    }
};

class PubSon : public Father {
public:
    PubSon() {
        cout << "PubSon()" << endl;
    }

    ~PubSon() {
        cout << "~PubSon()" << endl;
    }

    void callInClass() {
        cout << "子类覆盖父类的公有方法"<<endl;
    }
};

class ProSon : protected Father {
public:
    ProSon() {
        cout << "ProSon()" << endl;
    }

    ~ProSon() {
        cout << "~ProSon()" << endl;
    }

    void callInClass() {
        cout << "子类覆盖父类的公有方法"<<endl;
    }
};

int main() {
    Father father;
    father.callInClass();
//    father.proMethod();
    cout << "protect 方法在类外部无法调用，只能本类调用" << endl << endl;

    PubSon pubSon;
    pubSon.callInClass();
    pubSon.Father::callInClass();
    cout << "public 继承属于原样继承，不改变父类在子类中的属性" << endl << endl;

    ProSon proSon;
    proSon.callInClass();
//    proSon.Father::callInClass();
    cout<<"protected 继承会将原 public 成员改成 protected,这样父类的 public 方法无法在外部子类外部被调用"<<endl<<endl;
    system("rm -rf a.out*");
    return 0;
}

