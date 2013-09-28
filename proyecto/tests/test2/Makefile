INCPATH := -I/usr/include/mysql -I/usr/local/include/mysql++
LFLAGS := -L/usr/local/lib
LIBS := -lmysqlpp -lmysqlclient
PROG := test2

all: mysqplot.o

	g++ -Wall mysqplot.o test2.cpp $(LFLAGS) $(LIBS) $(INCPATH) -o test2
	
mysqplot.o : mysqplot.hh mysqplot.cpp

	g++ -Wall -c mysqplot.cpp $(INCPATH) 

clean:

	rm *.o $(PROG)


