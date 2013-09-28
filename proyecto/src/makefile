INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++
LIBS = -lmysqlpp -lmysqlclient
OBJS = mysqplot.cpp
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -L/usr/local/lib

mysqplot.o : mysqplot.cpp mysqplot.hh

	$(CC) $(CFLAGS) $(LFLAGS) $(INCPATH) $(LIBS) mysqplot.cpp
	
clean :

	rm *.o
