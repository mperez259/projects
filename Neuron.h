#ifndef _NEURON_H_
#define _NEURON_H_

#include <iostream>

using namespace std;

class Neuron {
public:
	Neuron(double val);
	// Fast Sigmoid
	// f(x) = x / (1 + |x|)
	void activate();

	// Derivative of Fast Sigmoid
	// f'(x) = f(x) * (1 - f(x))
	void derivative();

	// Getters
	double getVal() { return this->val; }
	double getActivatedVal() { return this->activatedVal; }
	double getDerivativeVal() { return this->derrivativeVal; }



private:
	double val;
	double activatedVal;
	double derrivativeVal;


};

#endif