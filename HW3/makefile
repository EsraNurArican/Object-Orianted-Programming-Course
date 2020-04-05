# top down makefile for CSE241-HW3

begin : N_Puzzle.o main.o 
	g++ --std=c++11  main.o N_Puzzle.o  -o test

N_Puzzle.o : N_Puzzle.cpp
	g++ -c --std=c++11 N_Puzzle.cpp
	
main.o : main.cpp
	g++ -c --std=c++11  main.cpp
	
clean:
	rm *.o test