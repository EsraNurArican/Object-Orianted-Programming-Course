# top down makefile for CSE241-HW4

begin : N_puzzle.o main.o 
	g++ --std=c++11  main.o N_puzzle.o  -o test

N_puzzle.o : N_puzzle.cpp
	g++ -c --std=c++11 N_puzzle.cpp
	
main.o : main.cpp
	g++ -c --std=c++11  main.cpp
	
clean:
	rm *.o test