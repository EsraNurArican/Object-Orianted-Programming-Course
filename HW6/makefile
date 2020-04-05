#Makefile for CSE-241 HW5
begin : gtuSet.o gtuVector.o gtuIterator.o gtuIteratorConst.o main.o 
	g++ -std=c++11 gtuSet.o  gtuIterator.o gtuIteratorConst.o main.o -o run
gtuSet.o : gtuSet.cpp
	g++ -c -std=c++11 gtuSet.cpp
	
gtuVector.o : gtuVector.cpp
	g++ -c -std=c++11 gtuVector.cpp
	
gtuIterator.o : gtuIterator.cpp
	g++ -c -std=c++11  gtuIterator.cpp

gtuIteratorConst.o : gtuIteratorConst.cpp
	g++ -c -std=c++11  gtuIteratorConst.cpp
	
main.o : main.cpp
	g++ -c -std=c++11  main.cpp
	
clean:
	rm *.o run