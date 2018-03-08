CFLAGS = -O -g -Wall
CC = g++ 
SRC = main.cpp contact_list.cpp sl_list.cpp node.h quick_sort.cpp
MAIN = main

all: $(MAIN)

$(MAIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(MAIN)

run: $(MAIN)
	./$(MAIN)

clean: 
	rm -rf core *.o $(MAIN)
