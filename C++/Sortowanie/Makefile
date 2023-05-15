all: sort
sort:	main.o algorytmy.o
	g++ -o sort main.o algorytmy.o
main.o: main.cpp algorytmy.hpp
	g++ -c main.cpp
algorytmy.o: algorytmy.cpp algorytmy.hpp
	g++ -c algorytmy.cpp
clean:
	rm *.o
 
