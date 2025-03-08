#include <iostream>
#include <cmath>
#include "Neuron.h"

using namespace std;

// Constructor
Neuron::Neuron(double val) {
	this->val = val;
	activate();
	derivative();
}
// Fast Sigmoid
void Neuron::activate() {
	this->activatedVal = this->val / (1 + abs(this->val));
}

// Derivative of Fast Sigmoid
void Neuron::derivative() {
	this->derrivativeVal = this->activatedVal * (1 - this->activatedVal);
}

