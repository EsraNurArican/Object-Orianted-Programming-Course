#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "source.h"

int main(int argc , char *argv[]){

	ifstream input,input2;	
	ofstream output;
	string filename,filename2,load;
	auto commandVCount=0;
	int arrBoard[maxSize][maxSize];
	int checkBoard[maxSize][maxSize];
	auto counter = 0;
	int check= 0;
	int control=0;
	int boardsize= 0;
	char action;
	// puzzle board's row and column numbers will determine while reading file
	decltype(boardsize)row=0;
	decltype(boardsize)column=0; 

	/*If user enters a file name on command line*/	
	if(argv[1]!=NULL){
		//file name is equal to command line argument
		filename=argv[1];
		//reading file and determining gameboard's row and column
		readFromFile(input,filename,row,column);
		//assigning the values from the file to array according to row and column
		readAndAssign(input2,filename,arrBoard,row,column);
		//equalizing arrBoard and check board to place 00's correctly
		equalizeArrays(arrBoard,checkBoard,row,column);
		//sorting checkBoard to control final state
		sortBoard(checkBoard,row,column);
		//shuffling the game board first to receive solvable puzzle
		shuffle(arrBoard,row,column);
		printBoard(arrBoard,row,column);
	
	}
	/*If program starts not entering file name*/
	else if(argv[1]== NULL){
		/*Taking board size from user*/
		do{
			cout<<"Please enter the problem size:";
			cin>>boardsize;
			if(boardsize<3 || boardsize>9)
				cout<<"You entered invalid value!\n";
		}while(boardsize<3 || boardsize>9);
		
		row=boardsize;
		column=boardsize;
		/*First assigning values to arrBoard,to avoid mistakes for further steps because of empty indexes*/
  		for(int i=0;i<maxSize;i++){ 
    		for(int j=0;j<maxSize;j++){
      			arrBoard[i][j]=-1;
    		}
  		}
		initBoard(boardsize,arrBoard);
		equalizeArrays(arrBoard,checkBoard,row,column);
		sortBoard(checkBoard,row,column);	
	}
	
  	/*Taking input from user until receive the solution or quit*/
 	do{

	    cout<<"Your move:";
	    cin>>action;

	    if(action=='U' || action=='u'){
	    	check=up(arrBoard,row,column);
	   
	    }
	    if(action=='D' || action=='d'){
	    	check=down(arrBoard,row,column);
	    
	    }
	    if(action=='L' || action=='l'){
	    	check=left(arrBoard,row,column);
	      
	    }
	    if(action=='R' || action=='r'){
	    	check=right(arrBoard,row,column);
	      
	    }
	    if(action=='I' || action == 'i'){
	      check=intelligent(arrBoard,row,column);
	      
	    }
	    if(action=='S' || action== 's'){
	    	/*First sorting the board for the final solution*/
  			sortBoard(arrBoard,row,column);
  			cout<<"Final solution of the board:\n";
 		 	printBoard(arrBoard,row,column);
	    	check=shuffle(arrBoard,row,column);
	    	cout<<"Shuffled version of the board:\n";
	      
	    }
	    if(action=='Q' || action=='q'){
	    	//cout<<"Total number of moves:"<<counter<<endl;
	    	return -1; 
	    }
	    if(action=='E' || action=='e'){
	    	cout<<"Please enter the file name to write:";
			cin>>filename2;
			printOnFile(output,filename2,arrBoard,row,column);
	    }
	    if(action == 'Y' || action== 'y'){
	    	cout<<"Please enter a filename to load board configuration:";
	    	cin>>load;
	    	readFromFile(input,load,row,column);
	    	readAndAssign(input,load,arrBoard,row,column);
	    	printBoard(arrBoard,row,column);

	    }
	    if(action == 'V' || action =='v'){
	    	int i=0;
			int randomMove;
			int lastMove;     // if last move is U dont make D after that ,or if it is R dont make L just after that.
			int control=0;
	    	sortBoard(arrBoard,row,column);
	    	/*Shuffling board to receive solution easily*/
	    	shuffle(arrBoard,row,column);
			while(control!=row*column ){

			intelligent(arrBoard,row,column);
			printBoard(arrBoard,row,column);
			
				while( i<5){

					randomMove = (rand() % 4)+1 ;
					if(randomMove==1 && lastMove!=2){
					  control=up(arrBoard,row,column);
					  if(control==0)
	        			cout<<"Intelligent move chooses U:"<<endl;
	        			printBoard(arrBoard,row,column);
					} 
					if(randomMove==2){
					  control=down(arrBoard,row,column);
					  if(control==0)
	        			cout<<"Intelligent move chooses D:"<<endl;
	        			printBoard(arrBoard,row,column);
					} 
					if(randomMove==3 && lastMove!=4){
					  control=left(arrBoard,row,column);
					  if(control==0)
	        			cout<<"Intelligent move chooses L:"<<endl;
	        			printBoard(arrBoard,row,column);
					} 
					if(randomMove==4){
					  control=right(arrBoard,row,column);
					  if(control==0)
	        			cout<<"Intelligent move chooses R:"<<endl;
	        			printBoard(arrBoard,row,column);
					} 
					lastMove=randomMove;
					/*Control is the return value for U,D,R,L functions
					 If control is -1 this means there is no room for that choice
					 If control is 0 this means cell is moved and size*size number increases*/
					if(control==0)
					  i++;
				}
    		
    		control=checkIfItsFinal(arrBoard,checkBoard,row,column);
    		commandVCount++;
	    	}
	    	cout<<"Number of moves for this action:"<<commandVCount<<endl;
	    }
	    
	    if(action=='T' || action=='t'){
	    
	    	cout<<"Total number of moves:"<<(counter+commandVCount-1)<<endl;	
	    	sortBoard(checkBoard,row,column);
	    	//Controlling the board whether is it on final position or not
	    	control=checkIfItsFinal(arrBoard,checkBoard,row,column);
	    	if(control==row*column){
	    		cout<<"Problem solved!"<<endl;	
	    	}
	    }

	    if(check==0 && (action!='q' && action!='Q') && (action!='T' && action !='t')){
	    	printBoard(arrBoard,row,column);
	    	counter++;
	    }
	    else if(check==-1 && (action=='L' || action=='l' || action=='r' || action=='R' ||
	    		action=='D' || action=='d' || action=='u' || action=='U'))
	    	cout<<"There is no room!\n";
	   
  	}while(action!='Q');

	return 0;
}

