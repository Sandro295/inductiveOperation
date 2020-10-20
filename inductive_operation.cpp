#include <iostream>
#include "max_finder.h"


using namespace std;

int main() {
	MaxFinderParameters params;
	cin >> params.upperBound;
	MaxFinder operation;
	maxFinderInit (operation, params);

	while (true) {
		MaxFinderInputItem input;		
		cin >> input.x;
		if (cin.eof()) {
			break;
		}
		MaxFinderOutput output;
		maxFinderProcess(operation, input, output);
		if (operation.output.exists) {
			cout << output.currentMax << " - " << output.amountMax << endl;
		}
		else { cout << "No aswer just yet" << endl; }
	}
	maxFinderDestroy(operation);
	return 0;
}