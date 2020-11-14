#include <iostream>
#include "max_finder.h"

using namespace std;

int main() {
	MaxFinderParameters params;
	cin >> params.upperBound;
	MaxFinder operation;
	maxFinderInit (operation, params);
	

	MaxFinderInputItem input;
	cin >> input.x;
	MaxFinderOutput output;
	MaxFinderOutput output1;
	maxFinderProcess(operation, input, output);

	
		for (unsigned i = 0; i < output.count; ++i) {
			cout << output.sequence[i].currentMax << " - " << output.sequence[i].amountMax << endl;
		}
	

	cin >> input.x;
	maxFinderProcess(operation, input, output1);
	
		for (unsigned i = 0; i < output1.count; ++i) {
			cout << output1.sequence[i].currentMax << " - " << output1.sequence[i].amountMax << endl;
		}
	



	while (true) {
		MaxFinderInputItem input;
		cin >> input.x;
		if (cin.eof()) {
			break;
		}
		MaxFinderOutput output;
		maxFinderProcess(operation, input, output);

		if (output.count > 0) {
			for (unsigned i = 0; i < output.count; ++i) {
				cout << output.sequence[i].currentMax << " - " << output.sequence[i].amountMax << endl;
			}
		}	else {
			cout << "No aswer just yet" << endl;
		}
	}
	maxFinderDestroy(operation);
	return 0;
}