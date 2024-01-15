#ifndef TICTACTOE_H
#define TICTACTOE_H
#include<iostream>
#include <fstream>
using namespace std;
#include<string>

void drawGrid(char grid[3][3]);
bool checkWin(char grid[3][3]);
bool checkFull(char grid[3][3]);
void playTicTacToe();

#endif // TICTACTOE_H
