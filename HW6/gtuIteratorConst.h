/*File gtuIteratorConst.h
 Header file for the class GTUIteratorConst*/
#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H
#include <iostream>
#include <memory>

using namespace std;

namespace ContainerHW6{

	template <class T>
	class GTUIteratorConst{

	public:
		GTUIteratorConst();									//no parameter constructor
		GTUIteratorConst(T *new_p);							//constructor that takes a pointer
		GTUIteratorConst(const GTUIteratorConst &rightSide);		//copy constructor

		//operator overloadings
		T operator * ()const ;
		T * operator ->()const ;							
		GTUIteratorConst & operator ++(); 				//prefix 
		GTUIteratorConst & operator ++(int ignoreMe);	//postfix 
		GTUIteratorConst & operator --();				
		GTUIteratorConst & operator =(const GTUIteratorConst &rightSide);
		GTUIteratorConst & operator +(int val);							
		bool operator ==(const GTUIteratorConst &rightSide)const ;
		bool operator !=(const GTUIteratorConst &rightSide)const ;
		
	private:
		//shared_ptr<T> _p;
		T * _p;

	};

}//end of namespace
#endif