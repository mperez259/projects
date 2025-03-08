#include <iostream>
#include "Neuron.h"

using namespace std;

int main() {
    Neuron *n = new Neuron(0.9);

    cout << "val: " << n->getVal() << endl;
    cout << "activated val: " << n->getActivatedVal() << endl;
    cout << "derivative val: " << n->getDerivativeVal() << endl;

    return 0;
}

