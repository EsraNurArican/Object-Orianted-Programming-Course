/*Main file for CSE241-HW4*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "N_puzzle.h"

int main(int argc , char *argv[]){

	ifstream input,input2;	
	ofstream output;
	string filename,filenameO,loadToFile;
	int m_boardsize;
	int controlRoom;
	int controlSolution;
	decltype(m_boardsize) m_row;
	decltype(m_boardsize) m_column;
	char action;
	auto numberOfMoves=0;
	decltype(numberOfMoves) commandVCount=0;
	//N_Puzzle objeMain(9);
	
	if(argv[1]!=NULL){

		filename=argv[1];
		//N_Puzzle objeMain(input,filename); //Uses constructor with file name
		N_Puzzle objeMain(9);
		objeMain.readFromFile(input,filename);
		objeMain.readAndAssign(input,filename);
		cout<<"Your initial board is:\n";
		objeMain.print();

		objeMain.print();
		/*Taking actions until user enters 'Q'*/
	do{	

		/*If problem solved,exits game*/
		/*if(objeMain.getBoardObje().isSolved()==1){
	    	objeMain.printReport(numberOfMoves);
	    	break;
	    }*/

	    cout<<"Your move:";
	    cin>>action;
	    
	    /*Calling necessary functions according to action*/
	    switch(action)
	    {
	    	case 'V':
	    		commandVCount=objeMain.solvePuzzle();
	    		cout<<"Number of moves for this action:"<<commandVCount<<endl;
	    		numberOfMoves=numberOfMoves+commandVCount;
	    		break;
    		case 'T':
    			objeMain.printReport(numberOfMoves);
    			break;
			case 'E':
				cout<<"Please enter a filename to write board configuration:";
				cin>>loadToFile;
				objeMain.writeToFile(output,loadToFile);
				objeMain.print();
				break;
			case 'O':
				cout<<"Please enter a filename to load board configuration from:";
				cin>>filenameO;
				objeMain.readFromFile(input2,filenameO);
				objeMain.readAndAssign(input2,filenameO);
				objeMain.print();
				break;
			case 'L':
				controlRoom=objeMain.move('L');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else {
					numberOfMoves++;
					objeMain.print();
					break;
				}
			case 'R':
				controlRoom=objeMain.move('R');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else{
					numberOfMoves++;
					objeMain.print();
					break;
				}
			case 'U':
				controlRoom=objeMain.move('U');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else{
					numberOfMoves++;
					objeMain.print();
					break;
				}
				
			case 'D':
				controlRoom=objeMain.move('D');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else {
					objeMain.print();
					numberOfMoves++;
					break;
				}
				
			
			case 'S':
				cout<<"Final solution of the board is:\n";
				objeMain.reset();
				objeMain.print();
				cout<<"Shuffled version of the board is:\n";
				objeMain.shuffle(6);
				objeMain.print();
				break;
			case 'Q':
				return -1;
			default:
				cout<<"You entered invalid action.\n";
				break;
	    }

	}
	while(action !='Q');
	}
	else if(argv[1]==NULL){
		
		/*Getting user input until the valid numbers*/
		do{
			cout<<"Please enter the problem size:";
			cin>>m_boardsize;
			if(m_boardsize<3 || m_boardsize>9)
				cout<<"You entered invalid value!\n";
		}while(m_boardsize<3 || m_boardsize>9);
		
		m_row=m_boardsize;
		m_column=m_boardsize;
	    N_Puzzle objeMain(m_boardsize); //Uses constructor with boardsize parameter.
	    objeMain.shuffle(m_boardsize);
		cout<<"Your initial random board is:\n";
		objeMain.print();
		/*Taking actions until user enters 'Q'*/
	do{	

		
		/*If problem solved,exits game*/
		/*if(objeMain.getBoardObje(0).isSolved()==1){
	    	objeMain.printReport(numberOfMoves);
	    	break;
	    }*/

	    cout<<"Your move:";
	    cin>>action;
	    

	    /*Calling necessary functions according to action*/
	    switch(action)
	    {
	    	case 'V':
	    		commandVCount=objeMain.solvePuzzle();
	    		cout<<"Number of moves for this action:"<<commandVCount<<endl;
	    		numberOfMoves=numberOfMoves+commandVCount;
	    		break;
    		case 'T':
    			objeMain.printReport(numberOfMoves);
    			break;
			case 'E':
				cout<<"Please enter a filename to write board configuration:";
				cin>>loadToFile;
				objeMain.writeToFile(output,loadToFile);
				objeMain.print();
				break;
			case 'O':
				cout<<"Please enter a filename to load board configuration from:";
				cin>>filenameO;
				objeMain.readFromFile(input2,filenameO);
				objeMain.readAndAssign(input2,filenameO);
				objeMain.print();
				break;
			case 'L':
				controlRoom=objeMain.move('L');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else {
					numberOfMoves++;
					objeMain.print();
					break;
				}
			case 'R':
				controlRoom=objeMain.move('R');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else{
					numberOfMoves++;
					objeMain.print();
					break;
				}
			case 'U':
				controlRoom=objeMain.move('U');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else{
					numberOfMoves++;
					objeMain.print();
					break;
				}
				
			case 'D':
				controlRoom=objeMain.move('D');
				if(controlRoom==-1){
					cout<<"There is no room!\n";
					break;
				}
				else {
					objeMain.print();
					numberOfMoves++;
					break;
				}
				
			
			case 'S':
				cout<<"Final solution of the board is:\n";
				objeMain.reset();
				objeMain.print();
				cout<<"Shuffled version of the board is:\n";
				objeMain.shuffle(m_boardsize);
				objeMain.print();
				break;
			case 'Q':
				return -1;
			default:
				cout<<"You entered invalid action.\n";
				break;
	    }

	}
	while(action !='Q');
	}

	
	
	return 0;
}
