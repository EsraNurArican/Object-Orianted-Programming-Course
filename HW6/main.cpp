/*MAIN FILE FOR HW6.
 *INCLUDES TEST FUNCTIONS*/
#include <iostream>
#include "gtuIterator.h"
#include "gtuIterator.cpp"
#include "gtuContainer.h"
#include "gtuSet.cpp"
#include "gtuVector.cpp"

using namespace ContainerHW6;

/*Global functions*/
//Function find
template<class GTUIterator, class T>
GTUIterator find (GTUIterator first, GTUIterator last,const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
   		++first; 	
  }
  return last;
}

//Function find_if
template<class GTUIterator, class UnaryPredicate>
GTUIterator find_if (GTUIterator first, GTUIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (pred(*first)) return first;
    	++first;
  }
  return last;
}

//Function for_each
template<class GTUIterator, class Function>
Function for_each(GTUIterator first, GTUIterator last, Function func)
{
  while (first!=last) {
    func (*first);
    ++first;
  }
  return func;     
}

//Function prints number by multiplying 2 the parameter
//Written to send parameter to function for_each
//So, after testing for_each function,it will print the 
//elements in the container by multiplied 2.
void  function(int num){
	cout<<" "<<num*2;
}

//Function isPrime.Written to send parameter as function find_if
//When find_if called, it will return first prime element in the container
bool isPrime(int num){
    bool result=true;
    for(int i=2; i <= num/2; i++) {
       if(num % i == 0) {
          result = false;
          break;
       }
    }
    return result;
}

//Print function to see elements in the container.
template <class T>
void printContainer(GTUContainer<T> &container, GTUIterator<T> &iterator){//Prints the set with iterator

	for(iterator = container.begin(); iterator != container.end(); ++iterator)
		cout<<*iterator<<' ';
	cout<<endl;
}

int main(){

	//Testing the set class,insert,erase,size,clear and empty tested.
	//Also begind and end tested in printContainer function which is uses them.
	cout<<"\n******TESTING SET WITH TYPE CHAR*****\n";
	GTUSet<char> charSet;
	GTUIterator<char> charPtr;

	charSet.insert('e');
	charSet.insert('c');
	charSet.insert('a');
	charSet.insert('f');
	charSet.insert('d');
	charSet.insert('z');
	charSet.insert('m');

	cout<<"İnserting elements..\n";
	printContainer(charSet,charPtr);

	cout<<"Size of the set: ";
	cout<<charSet.size()<<endl;

	cout<<"Erasing elements..\n";
	charSet.erase('a');
	cout<<"After erasing 'a':\n";
	printContainer(charSet,charPtr);

	charSet.erase('f');
	charSet.erase('z');
	cout<<"After erasing 'f' and 'z':\n";
	printContainer(charSet,charPtr);

	cout<<"Size of the set: ";
	cout<<charSet.size()<<endl;

	cout<<"Clearing the set..\n";
	charSet.clear();
	cout<<"After clearing the set,set size is:"<<charSet.size()<<endl;
	if(charSet.empty())
		cout<<"Set is empty.\n";
	printContainer(charSet,charPtr);

	cout<<"\n******TESTING SET WITH TYPE INT*****\n";
	GTUSet<int> intSet;
	GTUIterator<int> intPtr;

	intSet.insert(1);
	intSet.insert(2);
	intSet.insert(3);
	intSet.insert(4);
	intSet.insert(5);
	intSet.insert(6);
	intSet.insert(7);
	intSet.insert(8);
	intSet.insert(9);
	intSet.insert(10);

	cout<<"İnserting elements..\n";
	printContainer(intSet,intPtr);

	cout<<"Size of the set: ";
	cout<<intSet.size()<<endl;

	cout<<"Erasing elements..\n";
	intSet.erase(3);
	cout<<"After erasing 3:\n";
	printContainer(intSet,intPtr);

	intSet.erase(6);
	intSet.erase(8);
	cout<<"After erasing 6 and 8:\n";
	printContainer(intSet,intPtr);

	cout<<"Size of the set: ";
	cout<<intSet.size()<<endl;

	cout<<"Clearing the set..\n";
	intSet.clear();
	cout<<"After clearing the set,set size is:"<<intSet.size()<<endl;
	if(intSet.empty())
		cout<<"Set is empty.\n";

	//Testing the vector class,insert,erase,size,clear and empty tested.
	//Also begind and end tested in printContainer function which is uses them.
	cout<<"\n******TESTING VECTOR WITH TYPE CHAR*****\n";
	GTUVector<char> charVec;
	GTUIterator<char> charVecPtr;

	charVec.insert('A');
	charVec.insert('B');
	charVec.insert('C');
	charVec.insert('D');
	charVec.insert('E');
	charVec.insert('F');
	charVec.insert('G');
	charVec.insert('B');
	charVec.insert('E');
	charVec.insert('C');

	cout<<"İnserting elements..\n";
	printContainer(charVec,charVecPtr);

	cout<<"Size of the vector: ";
	cout<<charVec.size()<<endl;

	cout<<"Erasing elements..\n";
	charVec.erase('A');
	cout<<"After erasing 'A':\n";
	printContainer(charVec,charVecPtr);

	charVec.erase('D');
	charVec.erase('G');
	charVec.erase('F');
	cout<<"After erasing 'D', 'G' and 'F':\n";
	printContainer(charVec,charVecPtr);

	cout<<"Size of the vector: ";
	cout<<charVec.size()<<endl;

	cout<<"Clearing the vector..\n";
	charVec.clear();
	cout<<"After clearing the vector,vector size is:"<<charVec.size()<<endl;
	if(charVec.empty())
		cout<<"Vector is empty.\n";
	printContainer(charVec,charVecPtr);

	cout<<"\n******TESTING VECTOR WITH TYPE INT*****\n";
	GTUVector<int> intVec;
	GTUIterator<int> intVecPtr;

	intVec.insert(10);
	intVec.insert(20);
	intVec.insert(30);
	intVec.insert(40);
	intVec.insert(50);
	intVec.insert(60);
	intVec.insert(70);
	intVec.insert(80);
	intVec.insert(90);
	intVec.insert(100);

	cout<<"İnserting elements..\n";
	printContainer(intVec,intVecPtr);

	cout<<"Size of the vector: ";
	cout<<intVec.size()<<endl;

	cout<<"Erasing elements..\n";
	intVec.erase(30);
	cout<<"After erasing 30:\n";
	printContainer(intVec,intVecPtr);

	intVec.erase(40);
	intVec.erase(50);
	cout<<"After erasing 40 and 50:\n";
	printContainer(intVec,intVecPtr);

	cout<<"Size of the vector: ";
	cout<<intVec.size()<<endl;

	cout<<"Clearing the vector..\n";
	intVec.clear();
	cout<<"After clearing the vector,vector size is:"<<intVec.size()<<endl;
	if(intVec.empty())
		cout<<"Vector is empty.\n";

	
	intVec.insert(10);
	intVec.insert(20);
	intVec.insert(13);
	intVec.insert(17);
	intVec.insert(15);

	//Testing global functions find,find_if,for_each for containers set and vector

	cout<<"\n**************GLOBAL FUNCTİONS TEST ON CONTAINER TYPE VECTOR*************\n\n";

	cout<<"----------Printing the container vector first---------\n";
	printContainer(intVec,intVecPtr);
	cout << "----------For_each function test----------\n\n"
		<<"Print every element in container by multiply 2.\n";
	for_each (intVec.begin(), intVec.end(), function);
	cout << '\n';

	GTUIterator<int> ite;
	cout<< "\n----------Find_if function test----------\n\n"
		<<"Finds the first prime number in container.\n";
	ite = find_if (intVec.begin(), intVec.end(), isPrime);
	cout << "The first prime number is " << *ite << '\n';

	cout<<"\n----------Find function test----------\n\n"
		<<"Looking for find number 13 in container..\n";
	GTUIterator<int> iter;
	iter=find(intVec.begin(),intVec.end(),13);
	if (iter != (intVec.end()))
	cout << "Element found in vector container: " << *iter << '\n';
	else
	cout << "Element not found in vector container\n";

	cout<<"\n----------Find function test----------\n\n"
		<<"Looking for find number 22 in container..\n";
	iter=find(intVec.begin(),intVec.end(),22);
	if (iter != (intVec.end()))
	cout << "Element found in vector container: " << *iter << '\n';
	else
	cout << "Element not found in vector container\n";

	intSet.insert(6);
	intSet.insert(8);
	intSet.insert(7);
	intSet.insert(5);
	intSet.insert(3);
	intSet.insert(2);
	intSet.insert(4);

	cout<<"\n**************GLOBAL FUNCTİONS TEST ON CONTAINER TYPE SET*************\n\n";

	cout<<"----------Printing the container set first---------\n";
	printContainer(intSet,intPtr);
	cout << "----------For_each function test----------\n\n"
		<<"Print every element in container by multiply 2.\n";
	for_each (intSet.begin(), intSet.end(), function);
	cout << '\n';

	GTUIterator<int> it2;
	cout<< "\n----------Find_if function test----------\n\n"
		<<"Finds the first prime number in container.\n";
	it2 = find_if (intSet.begin(), intSet.end(), isPrime);
	cout << "The first prime number is " << *it2 << '\n';

	cout<<"\n----------Find function test----------\n\n"
		<<"Looking for find number 6 in container..\n";
	GTUIterator<int> itr;
	itr=find(intSet.begin(),intSet.end(),6);
	if (itr!= (intSet.end()))
	cout << "Element found in set container: " << *itr << '\n';
	else
	cout << "Element not found in set container\n";

	cout<<"\n----------Find function test----------\n\n"
		<<"Looking for find number 9 in container..\n";
	itr=find(intSet.begin(),intSet.end(),9);
	if (itr != (intSet.end()))
	cout << "Element found in vector container: " << *itr << '\n';
	else
	cout << "Element not found in vector container\n";


	return 0;
}


