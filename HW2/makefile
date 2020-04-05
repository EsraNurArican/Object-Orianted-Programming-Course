# top down makefile for CSE241-HW1

begin : source.o main.o 
	g++ --std=c++11  main.o source.o  -o test

source.o : source.cpp
	g++ -c --std=c++11 source.cpp
	
main.o : main.cpp
	g++ -c --std=c++11  main.cpp
	
clean:
	rm *.o test
