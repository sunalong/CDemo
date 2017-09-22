//
// Created by sunalong on 17/5/18 17:13.
// Email:466210864@qq.com
//
#include<iostream>
#include<stdlib.h>
using namespace std;

void loginNormal(string id);
//void login(string &id);
void loginP(const string *id);
void useString();


int main() {
    system("rm -rf a.out*");
    string personId="abc12345";//要确保不被改变
    cout << "使用 String" << endl;
    useString();


    cout<<"调用loginP前："<<personId<<"  personId地址："<<&personId<<endl;
    cout<<"loginP："<<personId<<endl;
    loginP(&personId);
    cout<<"调用后login："<<personId<<endl<<endl;

    cout<<"调用login前："<<personId<<"  personId地址："<<&personId<<endl;
    loginNormal(personId);
    cout<<"调用后login："<<personId<<"  personId地址："<<&personId<<endl<<endl;

//    cout<<"调用login前："<<personId<<"  personId地址："<<&personId<<endl;
//    login(personId);
//    cout<<"调用后login："<<personId<<"  personId地址："<<&personId<<endl<<endl;

    return 0;
}

void useString() {
    char charArr[] = "aou";
    char *rawStr;
    rawStr = charArr;
    string str = "";
    cout << "charArr:" << charArr << "  rawStr:" << rawStr << " *(rawStr + 1):" << *(rawStr + 1) << "  (rawStr + 1):" << (rawStr + 1) << endl;
    for (int i = 0; i < strlen(rawStr); i++) {
        str += *(rawStr + i) + i;//cqw
        cout << "str:" << str << " rawStr:" << rawStr << endl;
    }
    cout << "Done str:" << str << " rawStr:" << rawStr << endl << endl;
}
void loginNormal(string id) {
    cout<<"before 传进来的值："<<id<<"  id地址："<<&id<<endl;
//    id++;
    cout<<"after 传进来的值："<<id<<endl;
    //非法改变id的值
    string * changeId = &id;
//    (*changeId)=(*changeId)+5;
    cout<<"改变传进来的值："<<*changeId<<" "<<changeId<<" "<<&changeId<<endl;

}
void login(string &id) {
    cout<<"before 传进来的值："<<id<<"  id地址："<<&id<<endl;
//    id++;
    cout<<"after 传进来的值："<<id<<endl;
    //非法改变id的值
    string * changeId = &id;
//    (*changeId)=(*changeId)+5;
    cout<<"改变传进来的值："<<*changeId<<" "<<changeId<<" "<<&changeId<<endl;

}
void loginP(const string *id) {
    cout<<"before 传进来的值："<<*id<<" 地址："<<id<<endl;
//    id++;
    cout<<"after 传进来的值："<<*id<<endl;
}

