import java.security.InvalidParameterException;

/**
 * Abstract generic class GTUContainer
 * @param <T> generic parameter type
 */
public abstract class GTUContainer<T> {
    /**
     * Test if container is empty or not
     * @return true if container is empty
     */
    abstract boolean empty();

    /**
     * @return container size
     */
    abstract int size();

    /**
     * @return container's max size
     */
    abstract int max_size();

    /**
     * Inserts element to container
     * @param element to insert
     */
    abstract void insert(T element)throws InvalidParameterException;

    /**
     * Deletes an element from container
     * @param element to erase
     */
    abstract void erase(T element);

    /**
     * Clear all content
     */
    abstract void clear();

    /**
     * Returns iterator to beginning
     * @return GTUIterator<T>
     */
    abstract GTUIterator<T> iterator();

    /**
     * Returns true if this collection contains specified element
     * @param o an element
     * @return true if element is contained
     */
    abstract boolean contains(Object o);

    /**
     *Returns the array which keeps data
     * @return T type
     * @param i index
     */
    abstract T getArrayElement(int i);

}//end of GTUContainer class
