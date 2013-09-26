INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++
LFLAGS = -L/usr/local/lib
LIBS = -lmysqlpp -lmysqlclient
PROG = test2

all: 	
	g++ -c $(PROG).cpp $(INCPATH)
	g++ $(PROG).o -o $(PROG) $(LFLAGS) $(LIBS)
	clear 
	./$(PROG)
clean:
	


