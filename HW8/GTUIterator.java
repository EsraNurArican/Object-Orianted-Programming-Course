import java.lang.reflect.Array;

/**
 * Public generic ıterator class GTUIterator
 * @param <T> generic type
 */
public class GTUIterator<T> {
    /**
     * keeps position of the iterator
     */
    protected int position;
    /**
     * keeps size of the array
     */
    protected int sizeArr;
    /**
     *copies the data of container
     */
    private T[] itrArr;

    /**
     * Copies object's array to itrArr,initializes position to 0
     * @param object GTUContainer type object
     */
    public GTUIterator(GTUContainer <T> object,Class<T[]> classtype){
        position=0;
        sizeArr=object.size();
        itrArr=classtype.cast(Array.newInstance(classtype.getComponentType(),sizeArr));
        for(int i=0;i<object.size();i++) {
            itrArr[i]=  (T)object.getArrayElement(i);
        }
    }

    /**
     * Returns true if the iteration has more elements
     * @return boolean
     */
    public boolean hasNext(){
        return position<sizeArr;
    }

    /**
     * Returns the next element in the iteration
     * @return T generic type
     */
    public T next(){
        return itrArr[position++];
    }
}
