#include <iostream>
#include "bingo.h"
#include "tictactoe.h"
#include "rockpaperscissors.h"
#include <string>
using namespace std;

void playMatrix()
{
	cout << " ************************************************************************************************************************"<<endl;
	cout << " ************************************************************************************************************************" << endl;
	cout << " **  * *   *         * * * *   *         *      *        *   * * * *   * * * * *  *  *      * * * * *   *          *   **" << endl;
	cout << " **  *  *  *         *     *     *     *        *  *   * *   *     *       *      *    *        *         *       *    **" << endl;
	cout << " **  *  *  *         *     *       * *          *    *   *   *     *       *      *   *         *           *   *      **" << endl;
	cout << " **  * *   *         * * * *        *      ===  *        *   * * * *       *      *  *          *             *        **" << endl;
	cout << " **  *     *         *     *        *           *        *   *     *       *      * *           *           *   *      **" << endl;
	cout << " **  *     *         *     *        *           *        *   *     *       *      *   *         *         *       *    **" << endl;
	cout << " **  *     * * * *   *     *        *           *        *   *     *       *      *     *   * * * * *   *           *  **" << endl;
   cout << " ************************************************************************************************************************"<<endl;
	cout << " ************************************************************************************************************************" << endl;

}
int main()
{
	playMatrix();
	int choice;
	int op = 0;

	do {
		cout << "\n====== GAME MENU ======\n";
		cout << "1. Bingo\n";
		cout << "2. Tic Tac Toe\n";
		cout << "3. Rock Paper Scissors\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Running Bingo Game...\n";
			cout << endl;
			int BingoArr[5][5];
			srand(time(0));
			

			do
			{
				op = Menu();

				if (op == 1)
				{
					Player_S p1;
					cout << "Enter your name: ";
					cin >> p1.Name;
					p1.Max_score = 0;
					BingoGen(p1.B_card);
					BingoGen(BingoArr);
					cout << endl;
					cout << "=============== >> The Bingo Card <<============== " << endl;
					printCard(BingoArr);
					cout << endl;
					cout << "=============== >> The Player's Card <<============== " << endl;
					printCard(p1.B_card);
					cout << endl;
					winCheck(p1 , BingoArr, p1.B_card);



				}
				else if (op == 2)
				{
					int Pl_size;
					cout << "Enter the number of players " << endl;
					cin >> Pl_size;
					Player_M* players = new Player_M[Pl_size];

					BingoGen(BingoArr);
					for (int i = 0; i < Pl_size; i++) {
						cout << "Enter player " << i + 1 << "'s name: ";
						cin >> players[i].Name;
						players[i].Max_score = 0;
						BingoGen(players[i].B_card);
					}
					cout << endl;
					cout << "=============== >> The Bingo Card <<============== " << endl;
					printCard(BingoArr);

					for (int i = 0; i < Pl_size; i++) {
						cout << endl;
						cout << "=============== >> The Player " << players[i].Name << " Card <<= ============ = " << endl;
						printCard(players[i].B_card);
					}
					winCheckMulti(players, Pl_size, BingoArr);

                    delete []players;
				}
				else if (op == 3)
                {
	               cout << "The highest score is: " << loadScore() << endl;
                }
                else if (op ==0)
	              cout << "!!!!! BYEeeeee BYE !!!!" << endl;
				  
				else 
				  cout<< "INVALID INPUT "<<endl;


			} while (op > 0);
			break;

		case 2:
			// Run Tic Tac Toe Game
			playTicTacToe(); // Function from tictactoe.cpp
			break;

		case 3:
			// Run Rock Paper Scissors Game
			// Add function call or game code here
			cout << "Running Rock Paper Scissors Game...\n";
			cout << endl;
			 
    do {
       

                srand(static_cast<unsigned int>(time(nullptr)));

                GameResult gameResult = { 0, 0 }; // Initialize scores

                while (true) {
                    cout << "Choose your move (0: Rock, 1: Paper, 2: Scissors, 3: Quit): ";
                    int userChoice;
                    cin >> userChoice;

                    if (userChoice < 0 || userChoice > 3) {
                        cout << "Invalid choice. Please enter a number between 0 and 3.\n";
                        continue;
                    }

                    if (userChoice == 3) {
                        cout << "Game over. Exiting...\n";
                        break;
                    }

                    int computerChoice = rand() % 3;

                    cout << "Your choice: " << getChoiceName(userChoice) << "\n";
                    cout << "Computer's choice: " << getChoiceName(computerChoice) << "\n";

                    int result = determineWinner(userChoice, computerChoice);
                    displayResult(result, gameResult);

                    saveResult(gameResult);
                }


            



    } while (op !=0);

			break;

		case 0:
			cout << "Exiting. Goodbye!\n";
			break;

		default:
			cout << "Invalid choice. Please enter a valid option.\n";
			break;
		}

	} while (choice != 0);

	return 0;
}
