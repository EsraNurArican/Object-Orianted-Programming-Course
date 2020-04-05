# top down makefile for CSE241-HW1

begin : 161044028_hw1.o main_hw1.o 
	g++ -std=c++11 -ansi -pedantic -Wall main_hw1.o 161044028_hw1.o  -o test

161044028_hw1.o : 161044028_hw1.cpp
	g++ -c -std=c++11 -ansi -pedantic -Wall 161044028_hw1.cpp
	
main_hw1.o : main_hw1.cpp
	g++ -c -std=c++11  -ansi -pedantic -Wall main_hw1.cpp
	
clean:
	rm *.o test
