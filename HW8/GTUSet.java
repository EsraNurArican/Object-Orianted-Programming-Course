import java.lang.reflect.Array;
import java.security.InvalidParameterException;

/**
 * Class GTUSet is subclass of GTUContainer
 * Implements all abstract methods of GTUContainer or a set class
 * @param <T> generic type parameter
 */
public class GTUSet<T> extends GTUContainer<T> {
    /**
     * setArr array of type T to keep sets elements
     */
    protected T[] setArr;
    /**
     * size of set
     */
    protected int size;
    /**
     * capacity of the set
     */
    protected int cap;
    /**
     * current number of used elements in set
     */
    private int used;
    /**
     * type parameter for type of the elements in the set
     * to create generic array
     */
    protected Class<T[]> type;
    /**
     * one parameter constructor
     */
    public GTUSet(Class<T[]> classtype){

        this(0,classtype);
    }
    /**
     * constructor with size information
     * @param setSize indicate the new size of set
     * @param classtype indicate the class type
     */
    public GTUSet(int setSize,Class<T[]> classtype){
        size = setSize;
        used=size-1;
        cap = setSize+5;
        setArr = classtype.cast(Array.newInstance(classtype.getComponentType(),cap));
        type = classtype;
    }

    /**
     * Test if container is empty or not
     *
     * @return true if container is empty
     */
    @Override
    boolean empty() {
        return size==0;
    }

    /**
     * @return container size
     */
    @Override
    int size() {
        return size;
    }

    /**
     * @return container's max size
     */
    @Override
    int max_size() {
        return 100000;
    }

    /**
     * Inserts element to container
     *
     * @param element inserted
     */
    @Override
    void insert(T element)throws InvalidParameterException {
        //Set can not have two same element,so if existing element tries to insert again,
        //throws an exception
        for(int i=0; i<size; ++i)
            if(setArr[i]==element)
                throw new InvalidParameterException("Exception while trying to insert:"+element +
                                                    " This element is already in the set!");

        T[] temp = setArr;

        //If set is full,increase the capacity
        if(size==cap){
            cap+=size;
            setArr=type.cast(Array.newInstance(type.getComponentType(),cap));
        }
        ++size;
        //Copying all elements to setArr
        for(int i = 0; i<size-1; ++i)
            setArr[i] = temp[i];

        //Adding element to set
        setArr[size - 1] = (T) element;
    }

    /**
     * Deletes an element from container
     *
     * @param element erased
     */
    @Override
    void erase(T element) {
        //creating temp array
        T []temp=type.cast(Array.newInstance(type.getComponentType(),size));
        //copying all content
        for (int i = 0,j = 0; i < size; ++i) {
            if( ! element.equals(setArr[i]) ) {
                temp[j] = setArr[i];
                ++j;
            }
        }
        //Decrease size
        --size;
        //copying array
        System.arraycopy(temp, 0, setArr, 0, size);
    }

    /**
     * Clear all content
     */
    @Override
    void clear() {
        size=0;
        setArr=null;
    }

    /**
     * Returns iterator to beginning
     *
     * @return GTUIterator<T>
     */
    @Override
    GTUIterator<T> iterator() {
        GTUIterator it= new GTUIterator(this,type);
        return it;
    }

    /**
     * Returns true if this collection contains specified element
     *
     * @param o an element
     * @return true if element is contained
     */
    @Override
    boolean contains(Object o) {
        for(int i=0;i<size;i++){
            if(o==setArr[i])
                return true;
        }
        return false;
    }

    /**
     * Returns the array which keeps data
     *
     * @return T type
     */
    @Override
    public T getArrayElement(int index) {
        return (T) setArr[index];
    }

    /**
     * Prints the set to screen
     * @param iterator iterator variable
     */
    public void printSet(GTUIterator iterator){
        while(iterator.hasNext())
            System.out.printf(iterator.next()+" ");
        System.out.println();
    }
}//end of the GTUSet class