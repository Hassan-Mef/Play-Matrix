#ifndef BINGO_H
#define BINGO_H
#include<iostream>
#include <fstream>
using namespace std;
#include<string>

struct Player_M
{
	string Name;
	int Max_score;
	int C_score;
	int B_card[5][5] = { 0 };
};

struct Player_S
{
	string Name;
	int Max_score;
	int C_score;
	int B_card[5][5] = { 0 };


};
// Function prototypes for Bingo game
void BingoGen(int arr[5][5]);
int Menu();
void printCard(int arr[5][5]);
void winCheck(Player_S& p1, int arr[5][5], int arr2[5][5]);
void winCheckMulti(Player_M* players, int Pl_size, int arr2[5][5]);
void saveScore(int score);
int loadScore();


// Add other declarations related to Bingo game

#endif // BINGO_H