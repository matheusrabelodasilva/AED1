#include <stdio.h>
#include <stdbool.h>
#define SIZE 9
void printBoard(int (*board)[SIZE]);
bool isMoveValid(int (*board)[SIZE], int row, int col, int num);
bool isBoardFull(int (*board)[SIZE]);
void getAndProcessMove(int (*board)[SIZE], bool (*fixed_cells)[SIZE]);
bool isSolved(int (*board)[SIZE]);
int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    bool fixed_cells[SIZE][SIZE] = {
        {1, 1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 1}
    };
    printf("Bem-vindo ao Sudoku!\n");
    printf("Preencha as celulas vazias (0). Para sair, digite 0 0 0.\n\n");
    while (!isSolved(board)) {
        printBoard(board);
        getAndProcessMove(board, fixed_cells);
    }
    printf("\n\nParabens! Voce resolveu o Sudoku!\n\n");
    printBoard(board);
    
    return 0;
}
void printBoard(int (*board)[SIZE]) {
    printf("  -------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("  | ");
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("  -------------------------\n");
        }
    }
}
void getAndProcessMove(int (*board)[SIZE], bool (*fixed_cells)[SIZE]) {
    int row, col, num;
    printf("\nSua jogada (linha coluna numero): ");
    scanf("%d %d %d", &row, &col, &num);
    if (row == 0 && col == 0 && num == 0) {
        printf("Saindo do jogo. Ate mais!\n");
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                board[i][j] = -1;
            }
        }
        return;
    }
    if (row < 1 || row > SIZE || col < 1 || col > SIZE || num < 1 || num > SIZE) {
        printf("Entrada invalida. Por favor, use numeros de 1 a 9.\n");
        return;
    }
    row--;
    col--;
    if (fixed_cells[row][col]) {
        printf("Essa celula nao pode ser alterada. E um numero fixo.\n");
        return;
    }
    if (isMoveValid(board, row, col, num)) {
        board[row][col] = num;
        printf("Movimento realizado com sucesso.\n");
    } else {
        printf("Movimento invalido! Conflito na linha, coluna ou bloco.\n");
    }
}
bool isMoveValid(int (*board)[SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}
bool isBoardFull(int (*board)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
bool isSolved(int (*board)[SIZE]) {
    if (!isBoardFull(board)) {
        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int currentNum = board[i][j];
            if (currentNum != 0) {
                board[i][j] = 0;
                if (!isMoveValid(board, i, j, currentNum)) {
                    board[i][j] = currentNum;
                    return false;
                }
                board[i][j] = currentNum;
            }
        }
    }
    return true;
}
