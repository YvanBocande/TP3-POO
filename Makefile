CC = g++
FLAGS = -ansi -pedantic -Wall -std=c++11 -DMAP
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = prog

all : $(EXEC)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) $(FLAGS) -o $(EXEC) $^

remove:
	rm -f *.o

clean:
	rm -f *.o $(EXEC)

zip:
	tar -cvzf TP3.tar.gz *.cpp *.h Makefile

valgrind :
	valgrind --leak-check=full -s ./$(EXEC)