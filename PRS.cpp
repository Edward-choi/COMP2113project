#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int setWin = 0;
    int setLose = 0;
    srand (time(NULL));
    cout << "Oops, you have triggered a special event! Now you are going to play a best-of-3 Rock, Paper, Scissors. Win the game to get the secret reward, or you will receive a random penalty!" << endl;
    while (setWin < 2 && setLose < 2){
        int result = -100;
        int userInput = -100;
        string strResult;
        string userChoice;
        cout << "Input your choice (R/P/S): ";
        cin >> userChoice;
        result = rand()%3 + 1;
        if (result == 1) strResult = "R";
        if (result == 2) strResult = "P";
        if (result == 3) strResult = "S";
        if (userChoice == "R") userInput = 1;
        if (userChoice == "P") userInput = 2;
        if (userChoice == "S") userInput = 3;
        if (userChoice == strResult) {
            cout << "Opponent's choice: " << strResult << endl;
            cout << "It is a draw" << endl;
            cout << "Win: " << setWin << "   Lose: " << setLose << endl;
        }
        if (userInput == result + 1 || userInput == result - 2){ 
            setWin ++;
            cout << "Opponent's choice: " << strResult << endl;
            cout << "You win this set!" << endl;
            cout << "Win: " << setWin << "   Lose: " << setLose << endl;;
        }
        else if (userInput == result - 1 || userInput == result + 2){
            setLose ++;
            cout << "Opponent's choice: " << strResult << endl;
            cout << "You lose this set!" << endl;
            cout << "Win: " << setWin << "   Lose: " << setLose << endl;
        }
    }
    if (setWin == 2) cout << "Congratulations! You win the Game! You are rewarded an extra turn!" << endl;
    if (setLose == 2) cout << "（●´∧｀●） You lose the Game! As a penalty, your next turn is skipped. Better luck next time!" << endl;
}
