/*File N_Puzzle.cpp
 * Implementation file for the class N_Puzzle
 */

#include "N_Puzzle.h"

/*No parameter constructor*/
N_Puzzle::N_Puzzle(){
	Board();
}
/*Constructor that initializes board from file*/
N_Puzzle::N_Puzzle(ifstream &input,string filename){
	Board();
	boardObje.readFromFile(input,filename);
	boardObje.readAndAssign(input,filename);
}

/*Constructor that initializes board randomly */
N_Puzzle::N_Puzzle(int boardSize){
	
	boardObje.setRow(boardSize);
	boardObje.setColumn(boardSize);
	boardObje.initRandomly(boardSize);
	//Board(boardSize); 
	
}
/* No parameter Board constructor*/
N_Puzzle::Board::Board() : row(9) ,column(9)
{
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			arrBoard[i][j]=-1;
		}
	}
}

/*Board constructor which takes 2 parameter row and column*/
N_Puzzle::Board::Board(int n_row,int n_column) : row(n_row),column(n_column)
{ 
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			arrBoard[i][j]=-1;
		}
	}	
}

/*Board constructor takes one parameter boardsize*/
N_Puzzle::Board::Board(int boardSize) : row(boardSize),column(boardSize)
{ 
	for(int i=0; i<boardSize; i++){
		for(int j=0; j<boardSize; j++){
			arrBoard[i][j]=-1;
		}
	}
}


/*Function that prints the array in Board class*/
void N_Puzzle::Board::print() 
{
	row=getRow();
	column=getColumn();

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

/*Function reads the given file and determines row and column informations*/
void N_Puzzle::Board::readFromFile(ifstream &input,string filename){
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
	//determining row and column numbers according to file
	setRow(i);
	setColumn(j/i);
	input.close();
}
/*Function reads and assigns the values from the file to game board using row and column informations*/
void N_Puzzle::Board::readAndAssign(ifstream &input2,string filename){

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

/*Function loads the current board configuration to the given file*/
void N_Puzzle::Board::writeToFile(ofstream &output,string &filename2){
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

/*Function resets board to the solution*/
void N_Puzzle::Board::reset(){
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

/*Sets the board size to given values. After setting the size, the boards should be reset.*/
void N_Puzzle::Board::setSize(int size){
	row=size;
	column=size;
	reset();
}
/*Function moves empty cell given direction,and updates game board array*/
int N_Puzzle::Board::move(char direction){
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
	if (direction=='U'){
		
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
	else if(direction== 'D'){

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
	else if(direction=='R'){

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
	else if(direction=='L'){

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
}
/*Function that controls if the board is solution,if true it returns logical true,else false*/
bool N_Puzzle::Board::isSolved(){

	Board controlObje(row,column);
	controlObje.reset();

	int count=0;
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			if(arrBoard[i][j]==controlObje.getArrayBoardIndex(i,j)){
				count++;
			}
			else if(arrBoard[i][j]!=controlObje.getArrayBoardIndex(i,j)){
				return false;
			}
		}
	}
	if(count==row*column) 
		return true;
}
/*Function initializes the game board randomly with given size*/
void N_Puzzle::Board::initRandomly(int size){
	int added = size*size;
	srand(time(NULL)); 

	int x=0,y=0;
	int random;
	bool isThere=true;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++){
		    do{
		        random = (rand() % added) ;
		        isThere=true;

		        for ( x = 0; x<size && isThere==true; x++){
		          for ( y = 0; y <size && isThere==true; y++){  
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
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
		  if(arrBoard[i][j]==0)
		    arrBoard[i][j]=100;
		}
	}
}
/*Prints the board current configuration*/
void N_Puzzle::print(){
	boardObje.print();
}
/*Prints report about how many moves have been done and if the solution is found*/
int N_Puzzle::printReport(int numberMove){
	
	int control;
	control=boardObje.isSolved();
	if(control==1){
		cout<<"Problem solved!\n"<<"Total number of moves:"<<numberMove<<endl;
	}
	else{
		cout<<"Total number of moves:"<<numberMove<<endl;
	}
	return 0;
}
void N_Puzzle::readFromFile(ifstream &input,string filename){

	boardObje.readFromFile(input,filename);
}
void N_Puzzle::readAndAssign(ifstream &input,string filename){

	boardObje.readAndAssign(input,filename);
}
void N_Puzzle::writeToFile(ofstream &output,string &filename){

	boardObje.writeToFile(output,filename);
}

/*Function that shuffles the board N*N random moves*/
int N_Puzzle::shuffle(int N){
	/*First reset the board to the solution*/
	reset();
	
	int randomMove;
	int control=0;
	int i=0;
	/*This loop written for shuffle the board making ramdom moves size*size.
	But if there is an impossible move, i call random func. again to make sure
	the board is shuffled properly */
	while( i<N*N){

	randomMove = (rand() % 4)+1 ;
	if(randomMove==1){
		control=move('U');
	} 
	if(randomMove==2){
		control=move('D');
	} 
	if(randomMove==3){
		control=move('L');
	} 
	if(randomMove==4){
		control=move('R');
	} 
	/*Control is the return value for U,D,R,L functions
	If control is -1 this means there is no room for that choice
	If control is 0 this means cell is moved and size*size number increases*/
	if(control==0)
		i++;
	}
	//cout<<"Shuffled version:\n";
	//print();
	return 0;
}
void N_Puzzle::reset( ){

	boardObje.reset();
}
void N_Puzzle::setSize(int size){

	boardObje.setSize(size);
}
/*Function that makes one valid random move*/
int N_Puzzle::moveRandom(){

	int randomMove;
	int control=0;
	int i=0;
	/*While loop written for make one valid random move*/
	while( i!=1){

		randomMove = (rand() % 4)+1 ;
		cout<<randomMove<<endl;
		if(randomMove==1){
		control=boardObje.move('U');
		} 
		if(randomMove==2){
		control=boardObje.move('D');
		} 
		if(randomMove==3){
		control=boardObje.move('L');
		} 
		if(randomMove==4){
		control=boardObje.move('R');
		} 
		/*Control is the return value for U,D,R,L functions
		If control is -1 this means there is no room for that choice
		If control is 0 this means cell is moved and size*size number increases*/
		if(control==0)
		i++;
	}
	return randomMove;
}

/*Function that chooses a move like U, R, L, D intelligently
 *Determines numbers around empty cell and their current positions and final positions,chooses shortest distance
 * to the final solution,if there is equality, chooses random between them.
 */
int N_Puzzle::moveIntelligent(){
  int numL=0,numR=0,numU=0,numD=0; //numbers around the empty cell,initially 0
  int numLX,numLY,numRX,numRY,     //number's final positions around empty cell
      numUX,numUY,numDX,numDY;
  int diffU=0,diffD=0,diffR=0,diffL=0;    //difference between values final and current positions
  int posX,posY;
  int row=boardObje.getRow();  
  int column=boardObje.getColumn();
  int index;
  index=boardObje.getArrayBoardIndex(row,column);

  for(int i=0; i<row;i++){
    for(int j=0; j<column;j++){
      if(index==100){ 
        posX=i;
        posY=j;
        //Determining numbers around the empty cell if there is place
        if(posY-1!=-1){
          numL=boardObje.getArrayBoardIndex(row,column-1);
          
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
          numR=boardObje.getArrayBoardIndex(row,column+1);
          
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
          numU=boardObje.getArrayBoardIndex(row-1,column);
         
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
          numD=boardObje.getArrayBoardIndex(row+1,column);
           
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
    move('U');
  }
  else if(numD!=0 && diffD<diffU && diffD<diffL && diffD<diffR){
  
    cout<<"Intelligent move chooses D"<<endl;
    move('D') ;
  }
  else if(numL!=0 && diffL<diffU && diffL<diffR && diffL<diffD){
    
    cout<<"Intelligent move chooses L"<<endl;
    move('L');
  }
  else if(numR!=0 && diffR<diffU && diffR<diffD && diffR<diffL){
   
    cout<<"Intelligent move chooses R"<<endl;
    move('R');  
 }
  /*Else chooses random move*/
  else{
    int randomMove;
    int control=0;
    int m=0;
	    do{
	    randomMove = (rand() % 4)+1 ;
	    if(randomMove==1){
	      control=move('U');
	      if(control==0)
	        cout<<"Intelligent move chooses U:"<<endl;
	    } 
	    if(randomMove==2){
	      control=move('D');
	      if(control==0)
	        cout<<"Intelligent move chooses D:"<<endl;
	    } 
	    if(randomMove==3){
	      control=move('L');
	      if(control==0)
	        cout<<"Intelligent move chooses L:"<<endl;
	    } 
	    if(randomMove==4){
	      control=move('R');
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
}

/*Function moves the empty cell to given direction*/
int N_Puzzle::move(char direction){

	boardObje.move(direction);
}

/*Function that solves puzzle using moveIntelligent*/
int N_Puzzle::solvePuzzle(){
	auto numOfMovesForSolve=0;
	auto i=0;
	auto control=0;
	int randomMove;
	decltype(randomMove) lastMove;

	shuffle(boardObje.getRow()*boardObje.getColumn()); //shuffling board to receive solution easily
	/*While loop works until the receive solution*/
	while(control!=1){
		moveIntelligent();
		print();
		while(i<4){
			randomMove=moveRandom();
			if(randomMove==1)
				cout<<"Intelligent move chooses U:\n";
			if(randomMove==2)
				cout<<"Intelligent move chooses D:\n";
			if(randomMove==3)
				cout<<"Intelligent move chooses L:\n";
			if(randomMove==4)
				cout<<"Intelligent move chooses R:\n";
			lastMove=randomMove;
			i++;
			print();
		}
		control=boardObje.isSolved();
		numOfMovesForSolve++;
	}
	/*return the number of moves for this action*/
	return numOfMovesForSolve;
}

