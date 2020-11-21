#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "opponent.h"

using namespace std;

// this method generate a random number within the given number range and compare it with the magic number. If they are the same, it tells the player that he/she wins. Else, it shows the random number generated and the new number range.
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
