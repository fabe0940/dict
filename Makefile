CC = g++
CFLAGS = $(WARNINGS) $(DEBUG) $(DEFINE)
DEBUG = -g
DEFINE = -DHASH_TABLE_SIZE=$(SIZE)
WARNINGS = -ansi -pedantic -Wall -Wextra -D__USE_FIXED_PROTOTYPES__
OBJ = main.o hash.o
#LIBS = -lncurses
APPLICATION_NAME = dict

.PHONY : all rebuild clean

all : $(APPLICATION_NAME)

rebuild :
	make clean
	make all

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(APPLICATION_NAME) $(LIBS)

testHash : TestHash.o hash.o
	$(CC) $(CFLAGS) TestHash.o hash.o -o testHash

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

TestHash.o : TestHash.cpp hash.h
	$(CC) $(CFLAGS) -c TestHash.cpp

hash.o : hash.cpp hash.h
	$(CC) $(CFLAGS) -c hash.cpp $(LIBS)

clean :
	rm -f $(APPLICATION_NAME) $(OBJ)
