INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++
LIBS = -lmysqlpp -lmysqlclient -lstdc++
OBJS = mysqplot.cpp
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -L/usr/local/lib

mysqplot.o : mysqplot.cpp mysqplot.hh gnuplot_i.hpp 

	$(CC) $(CFLAGS) -ggdb -DDEBUGGA $(LFLAGS) $(INCPATH) $(LIBS) $(OBJS)
	
clean :

	rm *.o
