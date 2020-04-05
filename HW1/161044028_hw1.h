/*.h file for function declarations*/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
const int maxSize = 9;

/*Function declarations*/
void initBoard(int boardSize,int arrBoard[maxSize][maxSize]);
void printBoard(int arrBoard[maxSize][maxSize],int boardSize);
int up(int arrBoard[maxSize][maxSize],int boardSize);
int down(int arrBoard[maxSize][maxSize],int boardSize);
int left(int arrBoard[maxSize][maxSize],int boardSize);
int right(int arrBoard[maxSize][maxSize],int boardSize);
int intelligent(int arrBoard[maxSize][maxSize],int boardSize);
int shuffle (int arrBoard[maxSize][maxSize],int boardSize);
void sortBoard(int arrBoard[maxSize][maxSize], int boardSize) ;
int checkIfItsFinal(int arrBoard[maxSize][maxSize],int checkBoard[maxSize][maxSize],int boardSize);