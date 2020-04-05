/*This is the cpp file for function definitions*/
#include "161044028_hw1.h"

/*Initializes game board with given size,randomly*/
void initBoard(int boardSize,int arrBoard[maxSize][maxSize]){

  int added = boardSize*boardSize;
  srand(time(NULL)); 
  
  int x=0,y=0;
  int random;
  bool isThere=true;

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++){
        do{
            random = (rand() % added) ;
            isThere=true;

            for ( x = 0; x<boardSize && isThere==true; x++){
              for ( y = 0; y <boardSize && isThere==true; y++){  
                if (arrBoard[x][y]!=100 && arrBoard[x][y] == random ){
                      isThere = false;
                }
              }         
            }
          }
          while (isThere==false  );

            arrBoard[i][j] = random;
    }
  }

  cout<<"Your initial random board is:"<<endl;
  printBoard(arrBoard,boardSize);
}

/*Prints the board on screen*/
void printBoard(int arrBoard[maxSize][maxSize],int boardSize){

  for (int m = 0; m < boardSize; m++){
        for (int k = 0; k < boardSize; k++) {
          if(arrBoard[m][k]!=0)
            cout << arrBoard[m][k] << " ";
          else if(arrBoard[m][k]==0)
            cout<<"  ";
        }
        cout<<endl;
  }
  cout<<endl;
}
/*moves the empty cell up if there is room*/
int up(int arrBoard[maxSize][maxSize],int boardSize){

  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(arrBoard[i][j]==0){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellX==0){
    return -1;
  }
  else if(emptCellX!=0){
    num=arrBoard[emptCellX-1][emptCellY];
    arrBoard[emptCellX-1][emptCellY]=0;
    arrBoard[emptCellX][emptCellY]=num;
  }
  return 0;  
}
/*moves the empty cell down if there is room*/
int down(int arrBoard[maxSize][maxSize],int boardSize){
  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(arrBoard[i][j]==0){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellX==boardSize-1){
    return -1; 
  }
  else if(emptCellX!=boardSize-1){
    num=arrBoard[emptCellX+1][emptCellY];
    arrBoard[emptCellX+1][emptCellY]=0;
    arrBoard[emptCellX][emptCellY]=num;
  } 
  return 0;
}
/*moves the empty cell left if there is room*/
int left(int arrBoard[maxSize][maxSize],int boardSize){
  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(arrBoard[i][j]==0){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellY==0){ 
    return -1;
  }
  
  else if(emptCellY!=0){
    num=arrBoard[emptCellX][emptCellY-1];
    arrBoard[emptCellX][emptCellY-1]=0;
    arrBoard[emptCellX][emptCellY]=num;
  } 
  return 0;
}
/*moves the empty cell right if there is room*/
int right(int arrBoard[maxSize][maxSize],int boardSize){
  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(arrBoard[i][j]==0){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellY==boardSize-1){
    return -1;
  }
  
  else if(emptCellY!=boardSize-1){
    num=arrBoard[emptCellX][emptCellY+1];
    arrBoard[emptCellX][emptCellY+1]=0;
    arrBoard[emptCellX][emptCellY]=num;
  } 
  return 0;
}

/*Takes the board to the final solution, and
makes size*size random moves to shuffle the board.*/
int shuffle(int arrBoard[maxSize][maxSize],int boardSize){
  /*First sorting the board for the final solution*/
  sortBoard(arrBoard,boardSize);
  cout<<"Final solution of the board:\n";
  printBoard(arrBoard,boardSize);
  /*Making size*size random moves to shuffle the board*/
  int randomMove;
  int control=0;
  int i=0;
  /*This loop written for shuffle the board making ramdom moves size*size.
   But if there is an impossible move, i call random func. again to make sure
   the board is shuffled properly */
  while( i<boardSize*boardSize){

    randomMove = (rand() % 4)+1 ;
    if(randomMove==1){
      control=up(arrBoard,boardSize);
    } 
    if(randomMove==2){
      control=down(arrBoard,boardSize);
    } 
    if(randomMove==3){
      control=left(arrBoard,boardSize);
    } 
    if(randomMove==4){
      control=right(arrBoard,boardSize);
    } 
    /*Control is the return value for U,D,R,L functions
     If control is -1 this means there is no room for that choice
     If control is 0 this means cell is moved and size*size number increases*/
    if(control==0)
      i++;
  }
  cout<<"Shuffled version of the board:\n";
  return 0;
}

/*moves empty cell to get closer the final position*/
/*For intelligent move i find other numbers around the empty cell,
then i determined their current positions and final positions
the most closer number to its final position moved*/
int intelligent(int arrBoard[maxSize][maxSize],int boardSize){

  int numL=0,numR=0,numU=0,numD=0; //numbers around the empty cell,initially 0
  int numLX,numLY,numRX,numRY,     //number's final positions around empty cell
      numUX,numUY,numDX,numDY;
  int diffU=0,diffD=0,diffR=0,diffL=0;    //difference between values final and current positions
  int posX,posY;
  for(int i=0; i<boardSize;i++){
    for(int j=0; j<boardSize;j++){
      if(arrBoard[i][j]==0){
        posX=i;
        posY=j;
        /*Determining numbers around the empty cell if there is place*/
        if(posY-1!=-1){
          numL=arrBoard[i][j-1];
          
          if(numL%boardSize!=0){
            numLY=numL%boardSize-1;
            numLX=numL/boardSize;
          }
          else if(numL%boardSize==0){
            numLY=boardSize-1;
            numLX=numL/boardSize-1;
          }
          diffL=abs((posX-numLX)+(posY-1-numLY));
        }

        if(posY+1!=boardSize){
          numR=arrBoard[i][j+1];
          
          if(numR%boardSize!=0){
            numRY=numR%boardSize-1;
            numRX=numR/boardSize;
          }
          else if(numR%boardSize==0){
            numRY=boardSize-1;
            numRX=numR/boardSize-1;
          }
          diffR=abs((posX-numRX)+(posY+1-numRY));
        }

        if(posX-1!=-1){
          numU=arrBoard[i-1][j];
         
          if(numU%boardSize!=0){
            numUY=numU%boardSize-1;
            numUX=numU/boardSize;
          }
          else if(numU%boardSize==0){
            numUY=boardSize-1;
            numUX=numU/boardSize-1;
          }
          diffU=abs((posX-1-numUX)+(posY-numUY));
        }

        if(posX+1!=boardSize){
          numD=arrBoard[i+1][j];
           
          if(numD%boardSize!=0){
            numDY=numD%boardSize-1;
            numDX=numD/boardSize;
          }
          else if(numD%boardSize==0){
            numDY=boardSize-1;
            numDX=numD/boardSize-1;
          }
          diffD=abs((posX+1-numDX)+(posY-numDY));
        }
      }
    }
  }
  
  if(numU!=0 && diffU<diffR && diffU<diffL && diffU<diffD){
    cout<<"Intelligent move chooses U"<<endl;
    up(arrBoard,boardSize);
  }
  else if(numD!=0 && diffD<diffU && diffD<diffL && diffD<diffR){
    cout<<"Intelligent move chooses D"<<endl;
    down(arrBoard,boardSize);  
  }
  else if(numL!=0 && diffL<diffU && diffL<diffR && diffL<diffD){
    cout<<"Intelligent move chooses L"<<endl;
    left(arrBoard,boardSize);
  }
  else if(numR!=0 && diffR<diffU && diffR<diffD && diffR<diffL){
    cout<<"Intelligent move chooses R"<<endl;
    right(arrBoard,boardSize);
  }
  else{
    if(numU!=0){
      cout<<"Intelligent move chooses U"<<endl;
      up(arrBoard,boardSize);  
    }
    else if(numD!=0){
      cout<<"Intelligent move chooses D"<<endl;
      down(arrBoard,boardSize);   
    }
    else if(numL!=0){
      cout<<"Intelligent move chooses L"<<endl;
      left(arrBoard,boardSize); 
    }
    else if(numR!=0){
      cout<<"Intelligent move chooses R"<<endl;
      right(arrBoard,boardSize);  
    }
  }
  return 0;
}

/*Function to sort board to its final position*/
void sortBoard(int arrBoard[maxSize][maxSize], int boardSize) 
{ 
  int num=1;
  for(int i=0;i<boardSize;i++){
    for(int j=0; j<boardSize;j++){
      if(i==boardSize-1 && j==boardSize-1){

        arrBoard[i][j]=0;
      }
      else{

        arrBoard[i][j]=num;
        num++;
      } 
    }
  }
}

/*Function that compares two boards to see if game board is on final position*/
int checkIfItsFinal(int arrBoard[maxSize][maxSize],int checkBoard[maxSize][maxSize],int boardSize){
  int count=0;
  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(arrBoard[i][j]==checkBoard[i][j]){
        count++;
      }
      else if(arrBoard[i][j]!=checkBoard[i][j]){
        return -1;
      }
    }
  }
  return count;  
}  