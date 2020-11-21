#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
using namespace std;

struct RPS {
	int userNum;
	string userCh;
	int cpuNum;
	string cpuCh;
	RPS *next;
};

void appendRPS(RPS *&head, int userNum, string userCh, int cpuNum, string cpuCh) {
    RPS *new_rps = new RPS;  
    RPS *last = head;
    new_rps->userNum = userNum; 
    new_rps->userCh = userCh;
    new_rps->cpuNum = cpuNum; 
    new_rps->cpuCh = cpuCh;
    new_rps->next = NULL;
    if(head == NULL)
       head = new_rps;
    else{ 
        while(last->next!=NULL){
            last = last->next;
        }
        last->next = new_rps;
    }
}

void printRPS(RPS *&head, int &setWin, int &setLose) {
	RPS *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	if (current->userNum == current->cpuNum) {
            cout << "Opponent's choice: " << current->cpuCh << endl;
            cout << "It is a draw" << endl;
            cout << "Win: " << setWin << "   Lose: " << setLose << endl;
    }
    else if (current->userNum == current->cpuNum + 1 || current->userNum == current->cpuNum - 2){ 
        setWin ++;
        cout << "Opponent's choice: " << current->cpuCh << endl;
        cout << "You win this set!" << endl;
        cout << "Win: " << setWin << "   Lose: " << setLose << endl;;
    }
    else if (current->userNum == current->cpuNum - 1 || current->userNum == current->cpuNum + 2){
        setLose ++;
        cout << "Opponent's choice: " << current->cpuCh << endl;
        cout << "You lose this set!" << endl;
        cout << "Win: " << setWin << "   Lose: " << setLose << endl;
    }
}

int main()
{
    RPS *head = NULL;
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
        appendRPS(head, userInput, userChoice, result, strResult);
        printRPS(head, setWin, setLose);
    }
    if (setWin == 2) {
        cout << "Congratulations! You win the Game! You are rewarded an extra turn!" << endl;
        return 0;
    }
    if (setLose == 2) {
        cout << "（●´∧｀●） You lose the Game! As a penalty, your next turn is skipped. Better luck next time!" << endl;
        return 1;
    }

}
