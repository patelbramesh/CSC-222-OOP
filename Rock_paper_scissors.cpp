/* 
File Name: Rock_paper_scissorcs.cpp
Name: Bramesh Patel
Date: 09/24/2025

Description:
This program allows the user to play Rock, Paper, Scissors
against the computer in a tournament-style loop.
- User selects Rock, Paper, Scissors, Show Scoreboard, or Quit.
- Computer randomly chooses Rock, Paper, or Scissors.
- Each round has a winner or can end in a draw.
- Scores are tracked for User, Computer, and Draws.
- The scoreboard can be displayed anytime by selecting option 5.
- The tournament ends when the user selects Quit.

*/

#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

// Prompt user until valid choice
int getUserChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice:\n";
        cout << "1 = Rock\n2 = Paper\n3 = Scissors\n4 = Quit\n5 = Show Scoreboard\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) return choice;
        cout << "Invalid choice. Try again.\n";
    }
}

// Random computer choice (1–3)
int getComputerChoice() {
    return rand() % 3 + 1;
}

// Convert number to word
string choiceToString(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Quit";
    }
}

// Decide winner
string determineWinner(int user, int computer) {
    if (user == computer) return "Draw";
    if ((user == 1 && computer == 3) ||
        (user == 2 && computer == 1) ||
        (user == 3 && computer == 2)) {
        return "User";
    }
    return "Computer";
}

// Update scores
void updateScores(string winner, int &userScore, int &compScore, int &draws) {
    if (winner == "User") userScore++;
    else if (winner == "Computer") compScore++;
    else draws++;
}

// Show round results
void displayRoundResult(int userChoice, int compChoice, string winner, int userScore, int compScore, int draws) {
    cout << "You chose: " << choiceToString(userChoice) << endl;
    cout << "Computer chose: " << choiceToString(compChoice) << endl;

    if (winner == "Draw") cout << "It's a draw!\n";
    else cout << winner << " wins this round!\n";

    cout << "Score -> You: " << userScore
         << " | Computer: " << compScore
         << " | Draws: " << draws << "\n\n";
}

// Show scoreboard anytime
void displayScoreboard(int userScore, int compScore, int draws) {
    cout << "\n=== Scoreboard ===\n";
    cout << "You: " << userScore << endl;
    cout << "Computer: " << compScore << endl;
    cout << "Draws: " << draws << endl;
    cout << "==================\n\n";
}

// Final result
void displayFinalResult(int userScore, int compScore, int draws) {
    cout << "\n=== Tournament Over ===\n";
    cout << "Final Score -> You: " << userScore
         << " | Computer: " << compScore
         << " | Draws: " << draws << endl;

    if (userScore > compScore) cout << "You win the tournament!\n";
    else if (compScore > userScore) cout << "Computer wins the tournament!\n";
    else cout << "Tournament ends in a draw!\n";
}

// Main Function 
int main() {
    int userScore = 0, compScore = 0, draws = 0;

    srand(time(0)); // seed random generator

    cout << "=== Rock, Paper, Scissors Tournament ===\n";

    while (true) {
        int userChoice = getUserChoice();

        if (userChoice == 4) { // Quit
            displayFinalResult(userScore, compScore, draws);
            break;
        } 
        else if (userChoice == 5) { // Show scoreboard
            displayScoreboard(userScore, compScore, draws);
            continue;
        }

        // Otherwise play a round
        int compChoice = getComputerChoice();
        string winner = determineWinner(userChoice, compChoice);
        updateScores(winner, userScore, compScore, draws);
        displayRoundResult(userChoice, compChoice, winner, userScore, compScore, draws);
    }

    return 0;
}