/*This is the cpp file for function definitions*/
#include "source.h"

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
                if (arrBoard[x][y]!=-1 && arrBoard[x][y] == random ){
                      isThere = false;
                }
              }         
            }
          }
          while (isThere==false  );

            arrBoard[i][j] = random;

    }
  }
  //For loop to change value 0 to 100 because i take 'bb' as 100 while reading from file
  //so printing and other changes could work wrong if empty cell stays at 0.
  for(int i=0; i<boardSize; i++){
    for(int j=0; j<boardSize; j++){
      if(arrBoard[i][j]==0)
        arrBoard[i][j]=100;
    }
  }
  cout<<"Your initial random board is:"<<endl;
  printBoard(arrBoard,boardSize,boardSize);
}

/*Prints the board on screen*/
/*inline void printBoard(int arrBoard[maxSize][maxSize],int row,int column){

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
}*/

/*moves the empty cell up if there is room*/
int up(int arrBoard[maxSize][maxSize],int row,int column){

  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(arrBoard[i][j]==100){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellX==0 || arrBoard[emptCellX-1][emptCellY]==0){
    return -1;
  }
  else if(emptCellX!=0 && arrBoard[emptCellX-1][emptCellY]!=0){
    num=arrBoard[emptCellX-1][emptCellY];
    arrBoard[emptCellX-1][emptCellY]=100;
    arrBoard[emptCellX][emptCellY]=num;
  }
  return 0;  
}
/*moves the empty cell down if there is room*/
int down(int arrBoard[maxSize][maxSize],int row,int column){
  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(arrBoard[i][j]==100){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellX==row-1 || arrBoard[emptCellX+1][emptCellY]==0){
    return -1; 
  }
  else if(emptCellX!=row-1 && arrBoard[emptCellX+1][emptCellY]!=0){
    num=arrBoard[emptCellX+1][emptCellY];
    arrBoard[emptCellX+1][emptCellY]=100;
    arrBoard[emptCellX][emptCellY]=num;
  } 
  return 0;
}
/*moves the empty cell left if there is room*/
int left(int arrBoard[maxSize][maxSize],int row,int column){
  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(arrBoard[i][j]==100){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellY==0 || arrBoard[emptCellX][emptCellY-1]==0){ 
    return -1;
  }
  
  else if(emptCellY!=0 && arrBoard[emptCellX][emptCellY-1]!=0){
    num=arrBoard[emptCellX][emptCellY-1];
    arrBoard[emptCellX][emptCellY-1]=100;
    arrBoard[emptCellX][emptCellY]=num;
  } 
  return 0;
}
/*moves the empty cell right if there is room*/
int right(int arrBoard[maxSize][maxSize],int row,int column){
  int emptCellX, emptCellY;
  int num;

  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      if(arrBoard[i][j]==100){
        emptCellX=i;
        emptCellY=j;
      }
    }
  }
  if(emptCellY==column-1 || arrBoard[emptCellX][emptCellY+1]==0){
    return -1;
  }
  
  else if(emptCellY!=column-1 && arrBoard[emptCellX][emptCellY+1]!=0){
    num=arrBoard[emptCellX][emptCellY+1];
    arrBoard[emptCellX][emptCellY+1]=100;
    arrBoard[emptCellX][emptCellY]=num;
  } 
  return 0;
}

/*Takes the board to the final solution, and
makes size*size random moves to shuffle the board.*/
int shuffle(int arrBoard[maxSize][maxSize],int row,int column){
  
  /*Making size*size random moves to shuffle the board*/
  int randomMove;
  int control=0;
  int i=0;
  /*This loop written for shuffle the board making ramdom moves size*size.
   But if there is an impossible move, i call random func. again to make sure
   the board is shuffled properly */
  while( i<row*column){

    randomMove = (rand() % 4)+1 ;
    if(randomMove==1){
      control=up(arrBoard,row,column);
    } 
    if(randomMove==2){
      control=down(arrBoard,row,column);
    } 
    if(randomMove==3){
      control=left(arrBoard,row,column);
    } 
    if(randomMove==4){
      control=right(arrBoard,row,column);
    } 
    /*Control is the return value for U,D,R,L functions
     If control is -1 this means there is no room for that choice
     If control is 0 this means cell is moved and size*size number increases*/
    if(control==0)
      i++;
  }
  
  return 0;
}

/*moves empty cell to get closer the final position*/
/*For intelligent move i find other numbers around the empty cell,
then i determined their current positions and final positions
the most closer number to its final position moved*/
int intelligent(int arrBoard[maxSize][maxSize],int row,int column){
 
  int numL=0,numR=0,numU=0,numD=0; //numbers around the empty cell,initially 0
  int numLX,numLY,numRX,numRY,     //number's final positions around empty cell
      numUX,numUY,numDX,numDY;
  int diffU=0,diffD=0,diffR=0,diffL=0;    //difference between values final and current positions
  int posX,posY;
  for(int i=0; i<row;i++){
    for(int j=0; j<column;j++){
      if(arrBoard[i][j]==100){
        posX=i;
        posY=j;
        //Determining numbers around the empty cell if there is place
        if(posY-1!=-1){
          numL=arrBoard[i][j-1];
          
          if(numL%column!=0){
            numLY=numL%column-1;
            numLX=numL/row;
          }
          else if(numL%column==0){
            numLY=column-1;
            numLX=numL/row-1;
          }
          diffL=abs((posX-numLX)+(posY-1-numLY));
        }

        if(posY+1!=column){
          numR=arrBoard[i][j+1];
          
          if(numR%column!=0){
            numRY=numR%column-1;
            numRX=numR/row;
          }
          else if(numR%column==0){
            numRY=column-1;
            numRX=numR/row-1;
          }
          diffR=abs((posX-numRX)+(posY+1-numRY));
        }

        if(posX-1!=-1){
          numU=arrBoard[i-1][j];
         
          if(numU%column!=0){
            numUY=numU%column-1;
            numUX=numU/row;
          }
          else if(numU%column==0){
            numUY=column-1;
            numUX=numU/row-1;
          }
          diffU=abs((posX-1-numUX)+(posY-numUY));
        }

        if(posX+1!=row){
          numD=arrBoard[i+1][j];
           
          if(numD%column!=0){
            numDY=numD%column-1;
            numDX=numD/row;
          }
          else if(numD%column==0){
            numDY=column-1;
            numDX=numD/row-1;
          }
          diffD=abs((posX+1-numDX)+(posY-numDY));
        }
      }
    }
  }
  
  if(numU!=0 && diffU<diffR && diffU<diffL && diffU<diffD){
   
    cout<<"Intelligent move chooses U"<<endl;
    up(arrBoard,row,column);
  }
  else if(numD!=0 && diffD<diffU && diffD<diffL && diffD<diffR){
  
    cout<<"Intelligent move chooses D"<<endl;
    down(arrBoard,row,column);  
  }
  else if(numL!=0 && diffL<diffU && diffL<diffR && diffL<diffD){
    
    cout<<"Intelligent move chooses L"<<endl;
    left(arrBoard,row,column);
  }
  else if(numR!=0 && diffR<diffU && diffR<diffD && diffR<diffL){
   
    cout<<"Intelligent move chooses R"<<endl;
    right(arrBoard,row,column);
  }
  /*Else chooses random move*/
  else{
    int randomMove;
    int control=0;
    int m=0;
    do{
    randomMove = (rand() % 4)+1 ;
    if(randomMove==1){
      control=up(arrBoard,row,column);
      if(control==0)
        cout<<"Intelligent move chooses U:"<<endl;
    } 
    if(randomMove==2){
      control=down(arrBoard,row,column);
      if(control==0)
        cout<<"Intelligent move chooses D:"<<endl;
    } 
    if(randomMove==3){
      control=left(arrBoard,row,column);
      if(control==0)
        cout<<"Intelligent move chooses L:"<<endl;
    } 
    if(randomMove==4){
      control=right(arrBoard,row,column);
      if(control==0)
        cout<<"Intelligent move chooses R:"<<endl;
    } 
    /*Control is the return value for U,D,R,L functions
     If control is -1 this means there is no room for that choice
     If control is 0 this means cell is moved*/
    if(control==0)
      m++;
    
  } while(m==0);
    
  }
  return 0;
} 

/*Function to sort board to its final position*/
void sortBoard(int arrBoard[maxSize][maxSize],int row,int column) 
{ 
  int num=1;
  for(int i=0;i<row;i++){
    for(int j=0; j<column;j++){
      if(i==row-1 && j==column-1 && arrBoard[i][j]!=0){

        arrBoard[i][j]=100;
      }
      else if(arrBoard[i][j]!=0){

        arrBoard[i][j]=num;
        num++;
      } 
    }
  }
}

/*Function that compares two boards to see if game board is on final position*/
int checkIfItsFinal(int arrBoard[maxSize][maxSize],int checkBoard[maxSize][maxSize],int row,int column){
  int count=0;
  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
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

/*Function equalizes two arrays.Will be used for readen txt file's to use correctly*/
int equalizeArrays(int arrBoard[maxSize][maxSize],int checkBoard[maxSize][maxSize],int row,int column){

  for(int i=0; i<row; i++){
    for(int j=0; j<column; j++){
      checkBoard[i][j]=arrBoard[i][j];
    }
  }
  return 0;
}

/*Function that reads name's given txt file and determines its row and column 
 Takes a line and splits that line every line gives row and every element in that line gives column*/
void readFromFile(ifstream &input,string filename,int &row,int &column){
  
  input.open(filename.c_str());
  char readen[size];
  char *point;       //will used for strtok
  int i=0,j=0;

  if(input.fail()){
    cerr<<"Error opening file!";
    exit(1);
  }
  while(!input.eof()){

    input.getline(readen,size);
    point=strtok(readen," ");

    while(point!=NULL){

      point=strtok(NULL," ");
      j++;
    }
    i++;
  }
  //determining row and column numbers to use in 2D array later
  row=i;
  column=j/i;
  input.close();
}

/*Function reads given file and assign its values to 2D array  with given row and column size
  Readen is a string variable but 2D array is type of int so type converting used.*/
void readAndAssign(ifstream &input2,string filename,int arrBoard[maxSize][maxSize],int row,int column){
  
  cout<<endl;
  input2.open(filename.c_str());
  std::string readen;
  int i=0,j=0;
  int number=0;
  if(input2.fail()){
    cerr<<"Error opening file!";
    exit(1);
  }
  while(!input2.eof()){
    for(i=0;i<row;++i){
      for(j=0;j<column;++j){
        input2>>readen;
        if(readen!="bb"){
          //Readen is type of string so i convert it to integer
          number=atoi(readen.c_str());
          arrBoard[i][j]=number;
        }
        if(readen=="bb"){
          arrBoard[i][j]=100;
        } 
      }
    }
  }

}

/*Function writes given array on a txt file which name is given by user*/
void printOnFile(ofstream &output,string &filename2,int arrBoard[maxSize][maxSize],int row,int column){
  
  output.open(filename2.c_str()); 
  if(output.fail()){
    cerr<<"Error opening file!";
    exit(1);
  }
  if(output.is_open()){

  for(int i=0; i<row ;i++){
    for(int j=0; j<column; j++){
      if(arrBoard[i][j]!=100 && arrBoard[i][j]>9){
        output<<arrBoard[i][j];
        if(j!=column-1)
          output<<" ";
      }

      else if(arrBoard[i][j]<10){
        output<<"0"<<arrBoard[i][j];
        if(j!=column-1)
          output<<" ";
      }
      else if(arrBoard[i][j] == 100){
        output<<"bb";
        if(j!=column-1)
          output<<" ";
      }
    }
    if(i!=row-1)
      output<<"\n";
  }
  }
  else 
  cerr<<"Error opening file!\n";
  output.close();
}
