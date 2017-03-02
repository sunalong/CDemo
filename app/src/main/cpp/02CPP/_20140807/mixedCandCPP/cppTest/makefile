#用于将 cppTest.cpp 和库文件 libtestlib.so 生成可执行文件，
CC=g++
SRCS=cppTest.cpp

OBJS=$(SRCS:.cpp=.o)

EXEC=cppTest

start:	$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -L. -ltestlib

.cpp.o:
	$(CC) -g -o $@ -c $<

clean:
	rm -rf $(OBJS)

