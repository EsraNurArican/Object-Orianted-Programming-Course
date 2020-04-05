/*File GTUVector.cpp . This is the implementation file for class GTUVector*/
#include "gtuVector.h"
namespace ContainerHW6{
	/*no parameter consturctor*/
	template<class T>
	GTUVector<T>::GTUVector() :vecSize(0), vectorPtr(nullptr)
	{ /*Indentionally empty*/ }

	/*constructor that takes size*/
	template<class T>
	GTUVector<T>::GTUVector(int newvecSize) : vecSize(newvecSize){
		T* temp = new T (newvecSize);
		shared_ptr<T> tempptr (temp);

		vectorPtr = tempptr;
	}
	/*copy constructor*/
	template<class T>
	GTUVector<T>::GTUVector(const GTUVector& object){
		vecSize = object.getSize();

		T* temp = new T (vecSize);
		shared_ptr<T> tempptr (temp);

		vectorPtr = tempptr;

		for(int i=0 ; i < vecSize ; ++i)
			vectorPtr.get()[i] = object.vectorPtr.get()[i];
	}
	/*Assigment operator*/
	template<class T>
	GTUVector<T>& GTUVector<T>::operator=(const GTUVector& rightSide){
		if(this == &rightSide)
			return *this;

		vecSize= rightSide.getvecSize();
		T* temp = new T (vecSize);
		shared_ptr<T> tempptr (temp);

		vectorPtr = tempptr;

		for(int i=0 ; i < vecSize ; ++i)
			vectorPtr.get()[i] = rightSide.vectorPtr.get()[i];

		return *this;
	}
	/*Virtual destructor*/
	template<class T>	
	GTUVector<T>:: ~GTUVector(){
		vectorPtr = nullptr;
		vecSize = 0;
	}	

	/*Member function implementations*/	
	//Tests whether container is empty
	template<class T>
	bool GTUVector<T>::empty(){
		return (vecSize==0);
	}

	//Returns container size
	template<class T>
	int GTUVector<T>::size(){
		return vecSize;
	}	
	//Returns maximum size
	template<class T>
	int GTUVector<T>::maxSize(){
		return 10000;
	}

	//Inserts element,throws exception if there is a problem	
	template<class T>
	void GTUVector<T>::insert(const T &element){

		//Getting backup of data on variable tempData
		shared_ptr<T> tempData = this->vectorPtr;
		shared_ptr <T> temp(new T[++this->vecSize],default_delete<T[]>());
		this->vectorPtr = temp;
		//Copying elements from the temp to the vectorPtr
	    for (int i = 0; i < this->vecSize - 1; ++i)
	        	this->vectorPtr.get()[i] = tempData.get()[i];  

	    //Inserting element to the end of vectorPtr;
	    this->vectorPtr.get()[this->vecSize-1] = element;
	}	

	//Erase element
	template<class T>
	void GTUVector<T>::erase(const T &element){
		int isIn=0;

		GTUIterator<T> p;
		//Looking the set to find if value is in there
		for(p = begin();p != end();++p)
			if(*p == element)
				isIn=1;
				
		//If element is in the set,deletes it
		if(isIn==1){

			shared_ptr<T> temp(new T[this->vecSize],default_delete<T[]>());

			auto j=0;
			//Copying elements to a temporary set
			for( auto i= 0; i< this->vecSize; ++i){
				if(this->vectorPtr.get()[i] != element){
					temp.get()[j] = this->vectorPtr.get()[i];
					++j;
				}
			}
						
			this->vectorPtr= temp;
			//After deleting,decrementing size 
			--this->vecSize;
		
		}
	}	

	//Clear all content	
	template<class T>
	void GTUVector<T>::clear(){
		//To clear content vectorPtr and size equalized to 0
		this->vectorPtr=nullptr;
		this->vecSize=0;
	}	

	//Return iterator to beginning
	template<class T>
	 GTUIterator<T> GTUVector<T>::begin(){
		return((this->vectorPtr).get());
	}	

	//Return iterator to end
	template<class T>
	 GTUIterator<T> GTUVector<T>::end(){
		//To find end of the container adding first adress to size
		return((this->vectorPtr).get()+vecSize);
	}	

	//Overloaded []operator.Returns the value given index
	template<class T>
	const T& GTUVector<T>::operator[](int index){
		for(auto i=begin(); i<end(); i++ )
			if(vectorPtr.get()[i]==index)
				return vectorPtr.get()[i];
	}			

}//end of namespace