/*File N_puzzle.cpp
 *This is the implementation file for class N_puzzle and nested class Board
 */
#include "N_puzzle.h"
#include <vector>

/* No parameter Board constructor*/
N_Puzzle::Board::Board() :lastMovePerformed('S')
{
	boardVec.resize(9);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			boardVec[i].push_back(-1);
		}
	}
	
}

/*Board constructor takes one parameter boardsize*/
N_Puzzle::Board::Board(int boardSize) : lastMovePerformed('S')
{ 
	boardVec.resize(boardSize);
	for(int i=0; i<boardVec.size(); i++){
		for(int j=0; j<boardVec.size(); j++){
			boardVec[i].push_back(-1);
		}
	}	
}
void N_Puzzle::Board::initBoard(int row,int column){
	//boardVec.resize(row);
	//boardVec[0].resize(column);
	cout<<boardVec.size();
	cout<<boardVec[0].size();
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			boardVec[i].push_back(-1);
		}
	}

}

int N_Puzzle::Board::numOfMoves=0;

/*Prints the board on screen sending it to cout*/
void N_Puzzle::Board::print() 
{
	for (int m = 0; m < boardVec.size(); m++){
        for (int k = 0; k < boardVec[0].size(); k++) {
          if(boardVec[m][k]!=100)
            cout << boardVec[m][k] << " ";
          else if(boardVec[m][k]==100)
            cout<<"  ";
        }
        cout<<endl;
  }
  cout<<endl;
}
/*Function reads the given file and determines boardVec.size() and boardVec[0].size() informations*/
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
	//determining boardVec.size() and boardVec[0].size() numbers according to file
	boardVec.resize(i);
	boardVec[(boardVec.size()-1)].resize(j/i);
	input.close();
}
/*Function reads and assigns the values from the file to game board using boardVec.size() and boardVec[0].size() informations*/
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
    for(i=0;i<boardVec.size();++i){
      for(j=0;j<boardVec[(boardVec.size()-1)].size();++j){
        input2>>readen;
        if(readen!="bb"){
          //Readen is type of string so i convert it to integer
          number=atoi(readen.c_str());
          boardVec[i][j]=number;
        }
        if(readen=="bb"){
          boardVec[i][j]=100;
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

		for(int i=0; i<boardVec.size() ;i++){
			for(int j=0; j<boardVec[0].size(); j++){
				if(boardVec[i][j]!=100 && boardVec[i][j]>9){
					output<<boardVec[i][j];
					if(j!=boardVec[0].size()-1)
						output<<" ";
				}

				else if(boardVec[i][j]<10){
					output<<"0"<<boardVec[i][j];
					if(j!=boardVec[0].size()-1)
						output<<" ";
				}
				else if(boardVec[i][j] == 100){
					output<<"bb";
				if(j!=boardVec[0].size()-1)
					output<<" ";
				}
			}
			if(i!=boardVec.size()-1)
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
	for(int i=0;i<boardVec.size();i++){
		
		for(int j=0; j<boardVec[0].size();j++){
			
			if(i==boardVec.size()-1 && j==boardVec[0].size()-1 && boardVec[i][j]!=0){

				boardVec[i][j]=100;
			}
			else if(boardVec[i][j]!=0){

				boardVec[i][j]=num;
				num++;
			} 
		}
	}
}
/*Sets the board size to given values. After setting the size, the boards should be reset.*/
void N_Puzzle::Board::setSize(int size,int size2){
	
	initBoard(size,size2);
	print();
	reset();
}
/*Function moves empty cell given direction,and updates game board array*/
int N_Puzzle::Board::move(char direction){
	int emptCellX, emptCellY;
	int num;

	for(int i=0; i<boardVec.size(); i++){
		for(int j=0; j<boardVec[(boardVec.size()-1)].size(); j++){
			if(boardVec[i][j]==100){
				emptCellX=i;
				emptCellY=j;
			}
		}
	}
	if (direction=='U'){
		
		if(emptCellX==0 || boardVec[emptCellX-1][emptCellY]==0){
			return -1;
		}
		else if(emptCellX!=0 && boardVec[emptCellX-1][emptCellY]!=0){
			num=boardVec[emptCellX-1][emptCellY];
			boardVec[emptCellX-1][emptCellY]=100;
			boardVec[emptCellX][emptCellY]=num;
			setNumOfMoves();
			setLastMove('U');
		}
		return 0;  
	}
	else if(direction== 'D'){

		if(emptCellX==boardVec.size()-1 || boardVec[emptCellX+1][emptCellY]==0){
			return -1; 
		}
		else if(emptCellX!=boardVec.size()-1 && boardVec[emptCellX+1][emptCellY]!=0){
			num=boardVec[emptCellX+1][emptCellY];
			boardVec[emptCellX+1][emptCellY]=100;
			boardVec[emptCellX][emptCellY]=num;
			setNumOfMoves();
			setLastMove('D');
		} 
		return 0;
	}
	else if(direction=='R'){

		if(emptCellY==boardVec[0].size()-1 || boardVec[emptCellX][emptCellY+1]==0){
			return -1;
		}

		else if(emptCellY!=boardVec[0].size()-1 && boardVec[emptCellX][emptCellY+1]!=0){
			num=boardVec[emptCellX][emptCellY+1];
			boardVec[emptCellX][emptCellY+1]=100;
			boardVec[emptCellX][emptCellY]=num;
			setNumOfMoves();
			setLastMove('R');
		} 
		return 0;
	}
	else if(direction=='L'){

		if(emptCellY==0 || boardVec[emptCellX][emptCellY-1]==0){ 
			return -1;
		}

		else if(emptCellY!=0 && boardVec[emptCellX][emptCellY-1]!=0){
			num=boardVec[emptCellX][emptCellY-1];
			boardVec[emptCellX][emptCellY-1]=100;
			boardVec[emptCellX][emptCellY]=num;
			setNumOfMoves();
			setLastMove('L');
		} 
		return 0;
	}
}

/*Function that controls if the board is solution,if true it returns logical true,else false*/
bool N_Puzzle::Board::isSolved(){

	int row=boardVec.size();
	int column=boardVec[0].size();
	int number=1;
	int count=0;
	for(int i=0; i<row; i++){
		for(int j=0; j<column;j++){
			if(boardVec[i][j]!=0 && boardVec[i][j]!=100){
				if(boardVec[i][j]==number){
					number++;
					count++;
				}
				else
					return false;
			}
		}
	}
	return true;
}
/*Operator == overlading returns true if two boards are equal*/
bool N_Puzzle::Board::operator ==( Board& rightSide){
	int count=0;
	int row=boardVec.size();
	int column=boardVec.back().size();

	for(auto i=0; i<row;i++){
		for(auto j=0; j<column;j++){
			if(boardVec[i][j]==rightSide.getNumberIndex(i,j)){
				count++;
			}
			else if(boardVec[i][j]!=rightSide.getNumberIndex(i,j)){
				return false;
			}	
		}
	}
	if(count==row*column) 
		return true;
}
/*() operator overloading, returns the number in given indexes if they're valid*/
int N_Puzzle::Board::operator ()(int index1,int index2){
	if((index1 >= 0 && index1 <= boardVec.size()) && (index2>=0 && index2<=boardVec.back().size()))
		return boardVec[index1][index2];
	else 
		return -1;
}
char N_Puzzle::Board::lastMove(){
	return lastMovePerformed;
}
int N_Puzzle::Board::numberOfMoves(){
	return numOfMoves;
}
N_Puzzle::N_Puzzle(){
	vecBoardObj.resize(0);
	Board b;
	vecBoardObj.push_back(b);
}
N_Puzzle::N_Puzzle(int boardSize){
	
	vecBoardObj.resize(0);
	Board b(boardSize);
	vecBoardObj.push_back(b);
	vecBoardObj[0].reset();
	shuffle(boardSize);

}

void N_Puzzle::print(){
	
	vecBoardObj[(vecBoardObj.size()-1)].print();
}
void N_Puzzle::printReport(int numberMove){

	int control;
	control=vecBoardObj.back().isSolved();
	if(control==1){
		cout<<"Problem solved!\n"<<"Total number of moves:"<<numberMove<<endl;
	}
	else{
		cout<<"Total number of moves:"<<numberMove<<endl;
	}
}
void N_Puzzle::readFromFile(ifstream &input,string filename){

	vecBoardObj[(vecBoardObj.size()-1)].readFromFile(input,filename);
}
void N_Puzzle::readAndAssign(ifstream &input,string filename){

	vecBoardObj[(vecBoardObj.size()-1)].readAndAssign(input,filename);
}
void N_Puzzle::writeToFile(ofstream &output,string &filename){

	vecBoardObj[(vecBoardObj.size()-1)].writeToFile(output,filename);
}
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
int N_Puzzle::move(char direction){

	vecBoardObj.back().move(direction);
}
void N_Puzzle::reset( ){

	vecBoardObj.back().reset();
}
void N_Puzzle::setSize(int size){
	
	getBoardObje(0).setSize(size,size);
	
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
		control=getBoardObje(0).move('U');
		} 
		if(randomMove==2){
		control=getBoardObje(0).move('D');
		} 
		if(randomMove==3){
		control=getBoardObje(0).move('L');
		} 
		if(randomMove==4){
		control=getBoardObje(0).move('R');
		} 
		/*Control is the return value for U,D,R,L functions
		If control is -1 this means there is no room for that choice
		If control is 0 this means cell is moved and size*size number increases*/
		if(control==0)
		i++;
	}
	return randomMove;
}

int N_Puzzle::solvePuzzle(){

	int row=vecBoardObj.back().getBoard().size();
	int column=(vecBoardObj.back().getBoard())[0].size();
	
	int control;

	int BoardVecIndex=0;
	Board toAdd(row);
	//toAdd.setSize(row,column);
	vecBoardObj[BoardVecIndex].print();
	/*Equalizing toAdd board with vecBoardObj[currentIndex]*/
	for(int i=0;i<row;i++){
		for(int j=0; j<column;j++){
			int adding= vecBoardObj[0].getNumberIndex(i,j);
			toAdd.setBoardIndex(i,j,adding);
		}
	}
	toAdd.print();
	int m=0;
	do{
		while(m<4){
			if(m==0){
				toAdd.move('U');
				cout<<"up\n";
				toAdd.print();
				vecBoardObj.push_back(toAdd);
				toAdd=vecBoardObj[BoardVecIndex];
			}
			if(m==1){
				toAdd.move('D');
				cout<<"down\n";
				toAdd.print();
				vecBoardObj.push_back(toAdd);
				toAdd=vecBoardObj[BoardVecIndex];
			}
			if(m==2){
				toAdd.move('R');
				cout<<"right\n";
				toAdd.print();
				vecBoardObj.push_back(toAdd);
				toAdd=vecBoardObj[BoardVecIndex];
			}
			if(m==3){
				toAdd.move('L');
				cout<<"left\n";
				toAdd.print();
				vecBoardObj.push_back(toAdd);
				toAdd=vecBoardObj[BoardVecIndex];
			}
			m++;
		}
		for(int i=0; i<vecBoardObj.size();i++){
			control=vecBoardObj[i].isSolved();
			
		}
	}while(control!=1);
	
	for(int i=0; i<vecBoardObj.size()+1;i++){
		vecBoardObj[i].print();
	}
	cout<<"end\n";
}
/*Operator << overloading*/
ostream& operator <<(ostream &outputStream, N_Puzzle& object){
	int row=object.getBoardVector().back().getBoard().size();
	int column=(object.getBoardVector().back().getBoard())[0].size();
	int index=object.getBoardVector().size();
	
	for(auto i=0; i<row;i++){
		for(auto j=0; j<column;j++){
			if(object.getBoardObje(index-1).getNumberIndex(i,j)!=100)
				outputStream <<object.getBoardObje(index-1).getNumberIndex(i,j) << " ";
			else if(object.getBoardObje(index-1).getNumberIndex(i,j)==100)
				outputStream<<"  ";
		}
		outputStream<<endl;	
	}
	return outputStream;
}

/*Operator >> overloading*/
istream& operator >>(istream &inputStream,N_Puzzle& object){
	int row=object.getBoardVector().back().getBoard().size();
	int column=(object.getBoardVector().back().getBoard())[0].size();
	int index=object.getBoardVector().size();
  	std::string readen;
  	int i=0,j=0;
  	int number=0;

	  while(!inputStream.eof()){
	    for(i=0;i<row;++i){
	      for(j=0;j<column;++j){
	        inputStream>>readen;
	        if(readen!="bb"){
	          //Readen is type of string so i convert it to integer
	          number=atoi(readen.c_str());
	         object.getBoardObje(index-1).setBoardIndex(i,j,number);
	        }
	        if(readen=="bb"){
	         object.getBoardObje(index-1).setBoardIndex(i,j,100);
	        } 
	      }
	    }
	  }
	}	
