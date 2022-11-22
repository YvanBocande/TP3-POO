FLAGS = -ansi -pedantic -Wall -std=c++11 -DMAP

executable: Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Collection.o main.o
	g++ $(FLAGS) -o executable Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Collection.o main.o

map: Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Collection.o main.o
	g++ $(FLAGS) -o executable Catalogue.o Trajet.o TrajetSimple.o TrajetCompose.o Collection.o main.o -DMAP

Catalogue.o: Catalogue.h Catalogue.cpp
	g++ $(FLAGS) -o Catalogue.o -c  Catalogue.cpp

Trajet.o: Trajet.h Trajet.cpp
	g++ $(FLAGS) -o Trajet.o -c Trajet.cpp

TrajetSimple.o: TrajetSimple.h TrajetSimple.cpp
	g++ $(FLAGS) -o TrajetSimple.o -c TrajetSimple.cpp

TrajetCompose.o: TrajetCompose.h TrajetCompose.cpp
	g++ $(FLAGS) -o TrajetCompose.o -c TrajetCompose.cpp

Collection.o: Collection.h Collection.cpp
	g++ $(FLAGS) -o Collection.o -c Collection.cpp

main.o: main.cpp
	g++ $(FLAGS) -o main.o -c main.cpp

remove:
	rm -f *.o

clean:
	rm -f *.o executable

zip:
	tar -cvzf TP2.tar.gz *.cpp *.h makefile

valgrind :
	valgrind --leak-check=full -s ./executable