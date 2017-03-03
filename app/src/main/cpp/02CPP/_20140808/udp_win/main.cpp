#include <iostream>
#include "udp.h"

using namespace std;

int main(int argc, char *args[]) {
    if (argc > 1)
        socket_send(args[1]);
    else
        socket_recv();

//    if(argc>2){
//        if(args[1][0]=='1')
//            socket_send(args[2]);
//        else
//            socket_recv();
//    }
    return 0;
}
