/*Implementation file for class GtuIterator*/
#include "gtuIterator.h"

namespace ContainerHW6{
	template <class T>
	GTUIterator<T>::GTUIterator() : _p(nullptr)	
	{ /*Indentionally empty*/ }

	template <class T>
	GTUIterator<T>::GTUIterator(T *new_p) : _p(new_p)
	{ /*Indentionally empty*/ }

	template <class T>
	GTUIterator<T>::GTUIterator(const GTUIterator &rightSide) : _p(rightSide._p)
	{ /*Indentionally empty*/ }

	template <class T>
	T GTUIterator<T>::operator *(){
		return *_p;
	}

	template <class T>
	T* GTUIterator<T>::operator ->(){
		return _p;
	}
	template <class T>
	GTUIterator<T>& GTUIterator<T>:: operator ++(){
		_p++;
		return *this;
	}

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator ++(int ignoreMe){
		GTUIterator temp = *this;
		_p++;
		return temp;
	} 

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator --(){
		_p--;
		return *this;
	}

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator =(const GTUIterator& rightSide){
		_p=rightSide._p;
		return *this;
	}

	template <class T>
	GTUIterator<T>& GTUIterator<T>::operator +(int val){
		auto i=0;
		while(i<val){
			_p++;
			i++;
		}
		return *this;
	}

	template <class T>
	bool GTUIterator<T>::operator ==(const GTUIterator &rightSide){
		return (_p==rightSide._p);
	}

	template <class T>
	bool GTUIterator<T>::operator !=(const GTUIterator &rightSide){
		return (_p!=rightSide._p);
	}


}//end of namespace