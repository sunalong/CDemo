//
// Created by sunalong on 16/12/29 11:18.
// Email:466210864@qq.com
//
#include <iostream>
using namespace std;
struct Book{
    char title[30];
    int bookId;
};

void printBook(Book *pBook);

int main(){
//    struct Book book;
    Book book;
    strcpy(book.title,"Learn C++ Programming");
    book.bookId = 6495407;

    printBook(&book);
    return 0;
}

void printBook(Book *pBook) {
    cout<<"*pBook无法打印，&(*pBook)："<<&(*pBook)<<"  *(&pBook):"<<*(&pBook)<<"  pBook:"<<pBook<<" &pBook:"<<&pBook<<endl;
    cout << "&(pBook->title):  " << &(pBook->title)<< "    &(*pBook).title:"<<&((*pBook).title)<< " &(pBook->id):  " << &(pBook->bookId)<<endl;
    cout << "(*pBook).title:    " << (*pBook).title<< "\npBook->bookId:  " <<pBook->bookId<< endl;
    cout << "pBook->title:  " << pBook->title<< "\npBook->bookId:    " <<pBook->bookId<< endl;
}
