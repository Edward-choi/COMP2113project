#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "mc3.h"
using namespace std;

//this method asks the player 3 questions and store the answers. If the player answers at least two questions correctly, it returns 0. Else, it returns 1.
int MC3()
{
    srand (time(NULL));
    char s1;
    char s2;
    char s3;
    int numWrong = 0;
    while(true){
        cout << "Oops, you have triggered a special event! Now you are going to answer three multiple choice questions. Answer at least two correctly to get the secret reward, or you will receive a random penalty!" << endl;
        cout << "Question 1: Which London Tube station is between Canning Town station and Canary Wharf station?\nA East Greenwich    B North Greenwich    C West Greenwich    D South Greenwich" << endl;
        cout << "Your Choice: ";
        cin >> s1;
        if (s1=='B'||s1=='b') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is B." << endl;
            numWrong++;
        } 
        cout << "Question 2: What is the 177th digit of π?\nA 1    B 2    C 3    D 4    E 5" << endl;
        cout << "Your Choice: ";
        cin >> s2;
        if (s2=='E'||s2=='e') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is E." << endl;
            numWrong++;
        } 
        if (numWrong==2) {
            cout << "You have got two answers wrong. Better luck next time!" << endl;
            break;
        }
        cout << "Question 3: Guess what number I'm thinking of.\nA 64    B e    C -810    D √2 " << endl;
        cout << "Your Choice: ";
        cin >> s3;
        if (s3=='C'||s3=='c') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is C." << endl;
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
