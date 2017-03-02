#用于将 cppTest.cpp 和库文件 libtestlib.so 生成可执行文件，
CC=gcc
SRCS=cTest.c
OBJS=$(SRCS:.c=.o)
EXEC=cTest
start:	$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L. -ltestlib
   #$(CC) -o $(EXEC) $(OBJS) -L./../libToso/ -ltestlib
.c.o:
	$(CC) -g -o $@ -c $<
clean:
	rm -rf $(OBJS)

