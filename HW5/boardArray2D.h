/*Header file for class BoardArray2D*/
#ifndef BOARDARRAY2D_H
#define BOARDARRAY2D_H

#include "abstractBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

namespace EsraNameSpace{

	class BoardArray2D : public AbstractBoard{
	public:
		//constructors
		BoardArray2D();
		BoardArray2D(int nrow,int ncolumn);
		BoardArray2D(int size);

		//Big Three
		~BoardArray2D();											//destructor
		BoardArray2D(const BoardArray2D& object);					//copy construstor
		BoardArray2D & operator =(const BoardArray2D& rightSide);	//assignment operator

		//getters-setters
		inline void setRow(int n_row){ row=n_row; }
		inline void setColumn(int n_column) { column=n_column;}
		inline int getRow() const { return row; }
		inline int getColumn() const { return column;}
		inline int getIndex(int n_row,int n_column)const{ return arr2D[n_row][n_column];}
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
		virtual bool operator ==(const BoardArray2D& rightSide);			//returns true if two boards are equal
		int operator ()(int index1,int index2);							//takes two indexes and returns the value at cell

	private:
		int **arr2D;													//Dynamic 2D array to represent the game board
		int row;
		int column;
	};
}//end of namespace
#endif