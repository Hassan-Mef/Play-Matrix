#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H
#include<iostream>
#include <fstream>
using namespace std;
#include<string>


// Struct to store game results
struct GameResult {
    int userScore;
    int computerScore;
};

// Function prototypes for Rock-Paper-Scissors game
const char* getChoiceName(int choice);
int determineWinner(int userChoice, int computerChoice);
void displayResult(int result, GameResult& gameResult);
void saveResult(const GameResult& gameResult);
int playRockPaperScissors();

#endif // ROCKPAPERSCISSORS_H
