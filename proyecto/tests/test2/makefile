INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++
LIBS = -lmysqlpp -lmysqlclient
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG) -L/usr/local/lib ../../src/mysqplot.o
OBJS = test2.cpp
TARGET = test2

all : 
    
	cd ../../src/ && $(MAKE)
	$(MAKE) $(TARGET)
	
$(TARGET) : $(OBJS)

	$(CC) $(LFLAGS) $(OBJS) $(LIBS) $(INCPATH) -o $(TARGET).exe

clean:

	rm *.o *.$(EXE)


