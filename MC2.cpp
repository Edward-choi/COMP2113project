#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "mc2.h"
using namespace std;

//this method asks the player 3 questions and store the answers. If the player answers at least two questions correctly, it returns 0. Else, it returns 1.
int MC2()
{
    srand (time(NULL));
    char s1;
    char s2;
    char s3;
    int numWrong = 0;
    while(true){
        cout << "Oops, you have triggered a special event! Now you are going to answer three multiple choice questions. Answer at least two correctly to get the secret reward, or you will receive a random penalty!" << endl;
        cout << "Question 1: What is the capital of Mozambique?\nA Majuro    B Malabo    C Maputo    D Marino" << endl;
        cout << "Your Choice: ";
        cin >> s1;
        if (s1=='C'||s1=='c') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is C." << endl;
            numWrong++;
        } 
        cout << "Question 2: Which tennis player is not in the Big Four?\nA Novak Djokovic    B Andy Murray    C Rafael Nadal    D Roger Federer    E None of the above" << endl;
        cout << "Your Choice: ";
        cin >> s2;
        if (s2=='E'||s2=='e') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is A." << endl;
            numWrong++;
        } 
        if (numWrong==2) {
            cout << "You have got two answers wrong. Better luck next time!" << endl;
            break;
        }
        cout << "Question 3: Which manga was not published by Weekly Shōnen Jump?\nA Slam Dunk    B Attack on Titan    C Naruto    D To Love Ru    E None of the above" << endl;
        cout << "Your Choice: ";
        cin >> s3;
        if (s3=='B'||s3=='b') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is B." << endl;
            numWrong++;
        }
        if (numWrong==2) {
            cout << "You have got two answers wrong. Better luck next time!" << endl;
            return 1;
        }
        cout << "Congratulations! You pass the challenge!" << endl;
        return 0;
    }
}
