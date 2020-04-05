/*File boardArray2D.cpp
 *This is the implementation file for class BoardArray2D*/

#include "boardArray2D.h"

namespace EsraNameSpace{

	//No parameter constructor
	BoardArray2D::BoardArray2D(): row(9),column(9)
	{
		arr2D = new int*[9];
		for(int i=0; i<row;i++){
			arr2D[i]=new int[9];
		}
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				arr2D[i][j]=-1;
			}
		}
		setNumOfBoard();
		setLastMove('S');
	}

	//Constructor takes row and column
	BoardArray2D::BoardArray2D(int nrow,int ncolumn): row(nrow),column(ncolumn)
	{
		arr2D = new int*[row];
		for(int i=0; i<row;i++){
			arr2D[i]=new int[column];
		}
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				arr2D[i][j]=-1;
			}
		}
		setNumOfBoard();
		setLastMove('S');
	}
	//Constructor takes size
	BoardArray2D::BoardArray2D(int size): row(size),column(size)
	{
		arr2D = new int*[size];
		for(int i=0; i<size;i++){
			arr2D[i]=new int[size];
		}
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				arr2D[i][j]=-1;
			}
		}
		setNumOfBoard();
		setLastMove('S');
	}

	//Destructor
	BoardArray2D::~BoardArray2D(){
		for (int i = 0; i < row; i++)
  			delete [] arr2D[i]; 
		delete [] arr2D;
	}
	//Copy constructor
	BoardArray2D::BoardArray2D(const BoardArray2D& object){
		row=object.getRow();
		column=object.getColumn();
		numOfMovesPerformed=object.numberOfMoves();
		numOfBoardsCreated=object.numberOfBoards();
		lastMovePerf=object.lastMove();
		arr2D = new int*[row];
		for(int i=0; i<row;i++){
			arr2D[i]=new int[column];
		}
		for(int i=0; i<row;i++){
			for(int j=0; j<column;j++){
				arr2D[i][j]=object.getIndex(i,j);
			}
		}

	}
	//Assignment operator
	BoardArray2D& BoardArray2D::operator =(const BoardArray2D& rightSide){
		//Error check for control objects are same size
		if (row= rightSide.getRow() && column==rightSide.getColumn()){
			for(int i=0; i<row;i++){
				for(int j=0; j<row;j++){
					arr2D[i][j]=rightSide.getIndex(i,j);
				}
			}
		}
		else
			cout<<"Objects are not same size!";
	}
	//Prints the board by sending it to cout
	void BoardArray2D::print(){

		for (int m = 0; m < row; m++){
	        for (int k = 0; k < column; k++) {
	          if(arr2D[m][k]!=100)
	            cout << arr2D[m][k] << " ";
	          else if(arr2D[m][k]==100)
	            cout<<"bb ";
	        }
	        cout<<endl;
	  }
	  cout<<endl;
	}

	//Reads file and determines new row and column informations
	void BoardArray2D::readFromFile(ifstream &input,string filename){
		
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
	void BoardArray2D::readAndAssign(ifstream &input,string filename){

		delete [] arr2D;

		arr2D = new int*[getRow()];
		for(int i=0; i<getRow();i++){
			arr2D[i]=new int[getColumn()];
		}
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
			     
			      arr2D[i][j]=number;
			    }
			    if(readen=="bb"){
			    	
			      arr2D[i][j]=100;
			    } 
			  }
			}
  		}

	}

	//Writes the board configuration to given file
	void BoardArray2D::writeToFile(ofstream &output,string &filename){
		
		output.open(filename.c_str()); 
		if(output.fail()){
			cerr<<"Error opening file!";
			exit(1);
		}
		if(output.is_open()){

			for(int i=0; i<row ;i++){
				for(int j=0; j<column; j++){
					if(arr2D[i][j]!=100 && arr2D[i][j]>9){
						output<<arr2D[i][j];
						if(j!=column-1)
							output<<" ";
					}

					else if(arr2D[i][j]<10){
						output<<"0"<<arr2D[i][j];
						if(j!=column-1)
							output<<" ";
					}
					else if(arr2D[i][j] == 100){
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
	void BoardArray2D::reset(){
		
		int num=1;
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				if(i==row-1 && j==column-1 && arr2D[i][j]!=0){

					arr2D[i][j]=100;
				}
				else if(arr2D[i][j]!=0){

					arr2D[i][j]=num;
					num++;
				} 
			}
		}
	}

	//Sets the size and resets the board
	void BoardArray2D::setSize(int rowS,int columnS){
		
		setRow(rowS);
		setColumn(columnS);
		delete [] arr2D;

		arr2D = new int*[getRow()];
		for(int i=0; i<getRow();i++){
			arr2D[i]=new int[getColumn()];
		}
		for(int i=0;i<row;i++){
			for(int j=0; j<column;j++){
				arr2D[i][j]=-1;
			}
		}
		reset();
	}

	//Moves the empty cell to the given direction
	int BoardArray2D::move(char direction){
		int emptCellX, emptCellY;
		int num;

		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				if(arr2D[i][j]==100){
					emptCellX=i;
					emptCellY=j;
				}
			}
		}
		if (direction=='U'){
			
			if(emptCellX==0 || arr2D[emptCellX-1][emptCellY]==0){
				return -1;
			}
			else if(emptCellX!=0 && arr2D[emptCellX-1][emptCellY]!=0){
				num=arr2D[emptCellX-1][emptCellY];
				arr2D[emptCellX-1][emptCellY]=100;
				arr2D[emptCellX][emptCellY]=num;
				setLastMove('U');
				setNumOfMove();
			}
			return 0;  
		}
		else if(direction== 'D'){

			if(emptCellX==row-1 || arr2D[emptCellX+1][emptCellY]==0){
				return -1; 
			}
			else if(emptCellX!=row-1 && arr2D[emptCellX+1][emptCellY]!=0){
				num=arr2D[emptCellX+1][emptCellY];
				arr2D[emptCellX+1][emptCellY]=100;
				arr2D[emptCellX][emptCellY]=num;
				setLastMove('D');
				setNumOfMove();
			} 
			return 0;
		}
		else if(direction=='R'){

			if(emptCellY==column-1 || arr2D[emptCellX][emptCellY+1]==0){
				return -1;
			}

			else if(emptCellY!=column-1 && arr2D[emptCellX][emptCellY+1]!=0){
				num=arr2D[emptCellX][emptCellY+1];
				arr2D[emptCellX][emptCellY+1]=100;
				arr2D[emptCellX][emptCellY]=num;
				setLastMove('R');
				setNumOfMove();
			} 
			return 0;
		}
		else if(direction=='L'){

			if(emptCellY==0 || arr2D[emptCellX][emptCellY-1]==0){ 
				return -1;
			}

			else if(emptCellY!=0 && arr2D[emptCellX][emptCellY-1]!=0){
				num=arr2D[emptCellX][emptCellY-1];
				arr2D[emptCellX][emptCellY-1]=100;
				arr2D[emptCellX][emptCellY]=num;
				setLastMove('L');
				setNumOfMove();
			} 
			return 0;
		}
	}

	//Shuffles the board
	int BoardArray2D::shuffle(){
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
	bool BoardArray2D::isSolved(){
		BoardArray2D controlObje(row,column);
		controlObje.reset();

		int count=0;
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				if(arr2D[i][j]==controlObje.getIndex(i,j)){
					count++;
				}
				else if(arr2D[i][j]!=controlObje.getIndex(i,j)){
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
	bool BoardArray2D::operator ==(const BoardArray2D& rightSide)  {

		int count=0;

		for(auto i=0; i<row;i++){
			for(auto j=0; j<column;j++){
				if(arr2D[i][j]==rightSide.getIndex(i,j)){
					count++;
				}
				else if(arr2D[i][j]!=rightSide.getIndex(i,j)){
					return false;
				}	
			}
		}
		if(count==row*column) 
			return true;	
	}

	/*() operator overloading, returns the number in given indexes if they're valid*/
	int BoardArray2D::operator ()(int index1,int index2){
		
		if((index1 >= 0 && index1 <= getRow()) && (index2>=0 && index2<=getColumn()))
			return arr2D[index1][index2];
		else 
			return -1;
	}

	//Returns the coordinates of empty cell
	void BoardArray2D::getEmptyCellX_Y(int &cellX,int &cellY){
		for(auto i=0; i<row;i++){
			for(auto j=0;j<column;j++){
				if(arr2D[i][j]==100){
					cellX=i;
					cellY=j;
				}
			}
		}
	}
	
}//end of namespace