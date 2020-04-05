/*File BoardArray1D.cpp
 *This is the implementation file for class BoardArray1D*/

#include "boardArray1D.h"

namespace EsraNameSpace{
	//No parameter constructor
	BoardArray1D::BoardArray1D(): row(9),column(9)
	{
		arr1D = new int[9*9];
		
		for(int i=0;i<row*column;i++){
				arr1D[i]=-1;
		}
		setNumOfBoard();
		setLastMove('S');
	}

	//Constructor takes row and column
	BoardArray1D::BoardArray1D(int nrow,int ncolumn): row(nrow),column(ncolumn)
	{
		arr1D = new int[row*column];

		for(int i=0;i<row*column;i++){
				arr1D[i]=-1;
		}
		setNumOfBoard();
		setLastMove('S');
	}

	//Constructor takes size
	BoardArray1D::BoardArray1D(int size): row(size),column(size)
	{
		arr1D = new int[size*size];
		
		for(int i=0;i<row*column;i++){
				arr1D[i]=-1;
		}
		setNumOfBoard();
		setLastMove('S');
	}

	//Destructor
	BoardArray1D::~BoardArray1D(){

		delete [] arr1D;
	}
	//Copy constructor
	BoardArray1D::BoardArray1D(const BoardArray1D& object){
		row=object.getRow();
		column=object.getColumn();
		numOfMovesPerformed=object.numberOfMoves();
		numOfBoardsCreated=object.numberOfBoards();
		lastMovePerf=object.lastMove();
		arr1D = new int[row*column];
		
		for(int i=0; i<row;i++){
			for(int j=0; j<column;j++){
				arr1D[i*column+j]=object.getIndex(i,j);
			}
		}

	}
	//Assignment operator
	BoardArray1D& BoardArray1D::operator =(const BoardArray1D& rightSide){
		//Error check for control objects are same size
		if (row= rightSide.getRow() && column==rightSide.getColumn()){
			for(int i=0; i<row;i++){
				for(int j=0; j<row;j++){
					arr1D[i*column+j]=rightSide.getIndex(i,j);
				}
			}
		}
		else
			cout<<"Objects are not same size!";
	}

	//Prints the board by sending it to cout
	void BoardArray1D::print(){

		for (int m = 0; m < row; m++){
	        for (int k = 0; k < column; k++) {
	          if(arr1D[m*column+k]!=100)
	            cout << arr1D[m*column+k] << " ";
	          else if(arr1D[m*column+k]==100)
	            cout<<"bb ";
	        }
	        cout<<endl;
	  }
	  cout<<endl;
	}

	//Reads file and determines new row and column informations
	void BoardArray1D::readFromFile(ifstream &input,string filename){
		
		input.open(filename.c_str());
		char readen[100];
	  	char *point;       //will used for strtok
	  	int i=0,j=0;

		if(input.fail()){
		    cerr<<"Error opening file!";
		    exit(1);
		}
		while(!input.eof()){

		    input.getline(readen,100);
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

	//Reads file and assigns the values from file to board				
	void BoardArray1D::readAndAssign(ifstream &input,string filename){

		delete [] arr1D;

		arr1D = new int[getRow()*getColumn()];
		
		input.open(filename.c_str());
		std::string readen;
		int i=0,j=0;
		int number=0;
		if(input.fail()){
		cerr<<"Error opening file!";
		exit(1);
		}
		
		while(!input.eof()){
			for(i=0;i<row;++i){
			  for(j=0;j<column;++j){
			    input>>readen;
			    if(readen!="bb"){
			      //Readen is type of string so i convert it to integer
			      number=atoi(readen.c_str());
			     
			      arr1D[i*column+j]=number;
			    }
			    if(readen=="bb"){
			    	
			      arr1D[i*column+j]=100;
			    } 
			  }
			}
  		}

	}

	//Writes the board configuration to given file
	void BoardArray1D::writeToFile(ofstream &output,string &filename){
		
		output.open(filename.c_str()); 
		if(output.fail()){
			cerr<<"Error opening file!";
			exit(1);
		}
		if(output.is_open()){

			for(int i=0; i<row ;i++){
				for(int j=0; j<column; j++){
					if(arr1D[i*column+j]!=100 && arr1D[i*column+j]>9){
						output<<arr1D[i*column+j];
						if(j!=column-1)
							output<<" ";
					}

					else if(arr1D[i*column+j]<10){
						output<<"0"<<arr1D[i*column+j];
						if(j!=column-1)
							output<<" ";
					}
					else if(arr1D[i*column+j] == 100){
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

	//Resets board to the solution
	void BoardArray1D::reset(){
		
		int num=1;
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				if(i==row-1 && j==column-1 && arr1D[i*column+j]!=0){

					arr1D[i*column+j]=100;
				}
				else if(arr1D[i*column+j]!=0){

					arr1D[i*column+j]=num;
					num++;
				} 
			}
		}
	}

	//Sets the size and resets the board
	void BoardArray1D::setSize(int rowS,int columnS){
		
		setRow(rowS);
		setColumn(columnS);
		delete [] arr1D;

		arr1D = new int[getRow()*getColumn()];
		
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				arr1D[i*column+j]=-1;
			}
		}
		reset();
	}

	//Moves the empty cell to the given direction
	int BoardArray1D::move(char direction){
		int emptCellX, emptCellY;
		int num;

		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				if(arr1D[i*column+j]==100){
					emptCellX=i;
					emptCellY=j;
				}
			}
		}
		if (direction=='U'){
			
			if(emptCellX==0 || arr1D[((emptCellX-1))*column+emptCellY]==0){
				return -1;
			}
			else if(emptCellX!=0 && arr1D[((emptCellX-1))*column+emptCellY]!=0){
				num=arr1D[((emptCellX-1))*column+emptCellY];
				arr1D[(emptCellX-1)*column+emptCellY]=100;
				arr1D[emptCellX*column+emptCellY]=num;
				setLastMove('U');
				setNumOfMove();
			}
			return 0;  
		}
		else if(direction== 'D'){

			if(emptCellX==row-1 || arr1D[(emptCellX+1)*column+emptCellY]==0){
				return -1; 
			}
			else if(emptCellX!=row-1 && arr1D[(emptCellX+1)*column+emptCellY]!=0){
				num=arr1D[(emptCellX+1)*column+emptCellY];
				arr1D[(emptCellX+1)*column+emptCellY]=100;
				arr1D[emptCellX*column+emptCellY]=num;
				setLastMove('D');
				setNumOfMove();
			} 
			return 0;
		}
		else if(direction=='R'){

			if(emptCellY==column-1 || arr1D[emptCellX*column+(emptCellY+1)]==0){
				return -1;
			}

			else if(emptCellY!=column-1 && arr1D[emptCellX*column+(emptCellY+1)]!=0){
				num=arr1D[emptCellX*column+(emptCellY+1)];
				arr1D[emptCellX*column+(emptCellY+1)]=100;
				arr1D[emptCellX*column+emptCellY]=num;
				setLastMove('R');
				setNumOfMove();
			} 
			return 0;
		}
		else if(direction=='L'){

			if(emptCellY==0 || arr1D[emptCellX*column+(emptCellY-1)]==0){ 
				return -1;
			}

			else if(emptCellY!=0 && arr1D[emptCellX*column+(emptCellY-1)]!=0){
				num=arr1D[emptCellX*column+(emptCellY-1)];
				arr1D[emptCellX*column+(emptCellY-1)]=100;
				arr1D[emptCellX*column+emptCellY]=num;
				setLastMove('L');
				setNumOfMove();
			} 
			return 0;
		}
	}

	//Shuffles the board
	int BoardArray1D::shuffle(){
		/*First reset the board to the solution*/
		reset();
		
		int randomMove;
		int control=0;
		int i=0;
		/*This loop written for shuffle the board making ramdom moves size*size.
		But if there is an impossible move, i call random func. again to make sure
		the board is shuffled properly */
		while( i<row*column){

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

	//Returns true if board is solved
	bool BoardArray1D::isSolved(){
		BoardArray1D controlObje(row,column);
		controlObje.reset();

		int count=0;
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				if(arr1D[i*column+j]==controlObje.getIndex(i,j)){
					count++;
				}
				else if(arr1D[i*column+j]!=controlObje.getIndex(i,j)){
					cout<<"Problem is not solved.\n";
					return false;
				}
			}
		}
		if(count==row*column) {
			cout<<"Problem is solved!\n";
			return true;
		}
	}

	//Returns true if two boards are equal
	bool BoardArray1D::operator ==(const BoardArray1D& rightSide)  {
		int count=0;

		for(auto i=0; i<row;i++){
			for(auto j=0; j<column;j++){
				if(arr1D[(i*column)+j]==rightSide.getIndex(i,j)){
					count++;
				}
				else if(arr1D[(i*column)+j]!=rightSide.getIndex(i,j)){
					return false;
				}	
			}
		}
		if(count==row*column) 
			return true;	
	}

	/*() operator overloading, returns the number in given indexes if they're valid*/
	int BoardArray1D::operator ()(int index1,int index2){
		
		if((index1 >= 0 && index1 <= getRow()) && (index2>=0 && index2<=getColumn()))
			return arr1D[index1*column+index2];
		else 
			return -1;
	}

	//Returns the coordinates of empty cell
	void BoardArray1D::getEmptyCellX_Y(int &cellX,int &cellY){
		for(auto i=0; i<getRow();i++){
			for(auto j=0;j<getColumn();j++){
				if(arr1D[((i*getColumn())+j)]==100){
					cellX=i;
					cellY=j;
				}
			}
		}
	}
	
}//end of namespace