//
// Created by sunalong on 17/3/1 11:56.
// Email:466210864@qq.com
//

#ifndef CDEMO_MYSTRING_H
#define CDEMO_MYSTRING_H

class MyString {
private:
    static MyString *instance;
    char * str;
protected:
    MyString();

    MyString(const char *s);

    ~MyString();

public:
    static MyString *makeString(const char *s);

    char *getStr() const;

    void setStr(const char *str);

    void initStr(const char *s);
};

#endif //CDEMO_MYSTRING_H
