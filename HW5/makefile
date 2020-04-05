#Makefile for CSE-241 HW5
begin : abstractBoard.o boardArray1D.o boardArray2D.o boardVector.o main.o 
	g++ -std=c++11 abstractBoard.o boardArray1D.o boardArray2D.o boardVector.o main.o -o run
abstractBoard.o : abstractBoard.cpp
	g++ -c -std=c++11 abstractBoard.cpp
	
boardArray1D.o : boardArray1D.cpp
	g++ -c -std=c++11  boardArray1D.cpp

boardArray2D.o : boardArray2D.cpp
	g++ -c -std=c++11  boardArray2D.cpp

boardVector.o : boardVector.cpp
	g++ -c -std=c++11  boardVector.cpp
	
main.o : main.cpp
	g++ -c -std=c++11  main.cpp
	
clean:
	rm *.o run