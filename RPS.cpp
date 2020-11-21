#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "rps.h"
using namespace std;

//This method reads the player's input using a linked list and randomly picks one from rock, paper and scissors. The outputs are then compared until the the best-of-3 game ends. If the player wins, it returns 0; Otherwise, it returns 1.
int RPS() {
    struct RPS {
    	int userNum;
    	string userCh;
    	int cpuNum;
    	string cpuCh;
    	RPS *next;
    };
    RPS *head = NULL;
    int setWin = 0;
    int setLose = 0;
    srand (time(NULL));
    cout << "Oops, you have triggered a special event! Now you are going to play a best-of-3 Rock, Paper, Scissors. Win the game to get the secret reward, or you will receive a random penalty!" << endl;
    while (setWin < 2 && setLose < 2){
        int cpuNum = -100;
        int userNum = -100;
        string cpuCh;
        string userCh;
        cout << "Input your choice (R/P/S): ";
        cin >> userCh;
        cpuNum = rand()%3 + 1;
        if (cpuNum == 1) cpuCh = "R";
        if (cpuNum == 2) cpuCh = "P";
        if (cpuNum == 3) cpuCh = "S";
        if (userCh == "R") userNum = 1;
        if (userCh == "P") userNum = 2;
        if (userCh == "S") userNum = 3;
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
    if (setWin == 2) {
        cout << "Congratulations! You win the Game! You are rewarded an extra turn!" << endl;
        return 0;
    }
    if (setLose == 2) {
        cout << "（●´∧｀●） You lose the Game! As a penalty, your next turn is skipped. Better luck next time!" << endl;
        return 1;
    }
}
