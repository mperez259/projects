//Math tutor program 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int choice;

    cout << "Multiplication(1) or Division(2): ";
    cin >> choice;

    while (choice == 1) {
        int num1 = rand() % (9 - 1 + 1) + 1;
        int num2 = rand() % (9 - 1 + 1) + 1;
        int result = num1 * num2;
        int answer;

        cout << num1 << " x " << num2 << " = ";
        cin >> answer;

        while (true) {
            if (answer != result) {
                cout << "Incorrect, try again: ";
                cin >> answer;
            } else {
                cout << "Correct.\n";
                break;
            }
        }
    }

    while (choice == 2) {
        int num1 = rand() % (9999 - 100 + 1) + 100;
        int num2 = rand() % (9 - 1 + 1) + 1;
        int result = num1 / num2;
        int remainder = num1 % num2;
        int rAnswer, answer;

        cout << num1 << " ÷ " << num2 << " = ";
        cin >> answer;

        while (true) {
            if (answer != result) {
                cout << "Incorrect, try again: ";
                cin >> answer;
            } else {
                cout << "Good, now the remainder: ";
                cin >> rAnswer;
            }

            if (answer == result && rAnswer != remainder) {
                cout << "Incorrect, try again: ";
                cin >> rAnswer;
            }

            if (rAnswer == remainder) {
                cout << "Both correct.\n";
                break;
            }
        }
    }

    return 0;
}
