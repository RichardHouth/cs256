//
// Created by Richard Houth on 5/9/18.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class dice {
    int value;
public:
    dice() {
        srand(time(NULL));
    }

    void toss() {
        value = rand() % 6 + 1;
    }

    int getValue() {
        return value;
    }
};

int main() {
    int playerScore = 0;
    int compScore = 0;
    int counter = 1;
    dice dice1 = dice();
    dice dice2 = dice();
    while (true) {
        playerScore = 0;
        compScore = 0;
        cout << "Round # " << counter++ << endl;
        while (playerScore <= 21 && compScore <= 21) {
            dice1.toss();
            dice2.toss();

            compScore += dice1.getValue() + dice2.getValue();

            dice1.toss();
            dice2.toss();

            playerScore += dice1.getValue() + dice2.getValue();
            if (playerScore > 21 || compScore > 21) {
                cout << "Score over 21, end round\n ";
                break;

            }
            cout << "Your score: " << playerScore << endl;
            cout << "Do you want to continue? (Y/N) : ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                break;
            }

        }
        cout << "Player score: " << playerScore << endl;
        cout << "Computer score: " << compScore << endl;
        if ((playerScore > 21 && compScore > 21) || (compScore == playerScore)) {
            cout << "No one wins." << endl;
        } else if (playerScore <= 21 && compScore > 21) {
            cout << "Player wins." << endl;
        } else if (playerScore > 21 && compScore <= 21) {
            cout << "Computer wins." << endl;
        } else if (playerScore > compScore) {
            cout << "Player wins." << endl;
        } else if (playerScore < compScore) {
            cout << "Computer wins." << endl;
        }
        char flag;
        cout << "Do you want to play another round? (Y/N): ";
        cin >> flag;
        if (flag == 'N' || flag == 'n') {
            cout << "End game" << endl;
            break;
        }
    }
}