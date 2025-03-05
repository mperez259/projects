//Find signal to noise ratio
//Use series expansion for 'e'

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = 3.14159265358979323846;

int main() {
    cout << "optional 1" << endl;
    int j = 0;

    while (j < 2) {
        double k = 1.0;
        double e = 0.0;
        double SNR = 0.0;

        cout << "Enter e value: ";
        cin >> e;

        if (e == 1.6755) {
            SNR = (sqrt(k * pi / (4.0 - pi))) * ((pow(e, 2)) / 4.0 - (pow(e, 4)) / 64.0 + (pow(e, 6)) / 768.0);
        } else {
            SNR = sqrt(2.0 * k / (4.0 - pi)) * (e - sqrt(pi / 2.0) + 1 / (2.0 * e) + 1.0 / (8.0 * pow(e, 3)) + 3 / (16.0 * pow(e, 5)));
        }

        cout << fixed << setprecision(15) << "Voltage signal to noise ratio = " << SNR << endl << endl;
        j++;
    }

    cout << endl;
    cout << "optional 2" << endl;

    int x;
    double sum = 1;
    double fact = 1;

    cout << "Enter x power to raise e: ";
    cin >> x;

    for (int i = 1; i < 12; i++) {
        fact *= i;
        sum += pow(x, i) / fact;
    }

    cout << fixed << setprecision(11) << "e to the power of " << x << " = " << sum << endl;

    return 0;
}
