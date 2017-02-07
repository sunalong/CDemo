//
// Created by sunalong on 16/12/28 16:54.
// Email:466210864@qq.com
//

#include<iostream>
#include <iomanip>

using namespace std;
struct Books {
    char title[50];
    int bookId;
};

void printBook1(Books &book);

void printBook2(Books book);

void printBook3(struct Books book);

int main() {
    struct Books book1;//声明 book1,类型为 Book

    strcpy(book1.title, "learn c++ programming");
    book1.bookId = 6495407;

    printBook1(book1);
    printBook2(book1);
    printBook3(book1);
    return 0;
}

void printBook1(Books &book) {
    cout << "title:  " << book.title << "\nid: " << book.bookId << endl;
}

void printBook2(struct Books book) {
    cout << "title:  " << book.title << "\nid: " << book.bookId << endl;
}

void printBook3(struct Books book) {
    cout << "title:  " << book.title << "\nid: " << book.bookId << endl;
}
