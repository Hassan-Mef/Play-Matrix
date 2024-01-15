#include "tictactoe.h"
#include <iostream>

using namespace std;

void drawGrid(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|" << grid[i][j];
        }
        cout << "|\n";
    }
}

bool checkWin(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return true;
        if (grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
            return true;
    }
    if (grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return true;
    if (grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return true;
    return false;
}

bool checkFull(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void playTicTacToe() {
    char grid[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};

    char player = 'X';
    int move;

    while (true) {
        drawGrid(grid);
        cout << "Player " << player << ", enter your move: ";
        cin >> move;
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (grid[row][col] == ' ') {
                grid[row][col] = player;
                if (checkWin(grid)) {
                    drawGrid(grid);
                    cout << "\nCongratulations! Player " << player << " wins.\n";
                    break;
                }
                if (checkFull(grid)) {
                    drawGrid(grid);
                    cout << "\nIt's a draw.\n";
                    break;
                }
                if (player == 'X') {
                    player = 'O';
                } else {
                    player = 'X';
                }            
            } else {
                cout << "\nInvalid move. Try again.\n";
            }
        } else {
            cout << "\nInvalid move. Try again.\n";
        }
    }
}
