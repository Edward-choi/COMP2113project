#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "mc3.h"
using namespace std;

int MC3()
{
    srand (time(NULL));
    char s1;
    char s2;
    char s3;
    int numWrong = 0;
    while(true){
        cout << "Oops, you have triggered a special event! Now you are going to answer three multiple choice questions. Answer at least two correctly to get the secret reward, or you will receive a random penalty!" << endl;
        cout << "Question 1: Who wrote the fiction Persy Jackson & the Olympians?\nA Arthur C. Clarke    B Rick Riordan    C H. G. Wells    D J.K. Rowling" << endl;
        cout << "Your Choice: ";
        cin >> s1;
        if (s1=='B'||s1=='b') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is B." << endl;
            numWrong++;
        } 
        cout << "Question 2: Which tennis player is not in the Big Four?\nA Novak Djokovic    B Andy Murray    C Rafael Nadal    D Roger Federer    E None of the above" << endl;
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
        cout << "Question 3: Which of the following is not a feature of C\nA Array    B Dynamic memory allocation    C Struct constructors    D  Pass by value function" << endl;
        cout << "Your Choice: ";
        cin >> s3;
        if (s3=='C'||s3=='c') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is C." << endl;
            numWrong++;
        }
        if (numWrong==2) {
            cout << "You have got two answers wrong. Better luck next time!" << endl;
            break;
        }
        cout << "Congratulations! You pass the challenge!" << endl;
        break;
    }
}
