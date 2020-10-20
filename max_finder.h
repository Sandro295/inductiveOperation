#ifndef MAX_FINDER_H_
#define MAX_FINDER_H_

struct MaxFinderInputItem {
	double x;
};

struct MaxFinderOutputItem {
	double y;
};

struct MaxFinderOutput {
	double currentMax;
	unsigned int amountMax;
	bool exists;
};

struct MaxFinderParameters {
	double upperBound;
};

struct MaxFinderExtension {
};

struct MaxFinder {
	MaxFinderOutput output;
	MaxFinderParameters params;
	MaxFinderExtension extension;
};

void maxFinderInit(MaxFinder& instance, const MaxFinderParameters& params);
void maxFinderDestroy(MaxFinder& instance);
void maxFinderProcess(MaxFinder& instance, MaxFinderInputItem& input,
	MaxFinderOutput& output);

#endif