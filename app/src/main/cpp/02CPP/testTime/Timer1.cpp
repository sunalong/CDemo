//
// Created by sunalong on 17/3/8 18:40.
// Email:466210864@qq.com
//
#include   <stdio.h>
#include   "KTimer.h"
main()
{
    unsigned   t;
    KTimer   timer;
    timer.Start();
    Sleep(1000);
    t   =   timer.Stop();
    printf("Lasting   Time:   %d/n",t);
}
