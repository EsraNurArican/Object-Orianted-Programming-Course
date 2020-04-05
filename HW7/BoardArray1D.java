import java.io.*;
import java.security.SecureRandom;
import java.util.Scanner;

/**
 * Class BoardArray1D is a subclass of AbstractBoard class
 * Implements all methods of super class
 * Keeps board configuration at 1D array
 */
public class BoardArray1D extends AbstractBoard{

    private int[] board;
    private int row;
    private int column;

    public void setRow(int n_row){
        this.row=n_row;
    }
    public void setColumn(int n_column){
        this.column=n_column;
    }
    public int getRow(){
        return this.row;
    }
    public int getColumn(){
        return this.column;
    }

    /**
     * No parameter constructor
     */
    public BoardArray1D(){
        this.row=9;
        this.column=9;
        board = new int[row*column];
        for(int i=0;i<row*column;i++){
            board[i]=-1;
        }
        setNumOfBoard();
        setLastMove('S');
    }

    /**
     * Constructor that takes size information
     * @param size for square shape board
     */
    public BoardArray1D(int size){
        this.row=size;
        this.column=size;
        board = new int[size*size];
        for(int i=0;i<row*column;i++){
            board[i]=-1;
        }
        setNumOfBoard();
        setLastMove('S');
    }

    /**
     * Constructor that takes two parameters
     * @param n_row as row size
     * @param n_column as column size
     */
    public BoardArray1D(int n_row,int n_column){
        this.row=n_row;
        this.column=n_column;
        board = new int[n_column*n_row];
        for(int i=0;i<row*column;i++){
            board[i]=-1;
        }
        setNumOfBoard();
        setLastMove('S');
    }

    /**
     * toString method to print board configuration
     * @return String board configuration
     */
    @Override
    public String toString(){

        String result="";
        for (int m = 0; m < getRow(); m++){
            for (int k = 0; k < getColumn(); k++) {
                if(board[m*getColumn()+k]!=100)
                    result+= board[m * getColumn() + k] +" ";
                else if(board[m*getColumn()+k]==100)
                    result+= "bb ";
            }
            result+="\n";
        }
        return result;
    }

    /**
     * readFromFile reads file ans assigns the values to board array
     * @param filename as name of the file
     */
    @Override
    public void readFromFile(String filename){
        String[] readen =new String[100];
        try {
            int iRow=0;
            int jCol=0;
            int indexReaden=0;
            Scanner sc = new Scanner(new BufferedReader(new FileReader(filename)));
            //Reading line by line and parsing those lines
            while (sc.hasNextLine()) {
                String[] line = sc.nextLine().split(" ");
                for(int i=0;i<line.length;i++) {
                    jCol=line.length;
                    line[i] = line[i].trim();
                    readen[indexReaden]=line[i];
                    indexReaden++;
                }
               iRow++;
            }
            //Updating board arrays size according to the file
            setSize(iRow,jCol);
            //Assigning readen values to board array
            for(int i=0;i<getRow();i++){
                for(int j=0;j<getColumn();j++){
                    try {
                        //Converting string to integer
                        if (readen[i * getColumn() + j] != "bb")
                            board[i * getColumn() + j] = Integer.parseInt(readen[i * getColumn() + j]);
                    }
                    catch (NumberFormatException nfe){
                        board[i * getColumn() + j] = 100;
                    }
                }
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * writeToFile method to load board configuration
     * @param filename as name of the file
     */
    @Override
    public void writeToFile(String filename){
        try {
            FileOutputStream output = new FileOutputStream("output.txt");
            output.write(toString().getBytes());
            output.close();
        } catch (IOException e) {
            System.out.println("Error - " + e.toString());
        }
    }

    /**
     * reset method,resets board to the solution
     */
    @Override
    void reset() {
        int num=1;
        for(int i=0;i<getRow();i++){
            for(int j=0; j<getColumn();j++){

                if(i==getRow()-1 && j==getColumn()-1 && board[i*getColumn()+j]!=0){
                    board[i*getColumn()+j]=100;
                }
                else if(board[i*getColumn()+j]!=0){
                    board[i*getColumn()+j]=num;
                    num++;
                }
            }
        }
    }

    /**
     * setSize sets size,and resets the board
     * @param size1 as row
     * @param size2 as column
     */
    @Override
    void setSize(int size1, int size2) {
        setRow(size1);
        setColumn(size2);
        board = new int[size1*size2];
        for(int i=0;i<row*column;i++){
            board[i]=-1;
        }
        reset();
    }

    /**
     * move empty cell if there is a place
     * @param direction U R L D directions
     * @return 1 if move is done,0 if no place
     */
    @Override
    int move(char direction) {
        int emptCellX=-2;
        int emptCellY=-2;
        int num;

        for(int i=0; i<getRow(); i++){
            for(int j=0; j<getColumn(); j++){
                if(board[i*getColumn()+j]==100){
                    emptCellX=i;
                    emptCellY=j;
                }
            }
        }
        if (direction=='U'){

            if(emptCellX==0 || board[((emptCellX-1))*getColumn()+emptCellY]==0){
                return -1;
            }
            else if(emptCellX!=0 && board[((emptCellX-1))*getColumn()+emptCellY]!=0){
                num=board[((emptCellX-1))*getColumn()+emptCellY];
                board[(emptCellX-1)*getColumn()+emptCellY]=100;
                board[emptCellX*getColumn()+emptCellY]=num;
                setLastMove('U');
                setNumOfMove();
            }
            return 0;
        }
        else if(direction== 'D'){

            if(emptCellX==getRow()-1 || board[(emptCellX+1)*getColumn()+emptCellY]==0){
                return -1;
            }
            else if(emptCellX!=getRow()-1 && board[(emptCellX+1)*getColumn()+emptCellY]!=0){
                num=board[(emptCellX+1)*getColumn()+emptCellY];
                board[(emptCellX+1)*getColumn()+emptCellY]=100;
                board[emptCellX*getColumn()+emptCellY]=num;
                setLastMove('D');
                setNumOfMove();
            }
            return 0;
        }
        else if(direction=='R'){

            if(emptCellY==getColumn()-1 || board[emptCellX*getColumn()+(emptCellY+1)]==0){
                return -1;
            }

            else if(emptCellY!=getColumn()-1 && board[emptCellX*getColumn()+(emptCellY+1)]!=0){
                num=board[emptCellX*getColumn()+(emptCellY+1)];
                board[emptCellX*getColumn()+(emptCellY+1)]=100;
                board[emptCellX*getColumn()+emptCellY]=num;
                setLastMove('R');
                setNumOfMove();
            }
            return 0;
        }
        else if(direction=='L'){

            if(emptCellY==0 || board[emptCellX*getColumn()+(emptCellY-1)]==0){
                return -1;
            }

            else if(emptCellY!=0 && board[emptCellX*getColumn()+(emptCellY-1)]!=0){
                num=board[emptCellX*getColumn()+(emptCellY-1)];
                board[emptCellX*getColumn()+(emptCellY-1)]=100;
                board[emptCellX*getColumn()+emptCellY]=num;
                setLastMove('L');
                setNumOfMove();
            }
            return 0;
        }
        return 0;
    }

    /**
     * shuffle method,written to shuffle the board
     * @return int 0 if shuffle is done
     */
    public int shuffle(){

        /*First reset the board to the solution*/
        reset();
        //Initialize the random object
        SecureRandom random = new SecureRandom();

        int randomMove;
        int control=0;
        int i=0;
		/*This loop written for shuffle the board making ramdom moves size*size.
		But if there is an impossible move, i call random func. again to make sure
		the board is shuffled properly */
        while( i<getRow()*getColumn()){

            randomMove = random.nextInt(4) + 1;
            if(randomMove==1){
                control=move('U');
            }
            if(randomMove==2){
                control=move('D');
            }
            if(randomMove==3){
                control=move('L');
            }
            if(randomMove==4){
                control=move('R');
            }
		/*Control is the return value for U,D,R,L functions
		If control is -1 this means there is no room for that choice
		If control is 0 this means cell is moved and size*size number increases*/
            if(control==0)
                i++;
        }
        return 0;
    }

    /**
     * isSolved method to check if board is solution
     * @return true if board is solution,else false
     */
    @Override
    boolean isSolved() {
        BoardArray1D controlObje= new BoardArray1D (row,column);
        controlObje.reset();

        int count=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(board[i*column+j]==controlObje.cell(i,j)){
                    count++;
                }
                else if(board[i*column+j]!=controlObje.cell(i,j)){
                    System.out.println("Problem is not solved.\n");
                    return false;
                }
            }
        }
        if(count==row*column) {
            System.out.println("Problem is solved!\n");
            return true;
        }
        else
            return false;
    }

    /**
     * method cell gives the index in given coordinates
     * @param index1 as row
     * @param index2 as column
     * @return int cell content at given indexes
     */
    @Override
    int cell(int index1, int index2) {
        if(index1<0 || index1>this.row || index2<0 || index2>this.column) {
            System.out.println("Invalid index values!!");
            System.exit(0);
        }
        return board[index1*this.column+index2];
    }

    /**
     * Abstract method equals,if two objects are the same,boards are the same
     * @param other AbstractBoard object
     * @return true if objects are same,else return false
     */
    @Override
    boolean equals(AbstractBoard other) {
        if ((other == null))
            return false;
        // If the object is compared with itself then return true
        if (other == this) {
            return true;
        }
        //Check if other is an instance of BoardArray2D or not
        if (!(other instanceof BoardArray1D)) {
            return false;
        }
        // typecast other so that we can compare data members
        BoardArray1D control = (BoardArray1D) other;
        if ((control.getColumn() != getColumn()) || (control.getRow() != getRow()))
            return false;
        if ((control.getColumn() == getColumn()) && (control.getRow() == getRow())) {
            for (int i = 0; i < getRow(); i++) {
                for (int j = 0; j < getColumn(); j++) {
                    if (board[i * getColumn() + j] != control.cell(i, j))
                        return false;
                }
            }
            return true;
        }
        return false;
    }

    @Override
    /**
     * getEmptyCellX method for using in global test function
     * @return int emptycell's x index
     */
    public int getEmptyCellX(){
        for(int i=0; i<getRow();i++){
            for(int j=0;j<getColumn();j++){
                if(board[((i*getColumn())+j)]==100)
                    return i;
            }
        }
        return -1;
    }
    /**
     * getEmptyCellY method for using in global test function
     * @return int emptycell's y index
     */
    @Override
    //Returns the coordinates of empty cell
    public int getEmptyCellY(){
        for(int i=0; i<getRow();i++){
            for(int j=0;j<getColumn();j++){
                if(board[((i*getColumn())+j)]==100)
                    return j;
            }
        }
        return -1;
    }
}

