#include "bingo.h"
#include <iostream>
#include <time.h> 
#include <windows.h>

using namespace std;


int Menu()
{
	int op;
	cout << endl;
	cout << "!!!!!   WELCOME TO BINGOOOOO      !!!!!!" << endl;
	cout << endl;
	cout << "SELECT THE PALYING MODE " << endl;
	cout << "[1] Single Player " << endl;
	cout << "[2] Multiple Players " << endl;
	cout << "[3] Highest Score " << endl;
	cout << "[0] EXIT " << endl;
	cin >> op;

	return op;
}

void BingoGen(int arr[5][5]) {
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			int min = j * 15 + 1;
			int max = min + 14;
			bool duplicate;
			do {
				duplicate = false;
				arr[i][j] = rand() % (max - min + 1) + min;
				// Check for duplicates
				for (int k = 0; k < i; k++) {
					if (arr[k][j] == arr[i][j]) {
						duplicate = true;
						break;
					}
				}
			} while (duplicate);
		}
	}
}

void printCard(int arr[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << arr[i][j] << "\t"; Sleep(500);
		cout << endl;
	}
}

int fcheck = 0;

void winCheck(Player_S& p1, int arr[5][5], int arr2[5][5])
{
	
	for (int i = 0; i < 5; i++)
	{
		int Ch = 0;
		for (int j = 0; j < 5; j++)
		{
			if (arr[i][j] == arr2[i][j])
			{
				Ch++;
			}
		}
		if (Ch == 5)
		{
			cout << "Congratulations!!! You got BINGO on row " << i << endl;
			fcheck++;
		}
		else
		{
			cout << "LOL!!! You got NOOOOO BINGO on row " << i << endl;
		}
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		int Ch = 0;
		for (int j = 0; j < 5; j++)
		{
			if (arr[j][i] == arr2[j][i])
			{
				Ch++;
			}
		}
		if (Ch == 5)
		{
			cout << "Congratulations!!! You got BINGO on column " << i << endl;
			fcheck++;
		}
		else
		{
			cout << "LOL!!! You got NOOOOO BINGO on column " << i << endl;
		}
	}

	cout << endl;

	int Ch1 = 0, Ch2 = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i][i] == arr2[i][i])
		{
			Ch1++;
		}
		if (arr[i][4 - i] == arr2[i][4 - i])
		{
			Ch2++;
		}
	}
	if (Ch1 == 5)
	{
		cout << "Congratulations!!! You got BINGO on main diagonal" << endl;
		fcheck++;
	}
	else
	{
		cout << "LOL!!! You got NOOOOO BINGO on main diagonal" << endl;
	}
	if (Ch2 == 5)
	{
		cout << "Congratulations!!! You got BINGO on secondary diagonal" << endl;
		fcheck++;
	}
	else
	{
		cout << "LOL!!! You got NOOOOO BINGO on secondary diagonal" << endl;
	}

	cout << endl;
	if (fcheck == 0)
	{
		cout << "You didn't win this time. Better luck next time!" << endl;
	}
	else
	{
		if (fcheck > p1.Max_score)
		{
			p1.Max_score = fcheck;
			cout << "Congratulations!!! You achieved a new high score: " << p1.Max_score << endl;
			saveScore(p1.Max_score);
		}
	}
}

void winCheckMulti(Player_M* players, int Pl_size, int arr2[5][5])
{
	for (int p = 0; p < Pl_size; p++)
	{
		cout << "Checking player " << players[p].Name << endl;

		// Check rows
		for (int i = 0; i < 5; i++)
		{
			int static Ch = 0;
			for (int j = 0; j < 5; j++)
			{
				if (players[p].B_card[i][j] == arr2[i][j])
				{
					Ch++;
				}
			}
			if (Ch == 5)
			{
				cout << "Congratulations " << players[p].Name << "!!! You got BINGO on row " << i << endl;
			}
		}
		cout << "LoL!! you didn't Win in any row " << endl;

		// Check columns
		for (int i = 0; i < 5; i++)
		{
			int static Ch = 0;
			for (int j = 0; j < 5; j++)
			{
				if (players[p].B_card[j][i] == arr2[j][i])
				{
					Ch++;
				}
			}
			if (Ch == 5)
			{
				cout << "Congratulations " << players[p].Name << "!!! You got BINGO on column " << i << endl;
			}
		}
		cout << "LoL!! you didn't Win in any columns " << endl;

		// Check diagonals
		int static Ch1 = 0 ;
	    int static Ch2 = 0;
		for (int i = 0; i < 5; i++)
		{
			if (players[p].B_card[i][i] == arr2[i][i])
			{
				Ch1++;
			}
			if (players[p].B_card[i][4 - i] == arr2[i][4 - i])
			{
				Ch2++;
			}
		}
		if (Ch1 == 5)
		{
			cout << "Congratulations " << players[p].Name << "!!! You got BINGO on main diagonal" << endl;
		}
		if (Ch2 == 5)
		{
			cout << "Congratulations " << players[p].Name << "!!! You got BINGO on secondary diagonal" << endl;
		}
		cout << "LoL!! you didn't Win in any anything at all " << endl;
	}
}

void saveScore(int score)
{
	ofstream file;
	file.open("Score.txt");
	file << score;
	file.close();
}

int loadScore()
{
	ifstream file;
	file.open("Score.txt");
	int score;
	file >> score;
	file.close();
	return score;
}