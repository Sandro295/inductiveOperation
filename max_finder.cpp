#include "max_finder.h"

void maxFinderInit(MaxFinder& instance, const MaxFinderParameters& params){
	instance.params = params;
	instance.output.amountMax = 0;
	instance.output.exists = false;
}

void maxFinderDestroy(MaxFinder & instance){
}

void maxFinderProcess(MaxFinder& instance, MaxFinderInputItem& input,
	MaxFinderOutput& output) {
	if (input.x < instance.params.upperBound) {
		if (!instance.output.exists) {
			output.currentMax = input.x;
			output.amountMax = 1;
			instance.output.exists = true;
			return;
		}
		if (input.x > output.currentMax) {
			output.currentMax = input.x;
			output.amountMax = 1;
			return; 
		}
		if (input.x == output.currentMax) {
			++output.amountMax;
			return;
		}
		if (input.x < output.currentMax) { return; }
		output.currentMax = input.x;
	} 
	return;
}
