import java.lang.IllegalArgumentException;

/**
 * Container test class includes main method and testing methods
 */
public class ContainerTest {
    /**
     * Main method includes method calls to test containers
     * @param args string argument
     */
    public static void main(String[] args) {

        //Creating set and vector containers with different types
        GTUSet<Integer> intSet = new GTUSet(Integer[].class);
        GTUSet<String> stringSet = new GTUSet(String[].class);
        GTUSet<Character> charSet = new GTUSet(Character[].class);
        GTUVector<Integer> intVector = new GTUVector<Integer>(Integer[].class);
        GTUVector<Character> charVector = new GTUVector<Character>(Character[].class);
        GTUVector<String> stringVector = new GTUVector<String>(String[].class);
        /*----------------------------------------------------------*/
        System.out.println("******INTEGER SET TEST********");
        System.out.println("Inserting elements..");
        try{
            //Inserting elements to set
            intSet.insert(1);
            intSet.insert(2);
            intSet.insert(7);
            intSet.insert(9);
            intSet.insert(11);
            intSet.insert(4);
            intSet.insert(3);
            intSet.insert(4);
        }
        catch(IllegalArgumentException exception){
            System.out.println( exception.getMessage());
        }
        GTUIterator<Integer> intItr = new GTUIterator<Integer>(intSet,Integer[].class);
        intSet.printSet(intItr);
        System.out.println("Erasing some elements..");
        intSet.erase(7);
        intSet.erase(4);
        //Also iterator() method tested here..
        intSet.printSet(intSet.iterator());
        System.out.println("Current size of the set : "+intSet.size());
        System.out.println("Is set empty? "+intSet.empty());
        System.out.println("Is set contains 11 ? "+intSet.contains(11));
        System.out.println("Is set contains 5 ? "+intSet.contains(5));
        System.out.println("Clearing the set..");
        intSet.clear();
        System.out.println("Set size after clearing:"+ intSet.size());

        /*----------------------------------------------------------*/
        System.out.println("******STRING SET TEST********");
        System.out.println("Inserting elements..");
        try{
            //Inserting elements to set
            stringSet.insert("ESRA");
            stringSet.insert("CSE241");
            stringSet.insert("OOP");
            stringSet.insert("GTU");
            stringSet.insert("I_HOPE");
            stringSet.insert("I_GET");
            stringSet.insert("100_POINTS");
            stringSet.insert("FROM_THIS_HW");
        }
        catch(IllegalArgumentException exception){
            System.out.println( exception.getMessage());
        }
        GTUIterator<String> stringItr = new GTUIterator<String>(stringSet,String[].class);
        stringSet.printSet(stringItr);
        System.out.println("Erasing some elements..");
        stringSet.erase("OOP");
        stringSet.erase("GTU");
        //Also iterator() method tested here..
        intSet.printSet(stringSet.iterator());
        System.out.println("Current size of the set : "+stringSet.size());
        System.out.println("Is set empty? "+stringSet.empty());
        System.out.println("Is set contains GTU ? "+stringSet.contains("GTU"));
        System.out.println("Is set contains 100_POINTS ? "+stringSet.contains("100_POINTS"));
        System.out.println("Clearing the set..");
        stringSet.clear();
        System.out.println("Set size after clearing:"+ stringSet.size());

        /*----------------------------------------------------------*/
        System.out.println("******CHARACTER SET TEST********");
        System.out.println("Inserting elements..");
        try{
            //Inserting elements to set
            charSet.insert('A');
            charSet.insert('f');
            charSet.insert('u');
            charSet.insert('j');
            charSet.insert('h');
            charSet.insert('b');
            charSet.insert('e');
        }
        catch(IllegalArgumentException exception){
            System.out.println( exception.getMessage());
        }
        GTUIterator<Character> charItr = new GTUIterator<Character>(charSet,Character[].class);
        stringSet.printSet(charItr);
        System.out.println("Erasing some elements..");
        charSet.erase('j');
        charSet.erase('u');
        //Also iterator() method tested here..
        charSet.printSet(charSet.iterator());
        System.out.println("Current size of the set : "+charSet.size());
        System.out.println("Is set empty? "+charSet.empty());
        System.out.println("Is set contains A ? "+charSet.contains('A'));
        System.out.println("Is set contains h ? "+charSet.contains('h'));
        System.out.println("Clearing the set..");
        charSet.clear();
        System.out.println("Set size after clearing:"+ charSet.size());
        /*----------------------------------------------------------*/

        System.out.println("******INTEGER VECTOR TEST********");
        System.out.println("Inserting elements..");
        try{
            //Inserting elements to vector
            intVector.insert(1);
            intVector.insert(2);
            intVector.insert(7);
            intVector.insert(9);
            intVector.insert(11);
            intVector.insert(4);
            intVector.insert(3);
            intVector.insert(4);
        }
        catch(IllegalArgumentException exception){
            System.out.println( exception.getMessage());
        }
        GTUIterator<Integer> intItr2 = new GTUIterator<Integer>(intVector,Integer[].class);
        intVector.printVec(intItr2);
        System.out.println("Erasing some elements..");
        intVector.erase(7);
        intVector.erase(4);
        //Also iterator() method tested here..
        intVector.printVec(intVector.iterator());
        System.out.println("Current size of the vector : "+intVector.size());
        System.out.println("Is vector empty? "+intVector.empty());
        System.out.println("Is vector contains 11 ? "+intVector.contains(11));
        System.out.println("Is vector contains 5 ? "+intVector.contains(5));
        System.out.println("Clearing the vector..");
        intVector.clear();
        System.out.println("Set size after clearing:"+ intVector.size());
        /*----------------------------------------------------------*/

        System.out.println("******STRING VECTOR TEST********");
        System.out.println("Inserting elements..");
        try{
            //Inserting elements to vector
            stringVector.insert("HELLO");
            stringVector.insert("JAVA");
            stringVector.insert("PROGRAMMING");
            stringVector.insert("CONTAINER");
            stringVector.insert("TEST");
            stringVector.insert("METHOD");
            stringVector.insert("STRING");
            stringVector.insert("VECTOR");
            stringVector.insert("TEST");
        }
        catch(IllegalArgumentException exception){
            System.out.println( exception.getMessage());
        }
        GTUIterator<String> stringItr2 = new GTUIterator<String>(stringVector,String[].class);
        stringVector.printVec(stringItr2);
        System.out.println("Erasing some elements..");
        stringVector.erase("JAVA");
        stringVector.erase("METHOD");
        //Also iterator() method tested here..
        stringVector.printVec(stringVector.iterator());
        System.out.println("Current size of the vector : "+stringVector.size());
        System.out.println("Is vector empty? "+stringVector.empty());
        System.out.println("Is vector contains JAVA ? "+stringVector.contains("JAVA"));
        System.out.println("Is vector contains CONTAINER ? "+stringVector.contains("CONTAINER"));
        System.out.println("Clearing the vector..");
        stringVector.clear();
        System.out.println("Vector size after clearing:"+ stringVector.size());

        /*----------------------------------------------------------*/
        System.out.println("******CHARACTER VECTOR TEST********");
        System.out.println("Inserting elements..");
        try{
            //Inserting elements to vector
            charVector.insert('n');
            charVector.insert('f');
            charVector.insert('E');
            charVector.insert('b');
            charVector.insert('L');
            charVector.insert('b');
            charVector.insert('e');
        }
        catch(IllegalArgumentException exception){
            System.out.println( exception.getMessage());
        }
        GTUIterator<Character> charItr2 = new GTUIterator<Character>(charVector,Character[].class);
        charVector.printVec(charItr2);
        System.out.println("Erasing some elements..");
        charVector.erase('b');
        charVector.erase('e');
        charVector.erase('L');
        //Also iterator() method tested here..
        charVector.printVec(charVector.iterator());
        System.out.println("Current size of the vector : "+charVector.size());
        System.out.println("Is vector empty? "+charVector.empty());
        System.out.println("Is vector contains A ? "+charVector.contains('A'));
        System.out.println("Is vector contains E ? "+charVector.contains('E'));
        System.out.println("Clearing the vector..");
        charVector.clear();
        System.out.println("Set size after clearing:"+ charVector.size());
        /*----------------------------------------------------------*/
    }

}
