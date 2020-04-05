/**
     * Abstract class AbstractBoard represents the board configuration
     * @author Esra Nur Arıcan
     * @version  1.0.0
     * @since 14.01.2020
     */
    public abstract class AbstractBoard {

        protected static int numOfMovesPerformed=0;
        protected static int numOfBoardsCreated=0;
        protected static char lastMovePerformed='S';

        /**
        * Abstract method toString
        * @return String board configuration
        */
        @Override public abstract String toString();
        /**
        * Abstract method readFromFile,reads given file and assigns the values to the board
        * @param filename as name of the file
        */
        abstract void readFromFile(String filename);
        /**
        * Abstract method writeToFile,loads current board coniguration to given file
        * @param filename as name of the file
        */
        abstract void writeToFile(String filename);
        /**
        * Abstract method resets board to the solution
        */
        abstract void reset();

        /**
        * Abstract method setSize,set the board size,after setting size resets the board
        * @param size1 as row
        * @param size2 as column
        */
        abstract void setSize(int size1,int size2);

        /**
        * Abstract method move,moves empty cell to given direction if it is possible
        * @param direction U R L D directions
        * @return 1 if move is done,0 if there is no place
        */
        abstract int move(char direction);

        /**
        *Abstract method isSolved checks if board is solution or not
        * @return true if solved,else false
        */
        abstract boolean isSolved();

        /**
        * Abstract method cell gives the index in given coordinates
        * @param index1 as row
        * @param index2 as column
        * @return int cell content at given indexes
        */
        abstract int cell(int index1,int index2);

        /**
        * Abstract method equals,if two objects are the same,boards are the same
        * @param other AbstractBoard object
        * @return true if objects are same,else return false
        */
        abstract boolean equals(AbstractBoard other);

        /**
        * getEmptyCellX method for using in global test function
        * @return int emptycell's x index
        */
        abstract int getEmptyCellX();
        /**
        * getEmptyCellY method for using in global test function
        * @return int emptycell's y index
        */
        abstract int getEmptyCellY();

        /**
        * Abstract method getColumn
        * @return int column value
        */
        abstract int getColumn();
        /**
        * Abstract method getRow
        * @return int row value
        */
        abstract int getRow();

        /**Static int method numOfMoves
         * @return returns the int number of moves performed
         * */
        public static int numOfMoves(){
            return numOfMovesPerformed;
        }

        /**Static int method numOfBoards
         * @return returns the number of boards created so far
         * */
        public static int numOfBoards(){
            return numOfBoardsCreated;
        }

        /**
         * Static char method lastMove
         * @return returns the last move, if there is no move returns 'S'*/
        public static char lastMove(){
            return lastMovePerformed;
        }
        /**
         * setNumOfMove increases number of moves by one*/
        public void setNumOfMove(){ numOfMovesPerformed++;}
        /**
         * setNumOfBoard increases number of board by one*/
        public void setNumOfBoard(){ numOfBoardsCreated++;}
        /**setLastMove sets the last move
         * @param  move for changing the last move*/
        public void setLastMove(char move) {lastMovePerformed=move;}
    }//end of class AbstractBoard


