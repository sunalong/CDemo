//
// Created by sunalong on 17/2/28 21:23.
// Email:466210864@qq.com
//

#ifndef CDEMO_SINGLE_H
#define CDEMO_SINGLE_H
class single{
private:
    static single * p;
    int num;
    single();
public:
    ~single();
    static single* getInstance();
    static void releaseInstance();

    int getNum() const;

    void setNum(int num);
};
#endif //CDEMO_SINGLE_H
