INCPATH = -I/usr/include/mysql -I/usr/local/include/mysql++
LIBS = -lmysqlpp -lmysqlclient -lstdc++
CC = g++
DEBUG = -g
LFLAGS = -Wall $(DEBUG) -L/usr/local/lib ../../src/mysqplot.o

all : 

# build library
	cd ./proyecto/src && $(MAKE)

# build report
	cd ./documentacion && $(MAKE)

# build prereport
	cd ./propuesta && $(MAKE)

# build Doxigen documentation
	cd ./proyecto/doc && doxygen Doxyfile

# build install and usage documentation
	cd ./proyecto/doc && $(MAKE)

# build presentation
	cd ./presentacion && $(MAKE)

$(TARGET) : $(OBJS)

	$(CC) -ggdb $(LFLAGS) $(OBJS) $(LIBS) $(INCPATH) -o $(TARGET).exe

clean:

# clean library
	cd ./proyecto/src && $(MAKE) clean

# clean report
	cd ./documentacion && $(MAKE) clean

# clean prereport
	cd ./propuesta && $(MAKE) clean

# clean Doxigen documentation
	cd ./proyecto/doc && rm -rf html latex

# clean install and usage documentation
	cd ./proyecto/doc && $(MAKE) clean

# clean presentation
	cd ./presentacion && $(MAKE) clean


