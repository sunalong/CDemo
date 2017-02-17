//
// Created by sunalong on 17/2/7 15:29.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
double vals[] = {10.1,12.6,33.6};
double & setValues(int i){
    return vals[i];//返回第 i个元素的引用
}
int main(){
    cout<<"改变前的值："<<endl;
    for(int i=0;i<3;i++){
        cout<<"vals["<<i<<"]="<<vals[i]<<endl;
    }
    setValues(1) = 5.8;//改变第2 个元素
    setValues(2) = 8.7;//改变第3 个元素
    cout<<"改变前的值："<<endl;
    for(int i=0;i<3;i++){
        cout<<"vals["<<i<<"]="<<vals[i]<<endl;
    }
    return 0;
}

