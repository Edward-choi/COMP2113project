#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "opponent.h"

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
