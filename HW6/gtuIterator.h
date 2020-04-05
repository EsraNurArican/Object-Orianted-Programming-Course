/*File GTUIterator.h
 Header file for the class GTUIterator*/
#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include <iostream>
#include <memory>
using namespace std;
namespace ContainerHW6{

	template <class T>
	class GTUIterator{

	public:
		GTUIterator();									//no parameter constructor
		GTUIterator(T *new_p);							//constructor that takes a pointer
		GTUIterator(const GTUIterator &rightSide);		//copy constructor

		//operator overloadings
		T operator * () ;
		T * operator ->() ;							
		GTUIterator & operator ++(); 				//prefix 
		GTUIterator & operator ++(int ignoreMe);	//postfix 
		GTUIterator & operator --();				
		GTUIterator & operator =(const GTUIterator &rightSide);
		GTUIterator & operator +(int val);							
		bool operator ==(const GTUIterator &rightSide) ;
		bool operator !=(const GTUIterator &rightSide) ;
		
	private:
		//shared_ptr<T> _p;
		T * _p;

	};

}//end of namespace
#endif