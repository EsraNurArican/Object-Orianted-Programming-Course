/*Implementation file for class GTUIteratorConst*/
#include "gtuIteratorConst.h"

namespace ContainerHW6{
	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst() : _p(nullptr)	
	{ /*Indentionally empty*/ }

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(T *new_p) : _p(new_p)
	{ /*Indentionally empty*/ }

	template <class T>
	GTUIteratorConst<T>::GTUIteratorConst(const GTUIteratorConst &rightSide) : _p(rightSide._p)
	{ /*Indentionally empty*/ }

	template <class T>
	T GTUIteratorConst<T>::operator *()const{
		return *_p;
	}

	template <class T>
	T* GTUIteratorConst<T>::operator ->()const{
		return _p;
	}
	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>:: operator ++(){
		_p++;
		return *this;
	}

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator ++(int ignoreMe){
		GTUIteratorConst temp = *this;
		_p++;
		return temp;
	} 

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator --(){
		_p--;
		return *this;
	}

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator =(const GTUIteratorConst& rightSide){
		_p=rightSide._p;
		return *this;
	}

	template <class T>
	GTUIteratorConst<T>& GTUIteratorConst<T>::operator +(int val){
		auto i=0;
		while(i<val){
			_p++;
			i++;
		}
		return *this;
	}

	template <class T>
	bool GTUIteratorConst<T>::operator ==(const GTUIteratorConst &rightSide)const{
		return (_p==rightSide._p);
	}

	template <class T>
	bool GTUIteratorConst<T>::operator !=(const GTUIteratorConst &rightSide)const{
		return (_p!=rightSide._p);
	}


}//end of namespace