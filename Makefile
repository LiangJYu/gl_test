CFLAGS = -O -g -Wall
CC = g++ 
SRC = main.cpp csv.cpp
MAIN = main

all: $(MAIN)

$(MAIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(MAIN)

clean: 
	rm -rf core *.o $(MAIN)
