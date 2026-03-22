import java.util.Scanner;

/**
 *Plays tic-tac-toe
 */
public class TicTacToe {

    private final String[][] board;
    static int ROWS = 3;
    static int COLUMNS = 3;
    static String player1 = "x";
    static String player2 = "o";

    public TicTacToe() {
        board = new String[ROWS][COLUMNS];
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLUMNS; j++)
                board[i][j] = " ";
    }

    /**
     * converts game table into a string
     * @return string version of tic-tac-toe table
     */
    public String toString() {
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < ROWS; i++) {
            r.append("|");
            for (int j = 0; j < COLUMNS; j++)
                r.append(board[i][j]);
            r.append("|\n");
        }
        return r.toString();
    }

    /**
     * set an empty cell to "x" or "o"
     * @param i first coordinate
     * @param j second coordinate
     * @param player either "x" or "o"
     */
    public void set(int i, int j, String player) {
        if (board[i][j].equals(" "))
            board[i][j] = player;
    }

    /**
     *
     * @return
     */
    public String getWinner() {
        int xCounter, oCounter;

        for (int i = 0; i < ROWS; i++) {
            xCounter = 0;
            oCounter = 0;
            for (int j = 0; j < COLUMNS; j++) {
                if(board[i][j].equals(player1))
                    xCounter++;
                else if (board[i][j].equals(player2))
                    oCounter++;
            }
            if (xCounter == ROWS) {
                return player1;
            }
            if (oCounter == ROWS) {
                return player2;
            }

            xCounter = 0;
            oCounter = 0;
            for (int j = 0; j < COLUMNS; j++) {
                if(board[j][i].equals(player1))
                    xCounter++;
                else if (board[j][i].equals(player2))
                    oCounter++;
            }
            if (xCounter == ROWS) {
                return player1;
            }
            if (oCounter == ROWS) {
                return player2;
            }
        }

        xCounter = 0;
        oCounter = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][ROWS - i - 1].equals(player1))
                xCounter++;
            else if (board[i][ROWS - i - 1].equals(player2))
                oCounter++;
            if (xCounter == ROWS) {
                return player1;
            }
            if (oCounter == ROWS) {
                return player2;
            }
        }
        xCounter = 0;
        oCounter = 0;
        for (int i = 0; i < ROWS; i++) {

            if (board[i][i].equals(player1))
                xCounter++;
            else if (board[i][i].equals(player2))
                oCounter++;

            if (xCounter == ROWS) {
                return player1;
            }
            if (oCounter == ROWS) {
                return player2;
            }
        }
        return "Nessun vincitore";
    }

    public static void main(String[] args) {
        String player = player1;
        TicTacToe game = new TicTacToe();
        Scanner in = new Scanner(System.in);
        int row, column;
        System.out.println(game);

        do {

            if (game.getWinner().equals(player1) || game.getWinner().equals(player2)) {
                System.out.println("Partita finita");
                System.exit(0);
            }

            System.out.println("Inserisci riga per " + player + " (-1 per uscire):");
            row = in.nextInt();

            if (row == -1) {
                System.out.println("Partita finita");
                System.exit(0);
            }

            System.out.println("Inserisci colonna per " + player + ":");
            column = in.nextInt();

            if (row >= ROWS || column >= COLUMNS) {
                System.out.println("Combinazione non valida");
            } else {
                // Set value on the board
                game.set(row, column, player);

                // Draw board
                System.out.println(game);

                // Get winnner
                System.out.println("Vince: " + game.getWinner());

                // Change player
                if (player.equals(player1)) {
                    player = player2;
                } else {
                    player = player1;
                }
            }

        } while (row < ROWS && column < COLUMNS);
    }
}