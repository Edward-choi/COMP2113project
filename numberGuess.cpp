// Example program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "numberGuess.h"
#include "opponent.h"
#include "user.h"
using namespace std;

void Opponent(int &low, int &high, int &guess, int target)
{
    srand (time(NULL));
    int result = rand()%(high-low-1) + low + 1;
    if (result > target) {
        high = result;
        cout << "Opponent's guess: " << result << "\nRange: " << low << "-" << high << endl;
    }
    else if (result < target) {
        low = result;
        cout << "Opponent's guess: " << result << "\nRange: " << low << "-" << high << endl;
    }
    else if (result == target) {
        cout << "Opponent's guess: " << result << endl;
        cout << "BOOM! The magic number is " << target << ". You win!" << endl;
    }
    guess = result;
}

void User(int &low, int &high, int &guess, int target)
{
    cout << "Please pick a number from " << low << "-" << high << " exclusive: ";
    int userInput;
    cin >> userInput;
    while (low >= userInput || userInput >= high){
        cout << "Input out of range. Please pick a number from " << low << "-" << high << " exclusive: ";
        cin >> userInput;
    }
    if (low < userInput && userInput < high){
        if (userInput > target) {
            high = userInput;
            cout << "Your guess: " << userInput << "\nRange: " << low << "-" << high << endl;
        }
        else if (userInput < target) {
            low = userInput;
            cout << "Your guess: " << userInput << "\nRange: " << low << "-" << high << endl;
        }
        else if (userInput == target) {
            cout << "Your guess: " << userInput << endl;
            cout << "BOOM! The magic number is " << target << ". You lose!" << endl;
        }
    }
    guess = userInput;
}

int NumberGuess()
{
    srand (time(NULL));
    cout << "Oops, you have triggered a special event! Now you are going to play a number guessing game. Win the game to get the secret reward, or you will receive a random penalty!" << endl;
    cout << "Game Instruction: A random number from 1-100 inclusive is chosen as the magic number. You and your opponent take turns to pick a number from a given range exclusive. If the number picked is not equal to the magic number, the range will shrink accordingly. The player whose chosen number is equivalent to the magic number is considered as the loser. The initial range is 0-101.\nHere is an example:\nMagic number: 47  Number range: 0-101\nYour input: 50  Number range: 0-50\nOpponent's input: 35  Number range: 35-50\nYour input: 47\nYou lose." << endl; 
    int target = rand()%100 + 1;
    int guess = 0;
    int high = 101;
    int low = 0;
    while (true){
        User(low, high, guess, target);
        if (guess==target) break;
        Opponent(low, high, guess, target);
        if (guess==target) break;
    }
}
