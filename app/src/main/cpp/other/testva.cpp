//
// Created by sunalong on 17/3/21.
//
#include <iostream>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

int demo(char *, ...);

void fun(int a, ...);

int main() {
    demo("Demo", "This", "is", "a", "demo!", "");
    int a = 23;
    int b = 56;
    int c = 72;
    int d = 26;
    fun(4, a, b, c, d);
    system("rm -rf a.out*");
    return EXIT_SUCCESS;
}

void fun(int a, ...) {
    int *temp = &a;
    temp++;
    va_list apList;
    va_start(apList,a);
    int tempArgs;
    for (int i = 0; i < a; ++i) {
        tempArgs = va_arg(apList,int);
        cout<<"i="<<i<<" *temp:"<<*temp<<endl;
        temp++;
    }
}

int demo(char *msg, ...) {
    va_list argp;
    int argno = 0;
    char *para;

    va_start(argp, msg);
    while (1) {
        para = va_arg(argp, char*);
        if (strcmp(para, "") == 0)
            break;
        cout << "parameter #" << argno << " is :" << para << endl;
        argno++;
    }
    va_end(argp);
    return 0;
}