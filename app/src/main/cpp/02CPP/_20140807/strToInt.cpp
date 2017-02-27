//
// Created by sunalong on 17/2/27 12:42.
// Email:466210864@qq.com
//
#include <iostream>
#include <stdio.h>
void print();

using namespace std;

/**
 * 把字符串转化为整数：
 * 如把“321”转化为321
 * 但“但32a”无法转化为整数
 */
int toNUm(char *str){
    char *istr = str;//保留副本
    int num =0;
    while(*str !='\0'){
        if(*str<'0' || *str>'9')
            return -1;
        *str++;;
        num++;//计数，判断有多少位
    }
    int result =0;
    for(int i=0;i<num;i++){
        result*=10;
        int wei = istr[i]-48;
        result+=wei;
        printf("转化%s,到第%d位时结果为%d\n",istr,i,result);
    }
    return result;
}
int toNUm2(char *str){
    int result =0;
    for(int i=0;i<strlen(str);i++){
        result*=10;
        int wei = str[i]-48;
        result+=wei;
        printf("=转化%s,到第%d位时结果为%d\n",str,i,result);
    }
    return result;
}

int main(){
    print();
    char str[10]="3429";
    printf("转化结果为：%d\n",toNUm(str));
    printf("=转化结果为：%d\n",toNUm2(str));
    return 0;
}

void print() {
    printf("%d,%c\n", 1, 1);//打印整型1,打印ASCII 编号为1的字符
    printf("%d,%c\n",'1','1');//打印字符'1'的ASCII值，打印字符'1'
}

