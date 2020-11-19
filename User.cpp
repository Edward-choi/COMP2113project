// Example program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "user.h"

using namespace std;

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
