import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * public class BoardArrayTest includes main method,isMovesValid method and testFunctions methods
 */
public class BoardArrayTest {
    /**
     * MAin method calls test methods and global method
     * @param args String argument
     * @throws FileNotFoundException if file not found
     */
    public static void main(String[] args) throws FileNotFoundException {


        /*This part is for testing the global isMovesValid function
         *I tested the function 3 times to show valid arrays and non-valid arrays work fine
         *Arrays of AbstractBoard created first
         *Objects created and made some moves on them
         *Objects assigned to arrays then called function */

        //Creating arrays of AbstractBoard to test the global function
        AbstractBoard[] array=new AbstractBoard[4];
        AbstractBoard[] array2=new AbstractBoard[5];
        AbstractBoard[] array3=new AbstractBoard[3];

        //Creating objects to assign to array's indexes
        BoardArray2D obje2d =new BoardArray2D(4);
        BoardArray2D obje2d2=new BoardArray2D(4,4);
        BoardArray1D obje1d=new BoardArray1D(4,4);
        BoardArray1D obje1d2=new BoardArray1D(4);

        //Random moves
        obje2d.shuffle();
        obje2d2.shuffle();
        obje1d.shuffle();
        obje1d2.shuffle();

        array[0]=obje2d;
        array[1]=obje2d2;
        array[2]=obje1d;
        array[3]=obje1d2;
        //Testing global function
        System.out.println("****Testing Global Function 1'st Time****");
        isMovesValid(array,4);
        //***************************************************************************
        //Creating objects to assign to array's indexes
        BoardArray2D obje2d_3 =new BoardArray2D(5);
        BoardArray2D obje2d_4=new BoardArray2D(5,5);
        BoardArray1D obje1d_3=new BoardArray1D(5,5);
        BoardArray1D obje1d_4=new BoardArray1D(5);
        BoardArray1D obje1d_5=new BoardArray1D(5,5);

        obje2d_3.reset();
        obje2d_3.move('L');
        obje2d_4.reset();
        obje2d_4.move('L');
        obje2d_4.move('U');
        obje1d_3.reset();
        obje1d_3.move('L');
        obje1d_3.move('U');
        obje1d_3.move('R');
        obje1d_4.reset();
        obje1d_4.move('L');
        obje1d_4.move('U');
        obje1d_4.move('R');
        obje1d_4.move('U');
        obje1d_5.reset();
        obje1d_5.move('L');
        obje1d_5.move('U');
        obje1d_5.move('R');
        obje1d_5.move('U');
        obje1d_5.move('L');

        array2[0]=obje1d_5;
        array2[1]=obje1d_4;
        array2[2]=obje1d_3;
        array2[3]=obje2d_4;
        array2[4]=obje2d_3;

        //Testing global function
        System.out.println("****Testing Global Function 2'nd Time****");
        isMovesValid(array2,5);
        //*************************************************
        BoardArray2D obje2d_5 =new BoardArray2D(3);
        BoardArray2D obje2d_6=new BoardArray2D(3,3);
        BoardArray1D obje1d_6=new BoardArray1D(3,3);

        obje2d_5.reset();
        obje2d_5.move('U');
        obje2d_5.move('L');
        obje2d_6.reset();
        obje2d_6.move('U');
        obje1d_6.reset();

        array3[0]=obje2d_5;
        array3[1]=obje2d_6;
        array3[2]=obje1d_6;

        //Testing global function
        System.out.println("****Testing Global Function 3'rd Time****");
        isMovesValid(array3,3);

        //Calling testMethod to show all methods work fine
        System.out.println("*****Testing methods******");
        testMethods(obje1d);

    }//end of main method

    /**
     * isMovesValid method is a global method to check given array contains of valid move sequences of boards
     * @param array of type AbstractBoard
     * @param sizeArray size of the array
     * @return true if array contains valid sequence of moves,otherwise returns false
     */
    public static boolean isMovesValid(AbstractBoard array[],int sizeArray){

        for(int i=0;i<sizeArray;i++){
            System.out.printf("Printing the board configuration at index:%d\n",i);
            System.out.println(array[i].toString());
        }
        int cllx=0,clly=0; // variables for holding the empty cell's index
        int cllxNext=0,cllyNext=0;
        int i=0;

        while(i<(sizeArray-1)){
            if((array[i].getColumn()!=array[i+1].getColumn()) || (array[i].getRow()!=array[i+1].getRow())){
                System.out.printf("Boards in array are not same size!");
                return false;
            }
            cllx=array[i].getEmptyCellX();
            clly=array[i].getEmptyCellY();
            cllxNext=array[i+1].getEmptyCellX();
            cllyNext=array[i+1].getEmptyCellY();

            //Controlling empty cell's move
            //If ıt goes u,d,r,l it looks other index until end of the array
            //else,it returns false because it means bb makes invalid move

            if((cllxNext==cllx-1 && cllyNext==clly) || (cllxNext==cllx+1 && cllyNext==clly) ||
                    (cllxNext==cllx && cllyNext==clly-1) || (cllxNext==cllx && cllyNext==clly+1)){
                i++;
            }
            else{
                System.out.printf("Non-valid movement at index:%d to %d!\n",i,i+1);
                return false;
            }
        }
        System.out.printf("Array contains valid sequence of moves!\n");
        return true;
    }//end of isMovesValid method

    /**
     * Tests every method for classes like move,setSize,reset,readFromFile,writeToFile,cell
     * @param object type AbstractBoard
     */
    public static void testMethods(AbstractBoard object){
        /*Calls derived classes every member function to show how they work*/

            int x,y,new_size,result;
            String filename,filename2;
            Scanner sc = new Scanner(System.in);
            Scanner sc2 = new Scanner(System.in);
            Scanner scw = new Scanner(System.in);

            System.out.println( "*****Reseting object:*****");
            object.reset();
            System.out.println(object.toString());
            System.out.println("*****Set size testing..*****");
            System.out.println("Enter new size:");
            new_size=sc.nextInt();
            System.out.printf("Setting size to size:%d\n",new_size);
            object.setSize(new_size,new_size);
            System.out.println(object.toString());
            System.out.println("*****Move tests*****");
            System.out.printf("Move U:\n");
            result=object.move('U');
            if(result==-1)
                System.out.printf("There is no room.\n");
            System.out.println(object.toString());
            System.out.printf("Move R:\n");
            result=object.move('R');
            if(result==-1)
                System.out.printf("There is no room.\n");
            System.out.println(object.toString());
            System.out.printf("Move D:\n");
            result=object.move('D');
            if(result==-1)
                System.out.printf("There is no room.\n");
            System.out.println(object.toString());
            System.out.printf("Move L:\n");
            result=object.move('L');
            if(result==-1)
                System.out.printf("There is no room.\n");
            System.out.println(object.toString());
            System.out.println("*****WriteToFile test*****");
            System.out.printf("Writing to file current board configuration\n");
            System.out.println("Enter a filename to write");
            filename = scw.nextLine();
            object.writeToFile(filename);
            System.out.printf("*****Is solved control******\n");
            object.isSolved();
            System.out.println("******Equals method test******");
            BoardArray1D testeq =new BoardArray1D(new_size);
            testeq.shuffle();
            System.out.println("Printing boards to send equal method");
            System.out.println(object.toString());
            System.out.println(testeq.toString());
            System.out.printf("Result of equals method is:%b\n",object.equals(testeq));
            System.out.printf("*****cell method control*****\n");
            System.out.printf("Enter 2 integer index values:");
            x=sc.nextInt();
            y=sc.nextInt();
            //bb = 100 as an integer not 0 because in files 0 means wall..
            System.out.printf("Index at row:%d column:%d is=%d\n",x,y,object.cell(x,y));

            System.out.printf("******Read from file control******\n");
            System.out.printf("Enter file name to read:");
            filename2 = sc2.nextLine();
            System.out.printf("Board after reading file:\n");
            object.readFromFile(filename2);
            System.out.println(object.toString());


        }//end of testMethods method
    }//end of BoardArrayTest class


