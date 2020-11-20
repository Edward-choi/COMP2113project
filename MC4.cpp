#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "mc4.h"
using namespace std;

int MC4()
{
    srand (time(NULL));
    char s1;
    char s2;
    char s3;
    int numWrong = 0;
    while(true){
        cout << "Oops, you have triggered a special event! Now you are going to answer three multiple choice questions. Answer at least two correctly to get the secret reward, or you will receive a random penalty!" << endl;
        cout << "Question 1: Which is the capital city of Australia?\nA  Canberra    B Sydney    C Melbourne    D Auckland" << endl;
        cout << "Your Choice: ";
        cin >> s1;
        if (s1=='A'||s1=='a') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is A." << endl;
            numWrong++;
        } 
        cout << "Question 2: Which is the fifth largest country in the world?\nA Australia    B India    C China    D Argentina    E None of the above" << endl;
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
