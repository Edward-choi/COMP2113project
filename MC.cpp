#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand (time(NULL));
    char s1;
    char s2;
    char s3;
    int numWrong = 0;
    while(true){
        cout << "Oops, you have triggered a special event! Now you are going to answer three multiple choice questions. Answer at least two correctly to get the secret reward, or you will receive a random penalty!" << endl;
        cout << "Question 1: Which US president was not featured in the Mount Rushmore?\nA Franklin D. Roosevelt    B Thomas Jefferson    C Theodore Roosevelt    D Abraham Lincoln" << endl;
        cout << "Your Choice: ";
        cin >> s1;
        if (s1=='A') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is A." << endl;
            numWrong++;
        } 
        cout << "Question 2: When was The Univerisity of Hong Kong found?\nA 1874    B 1853    C 1881    D 1911" << endl;
        cout << "Your Choice: ";
        cin >> s2;
        if (s2=='D') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is D." << endl;
            numWrong++;
        } 
        if (numWrong==2) {
            cout << "You have got two answers wrong. Better luck next time!" << endl;
            break;
        }
        cout << "Question 3: Who is the first person to win two Nobel prizes in different fields?\nA Linus Carl Pauling    B Marie Skłodowska Curie    C John Bardeen    D Frederick Sanger" << endl;
        cout << "Your Choice: ";
        cin >> s3;
        if (s3=='B') cout << "You are correct! Well done!" << endl;
        else{
            cout << "Wrong Answer! The correct answer is B." << endl;
            numWrong++;
        }
        if (numWrong==2) {
            cout << "You have got two answers wrong. Better luck next time!" << endl;
            break;
        }
        cout << "Congratulations! You pass the challenge!" << endl;
    }
}
