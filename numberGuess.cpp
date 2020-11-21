#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "numberGuess.h"
#include "opponent.h"
#include "user.h"
using namespace std;

//This method calls the User() and Opponent() method until the someone inputs the magic number. 
//If the player wins, it returns 0; Otherwise, 1 is returned.
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
        if (guess==target) {
            return 1;
        }
        Opponent(low, high, guess, target);
        if (guess==target) {
            return 0;
        }
    }
}
