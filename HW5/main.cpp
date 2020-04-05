/*file main.cpp */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include "abstractBoard.h"
#include "boardArray2D.h"
#include "boardVector.h"
#include "boardArray1D.h"

using namespace EsraNameSpace;

/*Global function definition.Returns true if array contains valid sequence of moves*/
bool isMovesValid(AbstractBoard *array[],int sizeArray);

/*Tests functions to show every funciton works correctly*/
void testFunctions(AbstractBoard &object,ifstream &input,ofstream &output);


int main(){

	std::ifstream input,input2,input3;	
	std::ofstream output;
	std::string filename,filename2;
	int testType;

	BoardArray1D object1d(4,4);
	BoardArray2D object2d(3,3);
	BoardVector objectvect(5,5);

	/*This part for testing for show how derived classes functions work*/
	cout<<"Enter the AbstractBoard type to test as int 1(BoardArray1D), 2(BoardArray2D),3(BoardVector):";
	cin>>testType;
	if(testType==1){
		cout<<"Testing the BoardArray1D object's functions..\n";
		testFunctions(object1d,input,output);
	}
	else if(testType==2){
		cout<<"Testing the BoardArray2D object's functions..\n";
		testFunctions(object2d,input,output);
	}
	else if(testType==3){
		cout<<"Testing the BoardVector object's functions..\n";
		testFunctions(objectvect,input,output);	
	}


	/*This part is for testing the global isMovesValid function
	*I tested the function 4 times to show valid arrays and non-valid arrays work fine
	*Arrays of AbstractBoard pointers created first
	*Objects created and made some moves on them
	*Objects assigned to arrays then called function */

	//Creating arrays of AbstractBoard to test the global function
	AbstractBoard* array[4];
	AbstractBoard* array2[5];
	AbstractBoard* array3[4];
	AbstractBoard* array4[3];

	BoardVector objVec(4,4);
	BoardArray2D obj2D(4,4);
	BoardArray1D obj1D(4,4);
	
	//making moves on objects

	objVec.reset();
	objVec.move('L');
	objVec.move('L');
	obj2D.reset();
	obj2D.move('L');
	obj1D.shuffle();
	//copy constructor used
	BoardArray2D obj2d(obj2D);
	obj2d.move('R');
	//assigning objects to array
	array[0]=&objVec;
	array[1]=&obj2D;
	array[2]=&obj1D;
	array[3]=&obj2d;

	//testing global funciton isMoveValid
	cout<<"***********************************************";
	cout<<"\nTesting isMovesValid function:\n";
	isMovesValid(array,4);

	//making moves and assigning them to array for test again global function isMoveValid
	obj2D.move('L');
	array2[0]=&obj2D;
	BoardArray2D obj1(obj2D);
	obj1.move('U');
	array2[1]=&obj1;
	BoardArray2D obj2(obj1);
	obj2.move('L');
	array2[2]=&obj2;
	BoardArray2D obj3(obj2);
	obj3.move('R');
	array2[3]=&obj3;
	BoardArray2D obj4(obj3);
	obj4.move('D');
	array2[4]=&obj4;
	BoardArray2D obj5(obj4);
	obj5.move('R');
	array2[5]=&obj5;

	//testing global funciton isMoveValid
	cout<<"***********************************************";
	cout<<"\nTesting isMovesValid function second time:\n";
	isMovesValid(array2,6);

	BoardVector vecObje(3,3);
	BoardArray1D onedObje(3,3);
	BoardArray2D twodObje(3,3);
	BoardVector vecobje2(3,3);

	vecObje.shuffle();
	onedObje.shuffle();
	twodObje.shuffle();
	vecobje2.shuffle();

	array3[0]=&vecObje;
	array3[1]=&onedObje;
	array3[2]=&twodObje;
	array3[3]=&vecobje2;

	//testing global funciton isMoveValid
	cout<<"***********************************************";
	cout<<"\nTesting isMovesValid function third time:\n";
	isMovesValid(array3,4);

	obj2D.move('L');
	array4[0]=&obj2D;
	BoardArray2D object1(obj2D);
	object1.move('U');
	array4[1]=&object1;
	BoardArray2D object2(object1);
	object2.move('R');
	array4[2]=&object2;

	//testing global funciton isMoveValid
	cout<<"***********************************************";
	cout<<"\nTesting isMovesValid function fourth time:\n";
	isMovesValid(array4,3);
	
	return 0;
}
/*Function returns true if array contains valid sequence of moves*/
bool isMovesValid(AbstractBoard *array[],int sizeArray){

	for(int i=0;i<sizeArray;i++){
		cout<<"Printing the board configuration at index:"<<i<<endl;
		array[i]->print();
	}
	int cllx=0,clly=0; // variables for holding the empty cell's index
	int cllxNext=0,cllyNext=0;
	auto i=0;

	while(i<(sizeArray-1)){
		
		array[i]->getEmptyCellX_Y(cllx,clly);
		array[i+1]->getEmptyCellX_Y(cllxNext,cllyNext);
		
		//Controlling empty cell's move
		//If ıt goes u,d,r,l it looks other index until end of the array
		//else,it returns false beceuse it means bb makes invalid move
		if((cllxNext==cllx-1 && cllyNext==clly) || (cllxNext==cllx+1 && cllyNext==clly) ||
			(cllxNext==cllx && cllyNext==clly-1) || (cllxNext==cllx && cllyNext==clly+1)){
			i++;
		}
		else{
			cout<<"Non-valid movement at index:"<<i<<" to "<<i+1<<"!"<<endl;
			return false;
		}
	}
	cout<<"Array contains valid sequence of moves!"<<endl;
	return true;	
}
/*Calls derived classes every member function to show how they work*/
void testFunctions(AbstractBoard &object,ifstream &input,ofstream &output){
	int newSize;
	int x,y,result;
	string filename,filename2;
	cout<<"Reseting object:\n";
	object.reset();
	object.print();
	cout<<"Enter new size to set size:";
	cin>>newSize;
	cout<<"Setting size to"<<newSize<<":\n";
	object.setSize(newSize,newSize);
	object.print();
	cout<<"Move U:\n";
	result=object.move('U');
	if(result==-1)
		cout<<"There is no room.\n";
	object.print();
	cout<<"Move R:\n";
	result=object.move('R');
	if(result==-1)
		cout<<"There is no room.\n";
	object.print();
	cout<<"Move D:\n";
	result=object.move('D');
	if(result==-1)
		cout<<"There is no room.\n";
	object.print();
	cout<<"Move L:\n";
	result=object.move('L');
	if(result==-1)
		cout<<"There is no room.\n";
	object.print();
	cout<<"Writing to file current board configuration\n";
	cout<<"Enter filename to write:";
	cin>>filename;
	object.writeToFile(output,filename);
	cout<<"Is solved control:\n";
	object.isSolved();
	cout<<"Operator () control for indexes:\n";
	//bb = 100 as an integer not 0 because in files 0 means wall..
	cout<<"Enter the indexes between "<<newSize<<" to get the value with space:";
	cin>>x>>y;
	cout<<object.operator()(x,y)<<endl;
	cout<<"Read from file control:\n";
	cout<<"Enter file name to read:";
	cin>>filename2;
	cout<<"Board after reading file:\n";
	object.readFromFile(input,filename2);
	object.readAndAssign(input,filename2);
	object.print();

}