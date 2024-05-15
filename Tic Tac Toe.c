#include <stdio.h>
char board[3][3]; 
void initialize_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
void print_board() {
    printf("-------------\n");
    for(int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}
int check_win(char player) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) // Check rows
            return 1;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) // Check columns
            return 1;
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) // Check diagonal
        return 1;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) // Check other diagonal
        return 1;
    return 0;
}
int check_tie() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return 0; // There's an empty space, game not tied yet
        }
    }
    return 1; // All spaces filled, game is tied
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    
    initialize_board();
    
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n");
    
    while(1) {
        printf("\nCurrent board:\n");
        print_board();
        
        printf("Player %c, enter row and column (0-2) separated by space: ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        board[row][col] = currentPlayer;
        
        if(check_win(currentPlayer)) {
            printf("\nPlayer %c wins! Congratulations!\n", currentPlayer);
            print_board();
            break;
        }
        
        if(check_tie()) {
            printf("\nThe game is tied!\n");
            print_board();
            break;
        }
        
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}