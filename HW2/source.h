/*.h file for function declarations*/
#ifndef SOURCE_H
#define SOURCE_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;
const int maxSize = 9;
const int size=100;

/*Function declarations*/

void initBoard(int boardSize,int arrBoard[maxSize][maxSize]);

inline void printBoard(int arrBoard[maxSize][maxSize],int row,int column){
	for (int m = 0; m < row; m++){
        for (int k = 0; k < column; k++) {
          if(arrBoard[m][k]!=100)
            cout << arrBoard[m][k] << " ";
          else if(arrBoard[m][k]==100)
            cout<<"  ";
        }
        cout<<endl;
  }
  cout<<endl;
}
int up(int arrBoard[maxSize][maxSize],int row,int column);
int down(int arrBoard[maxSize][maxSize],int row,int column);
int left(int arrBoard[maxSize][maxSize],int row,int column);
int right(int arrBoard[maxSize][maxSize],int row,int column);
int intelligent(int arrBoard[maxSize][maxSize],int row,int column);
int shuffle (int arrBoard[maxSize][maxSize],int row,int column);
void sortBoard(int arrBoard[maxSize][maxSize], int row,int column) ;
int checkIfItsFinal(int arrBoard[maxSize][maxSize],int checkBoard[maxSize][maxSize],int row,int column);
int equalizeArrays(int arrBoard[maxSize][maxSize],int checkBoard[maxSize][maxSize],int row,int column);
void readFromFile(ifstream &input,string filename,int &row,int &column);
void readAndAssign(ifstream &input,string filename,int arrBoard[maxSize][maxSize],int row,int column);
void printOnFile(ofstream &output,string &filename,int arrBoard[maxSize][maxSize],int row,int column);


#endif
