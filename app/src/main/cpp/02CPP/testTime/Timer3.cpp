//
// Created by sunalong on 17/3/8 18:41.
// Email:466210864@qq.com
//
#include   <windows.h>
#include   <stdio.h>

main()
{
    LARGE_INTEGER   t1,   t2,   tc;
    QueryPerformanceFrequency(&tc);
    printf("Frequency:   %u/n",   tc.QuadPart);
    QueryPerformanceCounter(&t1);
    Sleep(1000);
    QueryPerformanceCounter(&t2);
    printf("Begin   Time:   %u/n",   t1.QuadPart);
    printf("End   Time:   %u/n",   t2.QuadPart);
    printf("Lasting   Time:   %u/n",(   t2.QuadPart-   t1.QuadPart));
}
