/*File N_Puzzle.h*/
/*This file contains class definition of N_Puzzle class and nested Board class*/
#ifndef N_PUZZLE_H
#define N_PUZZLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

const int maxSize = 9;
const int size=100;

using namespace std;

class N_Puzzle{

private:
	
	class Board{
	public:
		/*Constructors*/
		Board(); 																//no parameter constructor
		Board(int n_row,int n_column); 											//constructor sets array with given row and column
		Board(int boardSize);													//constructor sets array with given size as square

		/*Getters Setters*/												
		inline void setRow(int n_row) { row = n_row;}
		inline void setColumn(int n_column) { column = n_column;}
		inline int getRow()const { return row; }
		inline int getColumn()const { return column; }
		inline int getArrayBoardIndex(int row,int column) {return arrBoard[row][column];}
		inline void setArrayBoardIndex(int row,int column,int n_value) { arrBoard[row][column]=n_value; }
	
		/*Functions*/
		void print();															//prints the board on screen
		void readFromFile(ifstream &input,string filename);						//function reads file and determines row and column
		void readAndAssign(ifstream &input,string filename);					//funciton assigns the values from the file to array
		void writeToFile(ofstream &output,string &filename);					//funciton writes array to given file
		void reset( );															//resets the board to the solution
		void setSize(int size);													//sets the board to given size
		int move(char direction);												//according to parameter moves empty cell U,D,R,L
		bool isSolved();														//returns true if board is solution
		void initRandomly(int size);											//initializes array randomly
	private:
		int arrBoard[maxSize][maxSize];
		int row;
		int column;
	};

	Board boardObje;

public:

	N_Puzzle();												//No parameter constructor
	N_Puzzle(ifstream &input,string filename);				//If program starts with a file name,initializes board according to file	
	N_Puzzle(int boardSize);								//If program starts without filename,initializes array randomly given size	
	inline Board getBoardObje()const { return boardObje;}   //getter for boardObje 	
	/*Functions*/												
	void print();
	int printReport(int numberMove);
	void readFromFile(ifstream &input,string filename);
	void readAndAssign(ifstream &input,string filename);
	void writeToFile(ofstream &output,string &filename);	
	int shuffle(int N);
	void reset( );
	void setSize(int size);
	int moveRandom();
	int moveIntelligent();
	int move(char direction);
	int solvePuzzle();
	
};
#endif