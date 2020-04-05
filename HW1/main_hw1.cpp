/*This is the main file for hw1*/
#include "161044028_hw1.h"
#include <iostream>
using namespace std;

int main(){

  int boardSize;
  char input; 
  int arrBoard[maxSize][maxSize];
  int checkBoard[maxSize][maxSize];
  int i,j;
  int counter=0,check=0,control;

  /*Taking board size from user*/
  do{
    cout<<"Please enter the problem size:";
    cin>>boardSize;
    if(boardSize<3 || boardSize>9)
    cout<<"You entered invalid value!\n";
  }while(boardSize<3 || boardSize>9);
 

  /*First assigning values to arrBoard,to avoid mistakes for further steps because of empty indexes*/
  for(i=0;i<boardSize;i++){ 
    for(j=0;j<boardSize;j++){
      arrBoard[i][j]=100;
    }
  }

  initBoard(boardSize,arrBoard);  //calling board initialization function
  sortBoard(checkBoard,boardSize); //final board situation assigned the check board array
  cout<<endl;

  /*Taking input from user until receive the solution or quit*/
  do{

    cout<<"Your move:";
    cin>>input;

    if(input=='U' || input=='u'){
      check=up(arrBoard,boardSize);
   
    }
    if(input=='D' || input=='d'){
      check=down(arrBoard,boardSize);
    
    }
    if(input=='L' || input=='l'){
      check=left(arrBoard,boardSize);
      
    }
    if(input=='R' || input=='r'){
      check=right(arrBoard,boardSize);
      
    }
    if(input=='I' || input == 'i'){
      check=intelligent(arrBoard,boardSize);
      
    }
    if(input=='S' || input== 's'){
      check=shuffle(arrBoard,boardSize);
      
    }
    if(input=='Q' || input=='q'){
      cout<<"Total number of moves:"<<counter<<endl;
      return -1; 
    }
    if(check==0 ){
      printBoard(arrBoard,boardSize);
      counter++;
    }
    else if(check==-1)
      cout<<"There is no room!\n";

    //Controlling the board whether is it on final position or not
    control=checkIfItsFinal(arrBoard,checkBoard,boardSize);
    if(control==boardSize*boardSize){
      cout<<"Problem solved!"<<endl;
      cout<<"Total number of moves:"<<counter<<endl;
      return -1;
    }

  }while(input!='Q');

  

  return 0;
}
