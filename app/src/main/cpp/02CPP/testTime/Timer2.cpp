//
// Created by sunalong on 17/3/8 18:40.
// Email:466210864@qq.com
//
#include   <windows.h>
#include   <stdio.h>

main()
{
    DWORD   t1,   t2;
    t1   =   timeGetTime();
    Sleep(1000);
    t2   =   timeGetTime();
    printf("Begin   Time:   %u/n",   t1);
    printf("End   Time:   %u/n",   t2);
    printf("Lasting   Time:   %u/n",(t2-t1));
}

