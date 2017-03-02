//
// Created by sunalong on 17/3/1 18:17.
// Email:466210864@qq.com
//

#include "udp.h"
#include <stdio.h>
#include <string.h>
#ifdef MYLINUX
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#define SOCKET int
#else
#include <winsock2.h>
#endif
int socket_send(const char *IP) {
#ifndef MYLINUX
    //初始化 socket
    DWORD ver;
    WSADATA wsadata;
    ver = MAKEWORD(1, 1);//在调用 WSAStartup 要告诉 windowns,用什么版本的 socket
    WSAStartup(ver, &wsadata);//windows 要求，只要用 socket,第一步必须调用这个函数，至此，初始化 socket 完成
#endif

    //建立一个 socket,第一个参数是指定 socket 要用哪个协议，AF_INET 代表要用 TCP/IP 协议
    //第二个参数 SOCK_DGRAM 意思是要用 UDP 协议
    //第三个参数一般默认0
    SOCKET st = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));//初始化结构 addr;
    addr.sin_family = AF_INET;// 代表要使用一个 TCP/IP 的地址
    addr.sin_port = htons(8080);//host to net short
    addr.sin_addr.s_addr= inet_addr(IP);
   //ussigned log laddr = inet_addr(IP);   
   // unsigned char *p = &laddr;
   // printf("%u,%u,%u,%u\n", *p, *(p + 1), *(p + 2), *(p + 3));
    char buf[1024] = {0};
    size_t rc = 0;
    while (1) {
        memset(buf, 0, sizeof(buf));
        //gets(buf);
        fgets(buf,(sizeof buf/sizeof buf[0]),stdin);
        if (buf[0] == '0')//做为退出条件
            break;
        //发送 udp 数据
        rc = sendto(st, buf, strlen(buf), 0, (struct sockaddr *) &addr, sizeof(addr));
    }
#ifdef MYLINUX
    close(st);//使用完 socket 要将其关闭
#else
    closesocket(st);//使用完 socket 要将其关闭
    WSACleanup();//释放 win socket 内部的相关资源
#endif
    return rc;
}

int socket_recv() {
#ifndef MYLINUX
    //初始化 socket
    DWORD ver;
    WSADATA wsadata;
    ver = MAKEWORD(1, 1);//在调用 WSAStartup 要告诉 windowns,用什么版本的 socket
    WSAStartup(ver, &wsadata);//windows 要求，只要用 socket,第一步必须调用这个函数，至此，初始化 socket 完成
#endif
    //建立一个 socket,第一个参数是指定 socket 要用哪个协议，AF_INET 代表要用 TCP/IP 协议
    //第二个参数 SOCK_DGRAM 意思是要用 UDP 协议
    //第三个参数一般默认0
    SOCKET st = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));//初始化结构 addr;
    addr.sin_family = AF_INET;// 代表要使用一个 TCP/IP 的地址
    addr.sin_port = htons(8080);//host to net short
    addr.sin_addr.s_addr = htonl(INADDR_ANY);//做为接收方，不需要指定具体的 IP,接收的主机是什么 IP，就在什么 IP 上接收数据
//    unsigned long laddr = inet_addr(IP);
//    unsigned  char *p = &laddr;
//    printf("%u,%u,%u,%u\n",*p,*(p+1),*(p+2),*(p+3));
    int rc = 0;
    if (bind(st, (struct sockaddr *) &addr, sizeof(addr)) > -1) {//将端口和程序绑定
        char buf[1024] = {0};
        struct sockaddr_in sendaddr;
        memset(&sendaddr, 0, sizeof(sendaddr));
#ifdef MYLINUX
       socklen_t len ;
#else
        int len;
#endif
      len = sizeof(sendaddr);
        while (1) {
            memset(buf,0, sizeof(buf));
            //接收 udp 数据
            rc = recvfrom(st, buf, strlen(buf), 0, (struct sockaddr *) &sendaddr, &len);
            printf("接收到的数据rc:%d IP:%s：%s\n",rc, inet_ntoa(sendaddr.sin_addr),buf);
        }
    }
#ifdef MYLINUX
    close(st);//使用完 socket 要将其关闭
#else
    closesocket(st);//使用完 socket 要将其关闭
    WSACleanup();//释放 win socket 内部的相关资源
#endif
    return rc;
}

