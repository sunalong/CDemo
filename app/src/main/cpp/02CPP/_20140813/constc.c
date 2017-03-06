//
// Created by sunalong on 17/3/5 15:08.
// Email:466210864@qq.com
//

#include <stdio.h>
void main(){
    const int num= 5;
    char * a[num];
    printf("1.const num 的值：%d\n",num);
    int *p = &num;
    *p =3;
    printf("2.经由指针改变后，const num 的值：%d\n",num);
}
//mac下与ubuntu 下的输出不一致：
//   mac:
//       ~/GitHub/CDemo/app/src/main/cpp/02CPP/_20140813 on  master! ⌚ 15:10:50
//       $ a.out
//       1.const num 的值：5
//       2.经由指针改变后，const num 的值：5
//
//   ubuntu:
//       ~/CDemo ⌚ 15:12:16
//       $ ./a.out
//       1.const num 的值：5
//       2.经由指针改变后，const num 的值：3
