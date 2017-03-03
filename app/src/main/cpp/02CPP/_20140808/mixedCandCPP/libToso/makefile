#用于将 testlib.c 文件打包成 so 库文件供外界调用
CC=gcc
SRCS=testlib.c
OBJS=$(SRCS:.c=.o)
EXEC=libtestlib.so
start:	$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -shared
	cp libtestlib.so ../cppTest/
	cp libtestlib.so ../cTest/
.c.o:
	$(CC) -g -o $@ -c $< -fPIC
clean:
	rm -rf $(OBJS)

