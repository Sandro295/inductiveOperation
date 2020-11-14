#include "max_finder.h"

void maxFinderInit(MaxFinder& instance, const MaxFinderParameters& params){
	instance.params = params;
	instance.output.count = 0;
	instance.extension.exists = false;
}

void maxFinderDestroy(MaxFinder & instance){
}

void maxFinderProcess(MaxFinder& instance, MaxFinderInputItem& input,
	MaxFinderOutput& output) {

	if (input.x < instance.params.upperBound) {

		if (!instance.extension.exists) {
			output.count = 1;
			output.sequence[0].currentMax = input.x;
			output.sequence[0].amountMax = 1;
			instance.extension.exists = true;
			instance.output = output;
			return;
		}

		if (input.x > instance.output.sequence[0].currentMax) {
			output.count = 1;
			output.sequence[0].currentMax = input.x;
			output.sequence[0].amountMax = 1;
			
		}

		if (input.x == instance.output.sequence[0].currentMax) {
			output.count = 1;
			output.sequence[0].currentMax = instance.output.sequence[0].currentMax;
			output.sequence[0].amountMax = instance.output.sequence[0].amountMax + 1;
		}

		if (input.x < instance.output.sequence[0].currentMax) { 
		}

		instance.output = output;
	}
	else {
		if (!instance.extension.exists) {
			output.count = 0;
		}
		else {
			output.count = 1;
			output.sequence[0].currentMax = instance.output.sequence[0].currentMax;
			output.sequence[0].amountMax = instance.output.sequence[0].amountMax;
		}
	}
	return;
}