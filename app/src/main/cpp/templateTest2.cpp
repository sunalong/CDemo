//
// Created by sunalong on 16/12/29 15:30.
// Email:466210864@qq.com
//

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template<class T>
class Stack {
private:
    vector<T> elems;//元素
public:
    void push(T const &);//入栈
    void pop();//出栈
    T top() const;//返回栈顶元素
    bool empty() const {//如果为空则返回真
        return elems.empty();
    }

};

template<class T>
void Stack<T>::push(T const &elem) {
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("stack<>::pop():empth stack");
    }
    elems.pop_back();//删除最后一个元素
}

template<class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw out_of_range("stack<>::pop():empth stack");
    }
    return elems.back();//返回最后一个元素的副本
}

int main() {
    try {
        Stack<int> intStack;//int 类型的栈
        Stack<string> stringStack;//string 类型的栈

        intStack.push(7);
        cout << intStack.top() << endl;

        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    } catch (exception const &ex) {
        cerr << "Exception:" << ex.what() << endl;
        return -1;
    }
}
