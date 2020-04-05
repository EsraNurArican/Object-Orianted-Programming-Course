import java.lang.reflect.Array;
import java.lang.IllegalArgumentException;

/**
 * Class GTUVector is subclass of GTUContainer
 * Implements all abstract methods of GTUContainer or a vector class
 * @param <T> generic tupe parameter
 */
public class GTUVector<T> extends GTUContainer<T> {
    /**
     * vecArr array of type T to keep vectors elements
     */
    protected T[] vecArr;
    /**
     * size of vector
     */
    protected int size;
    /**
     * capacity of the vector
     */
    protected int cap;
    /**
     * current number of used elements in vector
     */
    private int used;
    /**
     * type parameter for type of the elements in the vector
     * to create generic array
     */
    protected Class<T[]> type;
    /**
     * one parameter constructor
     */
    public GTUVector(Class<T[]> classtype){
        this(0,classtype);
    }

    /**
     * constructor with size information
     * @param setSize indicate the new size of vector
     * @param classtype indicate the class type
     */
    public GTUVector(int setSize,Class<T[]> classtype){
        size = setSize;
        cap = setSize+5;
        vecArr = classtype.cast(Array.newInstance(classtype.getComponentType(),cap));
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
        return 10000;
    }

    /**
     * Inserts element to container
     *
     * @param element inserted
     */
    @Override
    void insert(T element) throws IllegalArgumentException {

        T[] temp = vecArr;
        //If vector is full,increase the capacity
        if(size==cap){
            cap+=size;
            vecArr=type.cast(Array.newInstance(type.getComponentType(),cap));
        }
        ++size;
        //Copying all elements to vecArr
        for(int i = 0; i<size-1; ++i)
            vecArr[i] = temp[i];

        //Adding element to vector
        vecArr[size - 1] = (T) element;

    }

    /**
     * Deletes an element from container
     *
     * @param element deleted
     */
    @Override
    void erase(Object element) {
        //creating temp array
        T []temp=type.cast(Array.newInstance(type.getComponentType(),size));

        //copying content
        for (int i = 0,j = 0; i < size; ++i) {
            if( ! element.equals(vecArr[i]) ) {
                temp[j] = vecArr[i];
                ++j;
            }
        }
        //decrease size
        --size;
        //copying elements
        System.arraycopy(temp, 0, vecArr, 0, size);

    }

    /**
     * Clear all content
     */
    @Override
    void clear() {
        size=0;
        vecArr=null;
    }

    /**
     * Returns iterator to beginning
     *
     * @return GTUIterator<T>
     */
    @Override
    GTUIterator iterator() {
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
            if(o==vecArr[i])
                return true;
        }
        return false;
    }

    /**
     * Returns the array which keeps data
     * @return T type
     */
    @Override
    T getArrayElement(int index) {
        return (T) vecArr[index];
    }
    /**
     * Prints the vector to screen,uses next(),hasNext() methods
     * @param iterator iterator variable
     */
    public void printVec(GTUIterator iterator){
        while(iterator.hasNext())
            System.out.printf(iterator.next()+" ");
        System.out.println();
    }

}
