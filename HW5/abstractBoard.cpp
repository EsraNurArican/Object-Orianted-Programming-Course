/*File abstractBoard.cpp
 *This is the implementation file for class AbstractBoard*/
#include "abstractBoard.h"

using namespace EsraNameSpace;

int AbstractBoard::numOfMovesPerformed=0;
int AbstractBoard::numOfBoardsCreated=0;
char AbstractBoard::lastMovePerf='S';

int AbstractBoard::numberOfBoards(){
	return numOfBoardsCreated;
}
char AbstractBoard::lastMove(){
	return lastMovePerf;
}
int AbstractBoard::numberOfMoves(){
	return numOfMovesPerformed;
}
bool AbstractBoard::operator ==(AbstractBoard& rightSide){
	//will be implement in derived classes
	return -1;
}
void AbstractBoard::getEmptyCellX_Y(int &cellX,int &cellY){
	//will be implement later in derived classes
}
