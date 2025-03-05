//Black Jack Console App 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int numCards = 10;

int deal();  // Function prototype

int main() {
    srand(time(0));  // Seed the random number generator

    while (true) {
        int playerSum[numCards];
        int dealerSum[numCards];
        int card1 = deal();
        int card2 = deal();
        int dealerCard1 = deal();
        int dealerCard2 = deal();
        bool stay = false;
        bool bust = false;

        playerSum[0] = card1 + card2;
        dealerSum[0] = dealerCard1 + dealerCard2;

        cout << "Player deal is " << card1 << " & " << card2 << endl;
        cout << "Dealer card is " << dealerCard1 << " and shows " << dealerCard1 + 10 << endl;

        while (stay == false) {
            int choice;
            cout << "Hit(1) or Stay(2)? ";
            cin >> choice;

            if (choice == 1) {
                int newCard = deal();
                playerSum[0] += newCard;
                cout << "Deal is " << newCard << ", new total: " << playerSum[0] << endl;

                if (playerSum[0] > 21) {
                    cout << "Bust. Better luck next time." << endl;
                    bust = true;
                    break;
                } else if (playerSum[0] == 21) {
                    stay = true;
                    cout << "Deal is " << playerSum[0] << endl;
                }
            } else {
                stay = true;
                break;
            }
        }

        cout << "Dealer's face-down card was: " << dealerCard2 << endl;

        while (!bust) {
            if (dealerSum[0] == playerSum[0]) {
                cout << "Push." << endl;
                break;
            }
            if (dealerSum[0] > 16) {
                if (dealerSum[0] > playerSum[0] && !bust) {
                    cout << "Dealer wins." << endl;
                    break;
                }
                if (dealerSum[0] < playerSum[0]) {
                    cout << "Player wins!" << endl;
                    break;
                }
            }

            cout << "Dealer total: " << dealerSum[0] << endl;
            while (dealerSum[0] < 17) {
                int newCard = deal();
                dealerSum[0] += newCard;
                cout << "Dealer draws " << newCard << endl;
                cout << "New total: " << dealerSum[0] << endl;
            }

            if (dealerSum[0] > 21) {
                cout << "Dealer busts, you win!" << endl;
                bust = true;
                break;
            }
        }
        cout << endl;
    }

    return 0;
}

// Function to generate a random card between 1 and 10
int deal() {
    return 1 + rand() % 10;
}
