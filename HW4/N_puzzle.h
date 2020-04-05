/*File N_puzzle.h*/
/*This file contains class definition of N_Puzzle class and nested Board class*/
#ifndef N_PUZZLE_H
#define N_PUZZLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <time.h>
const int maxSize = 9;
const int size=100;

using namespace std;

class N_Puzzle{

private:

	class Board{
	public:
		/*Constructors*/
		Board();
		Board(int boardSize);
		
		/*Getters-Setters*/
		inline vector<vector<int>> getBoard(){return boardVec;}
		inline void setBoardIndex(int i,int j,int val){ boardVec[i][j]=val;}
		inline char getLastMove() const { return lastMovePerformed;}
		inline void setLastMove(char move) {lastMovePerformed = move;}
		inline int getNumOfMoves()  { return numOfMoves;}
		inline void setNumOfMoves() {numOfMoves++;}
		inline int getNumberIndex(int row,int column){return boardVec[row][column];}
		inline int getColumn() const { return row;}
		inline int getRow() const { return column;}

		/*Functions*/
		void initBoard(int row,int column);
		void print();													//Prints the board on screen
		void readFromFile(ifstream &input,string filename);				//function reads the file and determines row,column
		void readAndAssign(ifstream &input,string filename);			//funciton assigns the values from the file to vector
		void writeToFile(ofstream &output,string &filename);			//funciton writes board to given file
		void reset( );													//resets the board to the solution
		void setSize(int size,int size2);								//sets the board to given size,after that resets the board
		int move(char direction);										//according to parameter moves empty cell U,D,R,L
		bool isSolved();												//returns true if board is solution
		bool operator ==( Board& rightSide);							//returns true if two boards are equal
		int operator ()(int index1,int index2);							//takes two indexes and returns the value at cell
		int numberOfBoards();											//returns the number of boards created
		char lastMove();												//returns the last move
		int numberOfMoves();											//returns the number of moves this board made

	private:
		vector <vector <int> > boardVec;
		char lastMovePerformed;
		static int numOfMoves;
		int row;
		int column;
	};

	vector<Board> vecBoardObj;

public:
	N_Puzzle();
	N_Puzzle(int boardSize);
	inline Board getBoardObje(int i){ return vecBoardObj[i]; }
	inline vector<Board> getBoardVector() { return vecBoardObj;}
	void print();
	void printReport(int numberMove);
	void readFromFile(ifstream &input,string filename);
	void readAndAssign(ifstream &input,string filename);
	void writeToFile(ofstream &output,string &filename);
	int shuffle(int N);
	void reset();
	void setSize(int size);
	int moveRandom();
	int move(char direction);
	int solvePuzzle();
	friend ostream& operator <<(ostream &outputStream, N_Puzzle & object); 
	friend istream& operator >>(istream &inputStream,N_Puzzle & object);


};
#endif