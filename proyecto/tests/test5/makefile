INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++
LIBS = -lmysqlpp -lmysqlclient -lstdc++
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG) -L/usr/local/lib ../../src/mysqplot.o
OBJS = test5.cpp
TARGET = test5

all : 
	cd ../../src/ && $(MAKE)
	$(MAKE) $(TARGET)

$(TARGET) : $(OBJS)

	$(CC) -ggdb $(LFLAGS) $(OBJS) $(LIBS) $(INCPATH) -o $(TARGET).exe

clean:

	rm *.exe


