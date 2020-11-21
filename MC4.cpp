#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "mc4.h"
using namespace std;

//this method asks the player 3 questions and store the answers. If the player answers at least two questions correctly, it returns 0. Else, it returns 1.
int MC4()
{
    srand (time(NULL));
    char s1;
    char s2;
    char s3;
    int numWrong = 0;
    while(true){
        cout << "Oops, you have triggered a special event! Now you are going to answer three multiple choice questions. Answer at least two correctly to get the secret reward, or you will receive a random penalty!" << endl;
        cout << "Question 1: What is 2+2?\nA 4     B 69,420    C 177,013    D 114,514" << endl;
        cout << "Your Choice: ";
        cin >> s1;
        if (s1=='A'||s1=='a') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is A." << endl;
            numWrong++;
        } 
        cout << "Question 2: How do you spell UFO?\nA OFU    B ABC    C Ewe Eff Ohh    D 42    E None of the above" << endl;
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
        cout << "Question 3: Are the professors of COMP2113_ENGG1340 awesome?\nA Absolutely   B For sure    C I'm positive    D Hell yeah    E No" << endl;
        cout << "Your Choice: ";
        cin >> s3;
        if (s3 !='E'||s3 !='e') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! Come on" << endl;
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
