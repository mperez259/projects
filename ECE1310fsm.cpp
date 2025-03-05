//Finite State Machine
//Vending Machine

#include <iostream>

using namespace std;

int main() {
    enum { ENTERMONEY, SELECTION, CHECKINV, RETURN };
    int state = ENTERMONEY;
    int amount = 0;
    int total = 0;
    int drinkCost = 25;
    int numDrink1 = 2;
    int numDrink2 = 4;
    int numDrinks = 4;
    int choice = 0;
    bool soldOut = false;

    while (true) {
        switch (state) {
            case ENTERMONEY:
                cout << "Enter money or (-1) for refund: ";
                cin >> total;
                if (total > 0) {
                    amount += total;
                    if (amount == drinkCost) {
                        state = SELECTION;
                    } else if (amount > drinkCost) {
                        cout << (amount - drinkCost) << " cents refunded\n";
                        amount = drinkCost;
                        state = SELECTION;
                    }
                } else {
                    state = RETURN;
                }
                break;

            case SELECTION:
                cout << "Select water(1), soda(2) or refund(-1): ";
                cin >> choice;
                if (choice == 1 || choice == 2) {
                    state = CHECKINV;
                } else {
                    state = RETURN;
                }
                break;

            case CHECKINV:
                if (numDrinks < 1) {
                    soldOut = true;
                    state = RETURN;
                } else if (choice == 1 && numDrink1 > 0) {
                    cout << "Dispensing water.\n";
                    numDrink1--;
                    numDrinks--;
                    amount = 0;
                    state = ENTERMONEY;
                } else if (choice == 2 && numDrink2 > 0) {
                    cout << "Dispensing soda.\n";
                    numDrink2--;
                    numDrinks--;
                    amount = 0;
                    state = ENTERMONEY;
                } else {
                    cout << (choice == 1 ? "Water sold out.\n" : "Soda sold out.\n");
                    state = SELECTION;
                }
                break;

            case RETURN:
                if (total == -1 || choice == -1) {
                    cout << amount << " cents refunded\n";
                    amount = 0;
                    state = ENTERMONEY;
                }
                if (soldOut) {
                    cout << "Sold out of everything.\n75 cents refunded\n";
                    amount = 0;
                    state = ENTERMONEY;
                }
                break;
        }
    }

    return 0;
}

