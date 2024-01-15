#include "rockpaperscissors.h"
#include <iostream>
using namespace std;
#include<string>


const char* getChoiceName(int choice) {
    const char* choices[] = { "Rock", "Paper", "Scissors" };
    return choices[choice];
}

int determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return 0; // It's a draw
    } else if ((userChoice == 0 && computerChoice == 2) ||
               (userChoice == 1 && computerChoice == 0) ||
               (userChoice == 2 && computerChoice == 1)) {
        return 1; // User will win here
    } else {
        return -1; // Computer wins
    }
}

void displayResult(int result, GameResult& gameResult) {
    if (result == 0) {
        cout << "It's a draw!\n";
    } else if (result == 1) {
        cout << "You win!\n";
        gameResult.userScore++;
    } else {
        cout << "Computer wins!\n";
        gameResult.computerScore++;
    }
    cout << "Your Score: " << gameResult.userScore << "\tComputer Score: " << gameResult.computerScore << "\n";
}

void saveResult(const GameResult& gameResult) {
    ofstream outFile ("game_results.txt");
    if (outFile.is_open()) {
        outFile << "User Score: " << gameResult.userScore << "\tComputer Score: " << gameResult.computerScore << "\n";
        outFile.close();
        cout << "Result saved to file.\n";
    } else {
        cout << "Unable to open file for saving results.\n";
    }
}