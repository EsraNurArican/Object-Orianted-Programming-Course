/*File boardVector.cpp
 *This is the implementation file for class BoardVector*/

#include "boardVector.h"
namespace EsraNameSpace{
	//No parameter constructor
	BoardVector::BoardVector()
	{
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				boardVec[i].push_back(-1);
			}
		}
		setNumOfBoard();
		setLastMove('S');
	}
	//Constructor takes row and column
	BoardVector::BoardVector(int nrow,int ncolumn): row(nrow),column(ncolumn)
	{
		boardVec.resize(row);
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				boardVec[i].push_back(-1);
			}
		}
		setNumOfBoard();
		setLastMove('S');

	}
	//Constructor takes size
	BoardVector::BoardVector(int size): row(size),column(size)
	{	
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				boardVec[i].push_back(-1);
			}
		}
		setNumOfBoard();
		setLastMove('S');
	}
	//Prints the board by sending it to cout
	void BoardVector::print(){
		for (int m = 0; m <row; m++){
	        for (int k = 0; k < column; k++) {
	          if(boardVec[m][k]!=100)
	            cout << boardVec[m][k] << " ";
	          else if(boardVec[m][k]==100)
	            cout<<"bb ";
	        }
        	cout<<endl;
  		}
  		cout<<endl;
	}

	//Reads file and determines new row and column informations
	void BoardVector::readFromFile(ifstream &input,string filename){
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
		//changing vector's size to readen row-column values
		setRow(i);
		setColumn(j/i);
		boardVec.resize(row);
		for (int i = 0; i < row; ++i)
    		boardVec[i].resize(column);

		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				boardVec[i][j]=-1;			
			}
		}
		input.close();
	}	
	//Reads file and assigns the values from file to board		
	void BoardVector::readAndAssign(ifstream &input,string filename){
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
						boardVec[i][j]=number;
					}
					if(readen=="bb"){
						boardVec[i][j]=100;
					} 
				}
			}
		}
	}		

	//Writes the board configuration to given file	
	void BoardVector::writeToFile(ofstream &output,string &filename){
		output.open(filename.c_str()); 
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
	//Resets board to the solution		
	void BoardVector::reset(){
		int num=1;
		for(int i=0;i<row;i++){
			
			for(int j=0; j<column;j++){
				
				if(i==row-1 && j==column-1 && boardVec[i][j]!=0){

					boardVec[i][j]=100;
				}
				else if(boardVec[i][j]!=0){

					boardVec[i][j]=num;
					num++;
				} 
			}
		}
	}	
	//Sets the size,and resets the board											
	void BoardVector::setSize(int rowS,int columnS){
		cout<<"setsizeda";
		setRow(rowS);
		setColumn(columnS);
		//resizing the vector
		boardVec.resize(rowS);
		for (int i = 0; i < rowS; ++i)
    		boardVec[i].resize(columnS);

		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				boardVec[i][j]=-1;			
			}
		}
		reset();

	}	
	//Moves the empty cell to the given direction			
	int BoardVector::move(char direction){
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
				setLastMove('U');
				setNumOfMove();
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
				setLastMove('D');
				setNumOfMove();
			} 
			return 0;
		}
		else if(direction=='R'){

			if(emptCellY==boardVec[0].size()-1 || boardVec[emptCellX][emptCellY+1]==0){;
				return -1;
			}

			else if(emptCellY!=boardVec[0].size()-1 && boardVec[emptCellX][emptCellY+1]!=0){
				num=boardVec[emptCellX][emptCellY+1];
				boardVec[emptCellX][emptCellY+1]=100;
				boardVec[emptCellX][emptCellY]=num;
				setLastMove('R');
				setNumOfMove();
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
				setLastMove('L');
				setNumOfMove();
			} 
			return 0;
		}
	}	
	//Shuffles the board						
	int BoardVector::shuffle(){
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
		return 0;
	}

	//Returns true if board is solved
	bool BoardVector::isSolved(){
		BoardVector controlObje(row,column);
		controlObje.reset();

		int count=0;
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++){
				if(boardVec[i][j]==controlObje.getIndex(i,j)){
					count++;
				}
				else if(boardVec[i][j]!=controlObje.getIndex(i,j)){
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
	bool BoardVector::operator ==( const BoardVector& rightSide)  {
		
		int count=0;

		for(auto i=0; i<row;i++){
			for(auto j=0; j<column;j++){
				if(boardVec[i][j]==rightSide.getIndex(i,j)){
					count++;
				}
				else if(boardVec[i][j]!=rightSide.getIndex(i,j)){
					return false;
				}	
			}
		}
		if(count==row*column) 
			return true;	
	}
	//operator () overloading returns the value at given indexes
	int BoardVector::operator ()(int index1,int index2){
		if((index1 >= 0 && index1 <= getRow()) && (index2>=0 && index2<=getColumn()))
			return boardVec[index1][index2];
		else 
			return -1;
	}

	//Returns the coordinates of empty cell
	void BoardVector::getEmptyCellX_Y(int &cellX,int &cellY){
		for(auto i=0; i<row;i++){
			for(auto j=0;j<column;j++){
				if(boardVec[i][j]==100){
					cellX=i;
					cellY=j;
				}
			}
		}
	}
}//end of namespace