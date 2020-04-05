/*FILE gtuContainer.h. 
This is the header file for abstract base class "GtuContainer"*/
#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H

#include <iostream>
#include "gtuIterator.h"
#include "gtuIteratorConst.h"

namespace ContainerHW6{
	//Abstract base class
	template <class T>
	class GTUContainer{
	public:
		
		/*Member functions*/
		virtual bool empty()=0;					//Test whether container is empty
		virtual int size()=0;					//Return container size
		virtual int maxSize()=0;				//Return max size
		virtual void insert(const T &object)=0;	//Insert element	
		virtual void erase(const T &object)=0;	//Erase element
		virtual void clear()=0;					//Clear all content
		virtual GTUIterator<T> begin()=0;		//Return iterator to beginning
		virtual GTUIterator<T> end()=0;			//Return iterator to end
		/*Getters*/
		inline shared_ptr<T> getvaluePtr()const { return valuePtr; }
		inline int getSize()const { return _size; }

	protected:
		shared_ptr<T> valuePtr;
		int _size;

	};
}// end of namespace
#endif