/*This is the header file for class AbstractBoard
* File "abstractBoard.h" */
#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;


namespace EsraNameSpace{

	class AbstractBoard{
		public:
			virtual void print()=0;
			virtual void readFromFile(ifstream &input,string filename)=0;
			virtual void readAndAssign(ifstream &input,string filename)=0;
			virtual void writeToFile(ofstream &output,string &filename)=0;
			virtual void reset()=0;
			virtual void setSize(int rowS,int columnS)=0;
			virtual int move(char direction)=0;
			virtual bool isSolved()=0;
			virtual bool operator ==(AbstractBoard& rightSide);
			virtual int operator ()(int index1,int index2)=0;

			inline void setNumOfMove(){ numOfMovesPerformed++;}
			inline void setNumOfBoard(){ numOfBoardsCreated++;}
			inline void setLastMove(char move) {lastMovePerf=move;}
			static int numberOfBoards();
			static char lastMove();
			static int numberOfMoves();

			virtual void getEmptyCellX_Y(int &cellX,int &cellY);
		protected:
			static int numOfMovesPerformed;
			static int numOfBoardsCreated;
			static char lastMovePerf;

	};
}//end of EsraNameSpace
#endif