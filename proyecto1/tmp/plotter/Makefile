LFLAGS = -L /usr/local/lib
INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++ -I /usr/local/include/SFML
LIBS = -lmysqlpp -lmysqlclient -lnsl -lz -lm -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
PROG = testv11

all: 	
	g++ -c $(PROG).cpp $(INCPATH)
	g++ $(PROG).o -o $(PROG) $(LFLAGS) $(LIBS) 
	./$(PROG)
clean:
	


