/*File GtuSet.h. 
This is the header file for abstract base class "GTUSet"*/
#ifndef GTUSET_H
#define GTUSET_H

#include <iostream>
#include "gtuContainer.h"

namespace ContainerHW6{
	//Derived class GTUSet from GTUContainer class
	template <class T>
	class GTUSet : public GTUContainer<T> {
	public:
		
		//Constructors
		GTUSet();
		GTUSet(int newsetSize);
		//Big three
		GTUSet(const GTUSet& object);					//Copy consturctor
		GTUSet& operator=(const GTUSet& rightSide);		//Assigment operator
		virtual ~GTUSet();								//Virtual destructor
		
		//Member functions
		virtual bool empty();					//Test whether container is empty
		virtual int size();						//Return container size
		virtual int maxSize();					//Return max size
		virtual void insert(const T &element);	//Insert element	
		virtual void erase(const T &element);	//Erase element
		virtual void clear();					//Clear all content
		virtual GTUIterator<T> begin();			//Return iterator to beginning
		virtual GTUIterator<T> end();			//Return iterator to end
		//Getters
		inline shared_ptr<T> getsetPtr()const { return setPtr; }
		inline int getSize()const { return setSize; }

	protected:
		shared_ptr<T> setPtr;
		int setSize;
	};
}// end of namespace
#endif