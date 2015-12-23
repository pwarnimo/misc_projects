#include "mathfn.h"

void initCalculator() {
	currOperation = "+";
	currValue = 0;
	displayValue = 0;
}

void addToResult(float num) {
	currValue += num;
}
