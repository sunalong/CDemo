//
// Created by sunalong on 16/12/29 15:17.
// Email:466210864@qq.com
//
#include <iostream>

using namespace std;
template <typename T>
inline T const & Max(T const &a,T const &b){
    return a<b?b:a;
}
int main(){
    cout<<"int比较：Max(39,20):"<<Max(39,20)<<endl;
    cout<<"double比较：Max(13.5,20.7):"<<Max(13.5,20.7)<<endl;
    cout<<"string比较：Max(\"Hello\",\"World\"):"<<Max("Hello","World")<<endl;
}
