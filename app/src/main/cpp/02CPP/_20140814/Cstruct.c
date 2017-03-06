//
// Created by sunalong on 17/3/6 21:43.
// Email:466210864@qq.com
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct {
    int num1;
    int num2;
};

void getBigData(char *dataA, char *dataB) {
    int lengthA = strlen(dataA);
    int lengthB = strlen(dataB);
    int *pres = (int *)malloc(sizeof(int)*(lengthA+lengthB));
    memset(pres,0, sizeof(int)*lengthA+lengthB);
    for(int i=0;i<lengthA;i++)
        for (int j = 0; j < lengthB; ++j) {
            pres[i+j+1]+=(dataA[i]-'0')*(dataB[j]-'0');

        }
    //进位
    for(int i=lengthA+lengthB-1;i>=0;i--)
        if(pres[i]>=10){
            pres[i-1]+=pres[i]/10;//进位
            pres[i]%=10;//取出个位数
        }
    int i=0;
    while(pres[i] == 0){
        i++;//恰好不为0的位置
    }
    char *lastres = malloc(sizeof(char)*(lengthA+lengthB));
    for(int j=0;j<lengthA+lengthB;j++,i++){
        lastres[j] = pres[i]+'0';
    }
    lastres[lengthA+lengthB-1]='\0';
    printf("last 结果=%s\n",lastres);
}
void main(){
    char strA[100]={0};
    char strB[100]={0};
    scanf("%s",strA);
    scanf("%s",strB);
    printf("strA=%s,strB=%s",strA,strB);
    getBigData(strA,strB);
}