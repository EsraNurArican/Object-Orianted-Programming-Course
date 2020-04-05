/*Header file for class BoardArray1D*/
#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H

#include "abstractBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
namespace EsraNameSpace{

	class BoardArray1D : public AbstractBoard{
	public:
		//constructors
		BoardArray1D();
		BoardArray1D(int nrow,int ncolumn);
		BoardArray1D(int size);

		//Big Three
		~BoardArray1D();											//destructor
		BoardArray1D(const BoardArray1D& object);					//copy construstor
		BoardArray1D & operator =(const BoardArray1D& rightSide);	//assignment operator

		//getters-setters
		inline void setRow(int n_row){ row=n_row; }
		inline void setColumn(int n_column) { column=n_column;}
		inline int getRow() const { return row; }
		inline int getColumn() const { return column;}
		inline int getIndex(int n_row,int n_column)const{ return arr1D[n_row*column+n_column];}
		void getEmptyCellX_Y(int &cellX,int &cellY);				//Returns the empty cell's x y coordinates to use in global funct

		//functions
		void print();													//Prints the gameboard sending it to cout
		void readFromFile(ifstream &input,string filename);				//function reads the file and determines row,column
		void readAndAssign(ifstream &input,string filename);			//funciton assigns the values from the file to array
		void writeToFile(ofstream &output,string &filename);			//funciton writes board to given file
		void reset();													//resets the board to the solution
		void setSize(int rowS,int columnS);								//sets the board to given size,after that resets the board
		int move(char direction);										//according to parameter moves empty cell U,D,R,L
		int shuffle();													//shuffles board to receive solvable game board
		bool isSolved();												//returns true if board is solution
		virtual bool operator ==(const BoardArray1D& rightSide) ;			//returns true if two boards are equal
		int operator ()(int index1,int index2);							//takes two indexes and returns the value at cell
	
	private:
		int *arr1D;														//Dynamic 1D array to represent the game board
		int row;
		int column;
	};
}//end of namespace
#endif