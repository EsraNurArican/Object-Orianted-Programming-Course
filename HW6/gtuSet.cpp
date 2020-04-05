/*File GTUSet.cpp . This is the implementation file for class GTUSet*/
#include "gtuSet.h"

namespace ContainerHW6{
	/*no parameter consturctor*/
	template<class T>
	GTUSet<T>::GTUSet() :setSize(0), setPtr(nullptr)
	{ /*Indentionally empty*/ }

	/*constructor that takes size*/
	template<class T>
	GTUSet<T>::GTUSet(int newsetSize) : setSize(newsetSize){
		T* temp = new T (newsetSize);
		shared_ptr<T> tempptr (temp);

		setPtr = tempptr;
	}
	/*copy constructor*/
	template<class T>
	GTUSet<T>::GTUSet(const GTUSet& object){
		setSize = object.getSize();

		T* temp = new T (setSize);
		shared_ptr<T> tempptr (temp);

		setPtr = tempptr;

		for(int i=0 ; i < setSize ; ++i)
			setPtr.get()[i] = object.setPtr.get()[i];
	}
	/*Assigment operator*/
	template<class T>
	GTUSet<T>& GTUSet<T>::operator=(const GTUSet& rightSide){
		if(this == &rightSide)
			return *this;

		setSize= rightSide.getsetSize();
		T* temp = new T (setSize);
		shared_ptr<T> tempptr (temp);

		setPtr = tempptr;

		for(int i=0 ; i < setSize ; ++i)
			setPtr.get()[i] = rightSide.setPtr.get()[i];

		return *this;
	}
	/*Virtual destructor*/
	template<class T>	
	GTUSet<T>:: ~GTUSet(){
		setPtr = nullptr;
		setSize = 0;
	}	

	/*Member function implementations*/	
	//Tests whether container is empty
	template<class T>
	bool GTUSet<T>::empty(){
		return (setSize==0);
	}

	//Returns container size
	template<class T>
	int GTUSet<T>::size(){
		return setSize;
	}	
	//Returns maximum size
	template<class T>
	int GTUSet<T>::maxSize(){
		return 10000;
	}

	//Inserts element,throws exception if there is a problem	
	template<class T>
	void GTUSet<T>::insert(const T &element){

		//if element has already in set throws exception
		for(int i = 0;i< this->setSize;++i)
			if(this->setPtr.get()[i] == element)
				throw(invalid_argument("This element is already in the set!!!"));
		//Getting backup of data on variable tempData
		shared_ptr<T> tempData = this->setPtr;
		shared_ptr <T> temp(new T[++this->setSize],default_delete<T[]>());
		this->setPtr = temp;
		//Copying elements from the temp to the setPtr
	    for (int i = 0; i < this->setSize - 1; ++i)
	        	this->setPtr.get()[i] = tempData.get()[i];  

	    //Inserting element to the end of setPtr;
	    this->setPtr.get()[this->setSize-1] = element;
	}	

	//Erase element
	template<class T>
	void GTUSet<T>::erase(const T &element){
		int isIn=0;

		GTUIterator<T> p;
		//Looking the set to find if value is in there
		for(p = begin();p != end();++p)//Searchs the element in data
			if(*p == element)
				isIn=1;
				
		//If element is in the set,deletes it
		if(isIn==1){

			shared_ptr<T> temp(new T[this->setSize],default_delete<T[]>());//Allocates memory for copies

			auto j=0;
			//Copy elements in the set to a temporary set
			for( auto i= 0; i< this->setSize; ++i){
				if(this->setPtr.get()[i] != element){
					temp.get()[j] = this->setPtr.get()[i];
					++j;
				}
			}
						
			this->setPtr= temp;
			//After deleting,decrementing size 
			--this->setSize;
		
		}
	}	

	//Clear all content	
	template<class T>
	void GTUSet<T>::clear(){
		//To clear content setPtr and size equalized to 0
		this->setPtr=nullptr;
		this->setSize=0;
	}	

	//Return iterator to beginning
	template<class T>
	 GTUIterator<T> GTUSet<T>::begin(){
		return((this->setPtr).get());
	}	

	//Return iterator to end
	template<class T>
	 GTUIterator<T> GTUSet<T>::end(){
		//To find end of the container adding first adress to size
		return((this->setPtr).get()+setSize);
	}	

}//end of namespace