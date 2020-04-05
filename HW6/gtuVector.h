/*File gtuVector.h. 
This is the header file for abstract base class "GTUVector"*/
#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include <iostream>
#include "gtuContainer.h"

namespace ContainerHW6{
	//Derived class GTUVector from GTUContainer class
	template <class T>
	class GTUVector : public GTUContainer<T> {
	public:
		
		//Constructors
		GTUVector();
		GTUVector(int new_size);
		//Big three
		GTUVector(const GTUVector& object);					//Copy consturctor
		GTUVector& operator=(const GTUVector& rightSide);	//Assigment operator
		virtual ~GTUVector();								//Virtual destructor
		
		//Member functions
		virtual bool empty();					//Test whether container is empty
		virtual int size();						//Return container size
		virtual int maxSize();					//Return max size
		virtual void insert(const T &element);	//Insert element	
		virtual void erase(const T &element);	//Erase element
		virtual void clear();					//Clear all content
		virtual GTUIterator<T> begin();			//Return iterator to beginning
		virtual GTUIterator<T> end();			//Return iterator to end
		const T &operator[]( const int index);	//overloaded []operator.Returns the value given index
		//Getters
		inline shared_ptr<T> getvaluePtr()const { return vectorPtr; }
		inline int getSize()const { return vecSize; }

	protected:
		shared_ptr<T> vectorPtr;
		int vecSize;
	};
}// end of namespace
#endif